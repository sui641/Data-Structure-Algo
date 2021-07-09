#include <iostream>
#include <list>

using namespace std;

class Graph
{
    int V;
    list<int> *adj;

public:
    Graph(int V);
    void add_edge(int v, int w);
    void dfs(int s);
};

Graph :: Graph(int V)
{
    this -> V = V;
    adj = new list<int>[V];
}

void Graph :: add_edge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph :: dfs(int s)
{
    bool *visited = new bool[V];

    for (int i = 0; i<V; i++)
    {
        visited[i] = false;
    }

    list<int> :: iterator i;

    list<int> stack;
    stack.push_front(s);
    visited[s] = true;

    while (!stack.empty())
    {
        int cur_node = stack.front();
        cout << cur_node << "; ";
        stack.pop_front();

        for (i = adj[cur_node].begin(); i!= adj[cur_node].end(); ++i)
        {
            if (!visited[*i])
            {   
                visited[*i] = true;
                stack.push_front(*i);
            }
        
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