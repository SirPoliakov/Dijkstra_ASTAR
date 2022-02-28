#pragma once
#include "Graph.h"
#include "Connexion.h"
#include <vector>

/*struct NodeRecord
{
	Node myNode;
	Connexion myConnexion;
	int costSoFar;

	NodeRecord(std::string mNode) : myNode(mNode), costSoFar(0) {}
	NodeRecord() : myNode(""), costSoFar(0){}
	bool operator==(NodeRecord other) { return (myNode == other.myNode) && (myConnexion == other.myConnexion) && (costSoFar == other.costSoFar); }
};*/

class PathFindingList
{
private:
	std::vector<Connexion> roads;
	int length;

public:
	PathFindingList() : length(0){}
	~PathFindingList(){}

	std::vector<Connexion> getRoads();
	int getLength();

	void addRoad(Connexion myRoad);
	void addRoads(std::vector<Connexion> myRoads);
	bool removeRoad(Connexion myRoad);
	Connexion smallestElmt();
	bool contains(Node myNode);
	int find(Connexion myNode);
	
};