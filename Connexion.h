#pragma once
#include <string>

using Node = std::string;

class Connexion 
{
private:
	Node prevNode;
	Node nextNode;
	int cost ;

public:
	Connexion(Node prev, Node next, int v) : prevNode(prev), nextNode(next), cost(v) {}
	Connexion();
	~Connexion(){}

	Node getPrev();
	Node getNext();
	int getCost();

	bool operator==(Connexion other)
	{
		return (prevNode == other.prevNode) && (nextNode == other.nextNode) && (cost == other.cost);
	}
};