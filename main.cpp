#include <iostream>
#include "Connexion.h"
#include "Graph.h"
#include "PathFindingList.h"


struct Path
{
    std::string list;
    int pound;
};


Path dijkstra(Graph myGraph, std::string start, std::string end, std::string goal)
{

    //Initialize the record for the start Node
    NodeRecord startRecord = NodeRecord("start");

    //Initialize the open and closed list
    PathFindingList open = PathFindingList();
    open.addRoad(startRecord);
    PathFindingList closed = PathFindingList();
    NodeRecord current;

    //Iterate through processing each node
    while (open.getLength() > 0)
    {

        //Find the smallest element in the open list
        current = open.smallestElmt();
        
        //if it is the goal node, then terminate
        if (current.myNode == goal)  break;

        //Otherwise its outgoing connexion
        std::vector<Connexion> connexions = myGraph.getFromNode(current);

        NodeRecord endNodeRecord;

        //Loop through each connexion intern
        for (Connexion connexion : connexions)
        {

            //Get the cost estimate for the end node
            Node endNode = connexion.getNext();
            int endNodeCost = current.costSoFar + connexion.getCost();

            //Skip if the node is closed
            if (closed.contains(endNode)) continue;

            //...Or if it is open and we've found a worse route
            else if (open.contains(endNode))
            {
                //Here we find the record in the open list corresponding to the endNode
                endNodeRecord = open.find(endNode);
                if (endNodeRecord.costSoFar <= endNodeCost) continue;
            }

            //Otherwise we know we have an unvisited node, so make a record for it
            else
            {
                endNodeRecord = NodeRecord("endNode");
            }

            // We are here if we need to update the node
            // Update the cost and connection
            endNodeRecord.costSoFar = endNodeCost;
            endNodeRecord.myConnexion = connexion;

            // And add it to the open list
            if (!open.contains(endNode)) open.addRoad(endNodeRecord);
        }

        // We’ve finished looking at the connections for 
        // the current node, so add it to the closed list
        // and remove it from the open list.
        open.removeRoad(current);
        closed.addRoad(current);
    }

    // We’re here if we’ve either found the goal, or 
    // if we have no more nodes to search, find which.
    if (current.myNode != goal)
    {
        //We’ve run out of nodes without finding the goal, so there’s no solution
        Path NONE;
        NONE.list = "NONE"; NONE.pound = 0;
        return NONE;
    }
    else
    {
        // Compile the list of connections in the path
        Path path, finalPath;

        // Work back along the path, accumulating connections
        while (current.myNode != start)
        {
            path.list += current.myNode;
            path.pound += current.costSoFar;

            current = current.myConnexion.getPrev();
        }
        
        // Reverse the path, and return it
        finalPath.pound = path.pound;
        for (int i = path.list.size()-1; i>= 0; i--)
        {
            finalPath.list += path.list[i];
        }

        return finalPath;
    }
}

using namespace std;
int main()
{
    cout << "..................Test classes Graph et Connexions..................." << endl;



    //........................................................PREPARATION DU GRAPH.............................................................//

    const int relations = 6; const int noeuds = 5;

    Connexion tab[relations];
    Connexion co1, co2, co3, co4, 
    
    Graph graphTest = Graph(relations, noeuds, tab);
    cout << "Graph créé!" << endl;
    
    //.......................................................................................................................................//




    //................................................VERIFICATION DE LA COMPLETION DU GRAPH.................................................//

    cout << " Notre graphe contient les relations suivante : " << endl;
    for (int i = 0; i < graphTest.getNbR(); i++)
    {
        cout << "Prev :  " << graphTest.getTable()[i].getPrev() << endl << "Next :  " << graphTest.getTable()[i].getNext() << endl << " Cost :  " << graphTest.getTable()[i].getCost() << endl;
    }

    //......................................................................................................................................//
    
    Path result = dijkstra(graphTest, "A", "E", "E");
    cout << "Voici le chemin le plus cours :  " << endl;

    for (int i = 0; i < result.list.size()-1; i++)
    {
        cout << result.list[i] << " ; ";
    }
    cout << result.list[result.list.size()] << endl;
    cout << " poids total :  " << result.pound << endl;

    //......................................................................................................................................//


    cout << "Fin de Test." << endl;
    return 0;

    //..............................................................FIN....................................................................//
}
