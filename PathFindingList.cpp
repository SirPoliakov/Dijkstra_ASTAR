#include "PathFindingList.h"

void PathFindingList::addRoad(NodeRecord myRoad)
{
	roads.push_back(myRoad);
	length++;
}

void PathFindingList::addRoads(std::vector<NodeRecord> myRoads)
{
	for (int i = 0; i < static_cast<int>(myRoads.size()); i++)
	{
		roads.push_back(myRoads[i]);
	}
}

std::vector<NodeRecord> PathFindingList::getRoads(){ return roads; }

int PathFindingList::getLength() { return length; }

bool PathFindingList::removeRoad(NodeRecord myRoad)
{
	for (int i = 0; i < static_cast<int>(roads.size()); i++)
	{
		if (roads[i] == myRoad) {
			roads.erase(roads.begin() + i);
			length--;
			return true;
		}
	}
	return false;
}

bool PathFindingList::contains(Node myNode)
{
	for (int i = 0; i < length; i++)
	{
		if (roads[i].myNode == myNode) { return true; }
	}

	return false;
}

NodeRecord PathFindingList::find(Node myRoad)
{
	for (int i = 0; i < length; i++)
	{
		if (roads[i].myNode == myRoad) { return roads[i]; }
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