#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph
{

    map<T, list<T>> adjList;

public:
    Graph() {}

    void addEdge(T u, T v, bool bidir = true)
    {
        adjList[u].push_back(v);

        if (bidir)
        {
            adjList[v].push_back(u);
        }
    }

    void print()
    {

        //Iterate over the map

        for (auto i : adjList)
        {
            cout << i.first << " -> ";
            //i.second is List
            for (T entry : i.second)
            {
                cout << entry << ",";
            }
            cout << endl;
        }
    }

    void dfsHelper(T node, map<T, bool> &visited)
    {
        //mark node visited when we reach there

        visited[node] = true;
        cout << node << " ";

        for (T neighbour : adjList[node])
        {
            if (!visited[neighbour])
            {
                dfsHelper(neighbour, visited);
            }
        }
    }
    void dfsComp()
    {
        map<T, bool> visited;

        for (auto p : adjList)
        {
            visited[p.first] = false;
        }
        int count = 0;

        for (auto p : adjList)
        {
            T node = p.first;
            if (!visited[node])
            {
                cout << "COMPONENT::" << count << " -->";

                dfsHelper(node, visited);
                count++;
                cout << endl;
            }
        }
    }
};

int main()
{
    Graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(0, 3);
    g.addEdge(0, 4);
    g.addEdge(5, 6);
    g.addEdge(6, 7);
    g.addEdge(8, 8);
    g.dfsComp();
    return 0;
}