#include "PathFindingList.h"

void PathFindingList::addRoad(NodeRecord myRoad)
{
	roads.push_back(myRoad);
	length++;
}

void PathFindingList::addRoads(std::vector<NodeRecord> myRoads)
{
	for (int i = 0; i < myRoads.size(); i++)
	{
		roads.push_back(myRoads[i]);
	}
}

std::vector<NodeRecord> PathFindingList::getRoads(){ return roads; }

int PathFindingList::getLength() { return length; }

bool PathFindingList::removeRoad(NodeRecord myRoad)
{
	for (int i = 0; i < roads.size(); i++)
	{
		if (roads[i] == myRoad) {
			roads.erase(roads.begin() + i);
			length--;
			return true;
		}
	}
	return false;
}

bool PathFindingList::contains(NodeRecord myNode)
{
	for (int i = 0; i < length; i++)
	{
		if ((roads[i].myConnexion.getPrev() == myNode.myConnexion.getPrev()) || (roads[i].myConnexion.getNext() == myNode.myConnexion.getNext())) { return true; }
	}

	return false;
}

NodeRecord PathFindingList::find(NodeRecord myRoad)
{
	for (int i = 0; i < length; i++)
	{
		if (roads[i] == myRoad) { return roads[i]; }
	}

	NodeRecord eratum = NodeRecord();
	return eratum;
}

NodeRecord PathFindingList::smallestElmt()
{
	NodeRecord min, tmp;
	min = roads[0];
	for (int i = 0; i < length; i++)
	{
		tmp = roads[i];
		if (tmp.costSoFar < min.costSoFar)
		{
			min = tmp;
		}
	}

	return min;
}