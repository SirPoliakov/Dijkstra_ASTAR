#pragma once
#include "Connexion.h"
#include "PathFindingList.h"
#include <vector>


class Graph
{
private:
	const int nbRelation;
	const int  nbNode;
	std::vector<Connexion> table;
	
public:
	Graph(const int nbR, const int nbN, std::vector<Connexion>& tab);

	~Graph();
	std::vector<Connexion> getFromNode(NodeRecord myNode);
	std::vector<Connexion> getTable();
	Connexion find(Node myNode);

	int getNbR();
	int getNbN();
};