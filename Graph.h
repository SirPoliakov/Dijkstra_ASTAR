#pragma once
#include "Connexion.h"
#include <vector>


class Graph
{
private:
	const int nbRelation;
	const int  nbNode;
	std::vector<Connexion> table;
	
public:
	Graph(const int nbR, const int nbN, Connexion* tab);

	~Graph();
	std::vector<Connexion> getFromNode(Node myNode);
	std::vector<Connexion> getTable();

	int getNbR();
	int getNbN();
};