#include <iostream>
#include <list>

using namespace std;

//BFS
//1. Construct graph 
//2. BFS starting from a vetex

class Graph
{
    int V; //# of vertices
    list<int> *adj; // Adjacency list

public:
    Graph(int V); //Constructor
    void add_edge(int v, int w); //Function to construct a graph
    void bfs(int s);
};

//Initialize the graph object; V: # of vertices
Graph::Graph(int V)
{
    this -> V = V;
    adj = new list<int>[V];

}

//Direct and Indirect graph representation with adjacency lists
void Graph :: add_edge(int v, int w)
{
    adj[v].push_back(w); 
    //adj[w].push_back(v); // Indirect graph representation
}

void Graph :: bfs(int s)
{
    //Initialize the visited array as non-visited for all vertices
    //This can be improved using hash table
    bool *visited = new bool[V];
    for (int i = 0; i<V; i++)
    {
        visited[i] = false; 
    }

    //Using queue to record the current vetex's neighbours
    list<int> queue;

    //Mark s is visited and push it into queue
    visited[s] = true;
    queue.push_back(s);
    
    list<int>::iterator i;

    while (!queue.empty())
    {   
        
        int cur_node = queue.front();
        cout << cur_node << "; ";
        queue.pop_front();

        for (i = adj[cur_node].begin(); i != adj[cur_node].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }

    }
}


int main()
{   
    Graph g(5);
    g.add_edge(0,1);
    g.add_edge(4,0);
    g.add_edge(1,2);
    g.add_edge(1,3);
    g.add_edge(5,1);
    g.add_edge(2,4);
    g.add_edge(3,5);

    cout << "BFS starts from vertex 5:\n";
    g.bfs(5);
    cout << "\n\n\n";

    return 0;
}