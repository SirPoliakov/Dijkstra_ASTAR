#include <iostream>
#include "Connexion.h"
#include "Graph.h"
#include "PathFindingList.h"


struct Path
{
    std::string list;
    int pound = 0;
};


Path dijkstra(Graph myGraph, std::string start, std::string goal)
{

    //Initialize the record for the start Node
    NodeRecord startRecord = NodeRecord(myGraph.find(start));

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

                NodeRecord endNodeRecord = open.find(endNode);
                if (endNodeRecord.costSoFar <= endNodeCost) continue;
                else {
                    open.removeRoad(endNodeRecord);
                    endNodeRecord.myConnexion = connexion;
                    endNodeRecord.costSoFar = endNodeCost;
                    open.addRoad(endNodeRecord);
                }
            }

            //Otherwise we know we have an unvisited node, so make a record for it
            else {
                NodeRecord endNodeRecord = NodeRecord(endNode, connexion, endNodeCost);

                // And add it to the open list
                if (!open.contains(endNode)) open.addRoad(endNodeRecord);
            }
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
        Path path, finalPath; path.pound = 0;

        // Work back along the path, accumulating connections
        path.pound = current.costSoFar;
        while (current.myNode != start)
        {
            path.list += current.myNode;
            current = closed.find(current.myConnexion.getPrev());
        }
        

        // Reverse the path, and return it
         finalPath.list += start; finalPath.pound = path.pound;
         int s = static_cast <int>(path.list.size());
         for (int i = s-1; i>= 0; i--)
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

    const int nbRelations = 9; const int noeuds = 6;

    vector<Connexion> table;
    Connexion co1, co2, co3, co4, co5, co6, co7, co8, co9;
    co1 = Connexion("A", "B", 2);
    co2 = Connexion("A", "D", 4);
    co3 = Connexion("B", "C", 3);
    co4 = Connexion("B", "F", 13);
    co5 = Connexion("C", "E", 5);
    co6 = Connexion("D", "C", 3);
    co7 = Connexion("D", "F", 15);
    co8 = Connexion("E", "F", 3);
    co9 = Connexion("E", "B", 3);

    table.push_back(co1);
    table.push_back(co2);
    table.push_back(co3);
    table.push_back(co4);
    table.push_back(co5);
    table.push_back(co6);
    table.push_back(co7);
    table.push_back(co8);
    table.push_back(co9);
    
    Graph graphTest = Graph(nbRelations, noeuds, table);
    cout << "Graph créé!" << endl;
    
    //.......................................................................................................................................//




    //................................................VERIFICATION DE LA COMPLETION DU GRAPH.................................................//

    cout << " Notre graphe contient les relations suivante : " << endl;
    for (int i = 0; i < graphTest.getNbR(); i++)
    {
        cout << "Prev :  " << graphTest.getTable()[i].getPrev() << endl << "Next :  " << graphTest.getTable()[i].getNext() << endl << " Cost :  " << graphTest.getTable()[i].getCost() << endl;
    }

    //......................................................................................................................................//
    
    Path result = dijkstra(graphTest, "A", "F");
    cout << "Voici le chemin le plus cours :  " << endl;

    for (int i = 0; i < result.list.size()-1; i++)
    {
        cout << result.list[i] << " ; ";
    }
    cout << result.list[result.list.size()-1] << endl;
    cout << " poids total :  " << result.pound << endl;

    //......................................................................................................................................//


    cout << "Fin de Test." << endl;
    return 0;

    //..............................................................FIN....................................................................//
}
