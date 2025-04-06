#include <iostream>
#include <list>
using namespace std;

struct Node
{
    int label;
    list<int> neighbours;
};

struct Graph
{
    // graph will have an array of type "Node" with length specified by n
    int n = 8;
    Node *nodes = new Node[n];
    void intializenodes()
    {
        // iterate through the nodes and assign labels
        for (int i = 0; i < n; i++)
        {
            nodes[i].label = i + 1;
        }
    }
    void addedge(int u, int v)
    {
        // Only add edge in one direction (u to v) for directed graph
        nodes[u-1].neighbours.push_back(v);
    }
    void print()
    {
        // Iterate through each node and print its neighbours
        for (int i = 0; i < n; i++)
        {
            cout << nodes[i].label << "-->";
            for (auto nd : nodes[i].neighbours)
            {
                cout << nd << " ";
            }
            cout << "\n";
        }
    }
};

int main()
{
    Graph *g = new Graph;
    g->intializenodes();
    
    // Add  edges from lower to higher numbered nodes
    
    g->addedge(1, 2);
    g->addedge(1, 3);
    g->addedge(1, 5);
    g->addedge(1, 4);
    g->addedge(2, 3);
    g->addedge(2, 6);
    g->addedge(4, 6);
    g->addedge(4, 7);
    g->addedge(4, 8);
    g->addedge(5, 6);
    g->addedge(5, 7);
    g->addedge(5, 8);
    
    // Print the graph
    g->print();
}