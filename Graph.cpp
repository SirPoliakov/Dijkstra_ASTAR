#include "Graph.h"


Graph::Graph(const int nbR, const int nbN, Connexion* tab) : nbRelation(nbR), nbNode(nbN) {}

Graph::~Graph(){}

std::vector<Connexion> Graph::getFromNode(Node myNode)
{
	std::vector<Connexion> nodeConnexions;

	for (int i = 0; i < nbRelation; i++)
	{
		if (table[i].getPrev() == myNode)
		{
			nodeConnexions.push_back(table[i]);
		}
	}
	return nodeConnexions;
}

std::vector<Connexion> Graph::getTable() { return table; }

int Graph::getNbR()
{
	return nbRelation;
}

int Graph::getNbN()
{
	return nbNode;
}