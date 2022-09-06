#include "Graph.h"



Graph::Graph(const int nbR, const int nbN, std::vector<Connexion>& tab) : nbRelation(nbR), nbNode(nbN), table(tab) {}

Graph::~Graph(){}

std::vector<Connexion> Graph::getFromNode(NodeRecord node)
{
	std::vector<Connexion> nodeConnexions;

	for (int i = 0; i < nbRelation; i++)
	{
		if (table[i].getPrev() == node.myNode)
		{
			nodeConnexions.push_back(table[i]);
		}
	}
	return nodeConnexions;
}

std::vector<Connexion> Graph::getTable() { return table; }

Connexion Graph::find(Node myNode)
{
	for (int i = 0; i < static_cast<int>(table.size()); i++)
	{
		if (myNode == table[i].getPrev()) return table[i];
	}
}
int Graph::getNbR()
{
	return nbRelation;
}

int Graph::getNbN()
{
	return nbNode;
}