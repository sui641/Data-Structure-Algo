#include <iostream>
#include <list>
#include <iterator>
#include <map>
#include <stdio.h>

using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    
public:
    Graph (int V);
    map<int,bool> visited; //construct hash map for each vertics
    // Construct graph, then traversal by dfs algorithm
    void add_edge(int v, int w);
    void dfs(int s);
};

Graph :: Graph(int V)
{
    this -> V = V;
    adj = new list<int>[V];
}

//Directed graph
void Graph :: add_edge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph :: dfs(int s)
{   
    visited[s] = true;
    cout << s << "; ";
    
    int cur_neighbour = adj[s].front();
    //cout << "current neighbour is " << cur_neighbour << "/n" ;

    list<int> :: iterator i;

    for (i = adj[s].begin(); i != adj[s].end(); ++i)
    {   
        if (!visited[*i])
        {
            dfs(*i);
        }
    }

}

int main()
{
    Graph g(6);

    g.add_edge(0,1);
    g.add_edge(4,0);
    g.add_edge(1,2);
    g.add_edge(1,3);
    g.add_edge(5,1);
    g.add_edge(2,4);
    g.add_edge(3,5);

    cout << "DFS starts from vertex 5:\n";
    //cout << adj[5];
    
    g.dfs(5);
    cout << "\n\n\n";

    return 0;
}

