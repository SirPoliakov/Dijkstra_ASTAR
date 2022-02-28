#include "Connexion.h"


Connexion::Connexion(): prevNode(""), nextNode(""), cost(NULL) {}

Node Connexion::getPrev()
{
	return prevNode;
}

Node Connexion::getNext()
{
	return nextNode;
}

int Connexion::getCost()
{
	return cost;
}