#include <iostream>
#include "Connexion.h"
#include "Graph.h"
#include "PathFindingList.h"


struct Path
{
    std::string list;
    int pound;
};


Path dijkstra(Graph myGraph, std::string start, std::string end)
{
    Node current = start; 
    int costSoFar = 0;

    PathFindingList open = PathFindingList(); open.addRoads(myGraph.getTable());
    PathFindingList closed = PathFindingList();

    Path result; result.list = start; result.pound = 0;
    
    while (open.getLength() > 0)
    {
        std::vector<Connexion> connexions = myGraph.getFromNode(current); // Chemins possibles depuis le noeud

        Connexion min, tmp;
        min = connexions[0];
        for (int i = 0; i < connexions.size(); i++) //chemin le plus cours depuis le noeuds
        {
            tmp = connexions[i];
            if (tmp.getCost() < min.getCost())
            {
                min = tmp;
            }
        }
        current = min.getPrev(); 
        
        if (current == end) break; // Si on est arrivé STOP


        
    }


}

using namespace std;
int main()
{
    cout << "..................Test classes Graph et Connexions..................." << endl;



    //........................................................PREPARATION DU GRAPH.............................................................//

    const int relations = 7; const int noeuds = 5;

    Connexion tab[7];

    for (int i = 0; i < relations ; i++)
    {
        Node tmpPrevN, tmpNextN;
        int tmpCost;
        Connexion tmpConnexion;
        cout << "Entrez les relation... " << endl;
        cout << "Premier noeud : " << endl;
        cin >> tmpPrevN;
        cout << "Second noeud : " << endl;
        cin >> tmpNextN;
        cout << "Cout : " << endl;
        cin >> tmpCost;
        tmpConnexion = Connexion(tmpPrevN, tmpNextN, tmpCost);

        tab[i] = tmpConnexion;
        cout << "Releation suivante!" << endl;
    }

    cout << "tableau rempli!" << endl;
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


    cout << "Fin de Test." << endl;
    return 0;

    //..............................................................FIN....................................................................//
}
