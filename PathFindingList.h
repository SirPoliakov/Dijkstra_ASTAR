#pragma once
#include "Connexion.h"
#include <vector>

struct NodeRecord
{
	Node myNode;
	Connexion myConnexion;
	int costSoFar;

	NodeRecord(Connexion myCo) : myNode(myCo.getPrev()), myConnexion(myCo), costSoFar(0) {}
	NodeRecord() : myNode(""), costSoFar(0){}
	bool operator==(NodeRecord other) { return (myNode == other.myNode) && (myConnexion == other.myConnexion) && (costSoFar == other.costSoFar); }
};

class PathFindingList
{
private:
	std::vector<NodeRecord> roads;
	int length;

public:
	PathFindingList() : length(0){}
	~PathFindingList(){}

	std::vector<NodeRecord> getRoads();
	int getLength();

	void addRoad(NodeRecord myRoad);
	void addRoads(std::vector<NodeRecord> myRoads);
	bool removeRoad(NodeRecord myRoad);
	NodeRecord smallestElmt();
	bool contains(NodeRecord myNode);
	NodeRecord find(NodeRecord myNode);
	
};