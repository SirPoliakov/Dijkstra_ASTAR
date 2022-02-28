#include "PathFindingList.h"

void PathFindingList::addRoad(Connexion myRoad)
{
	roads.push_back(myRoad);
	length++;
}

void PathFindingList::addRoads(std::vector<Connexion> myRoads)
{
	for (int i = 0; i < myRoads.size(); i++)
	{
		roads.push_back(myRoads[i]);
	}
}

std::vector<Connexion> PathFindingList::getRoads(){ return roads; }

int PathFindingList::getLength() { return length; }

bool PathFindingList::removeRoad(Connexion myRoad)
{
	int indice = find(myRoad);
	if (indice >= 0) {
		roads.erase(roads.begin() + indice);
		length--;
		return true;
	}
	else { return false; }
}

bool PathFindingList::contains(Node myNode)
{
	for (int i = 0; i < length; i++)
	{
		if ((roads[i].getPrev() == myNode) || (roads[i].getNext() == myNode)) { return true; }
	}

	return false;
}

int PathFindingList::find(Connexion myRoad)
{
	for (int i = 0; i < length; i++)
	{
		if (roads[i] == myRoad) { return i; }
	}

	return -1;
}

Connexion PathFindingList::smallestElmt()
{
	Connexion min, tmp;
	min = roads[0];
	for (int i = 0; i < length; i++)
	{
		tmp = roads[i];
		if (tmp.getCost() < min.getCost())
		{
			min = tmp;
		}
	}

	return min;
}