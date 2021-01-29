#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph
{
    int V;
    map<T, list<T>> adjList;

public:
    Graph(int v)
    {
        V = v;
    }

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

    bool isCyclicHelper(T node, map<T, bool> &visited, T parent)
    {
        visited[node] = true;
        for (T nbr : adjList[node])
        {
            if (!visited[nbr])
            {
                bool cycleDetected = isCyclicHelper(nbr, visited, node);
                if (cycleDetected)
                    return true;
            }
            else if (nbr != parent)
                return true;
        }
        return false;
    }

    bool isCyclicDFS()
    {
        map<T, bool> visited;
        for (auto i : adjList)
        {
            T node = i.first;
            if (!visited[node])
            {
                bool ans = isCyclicHelper(node, visited, node);
                if (ans == true)
                    return true;
            }
        }
        return false;
    }
};

int main()
{
    //Graph<int> g;

    Graph<int> g(4);
    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(4, 3);

    if (g.isCyclicDFS())
    {
        cout << "Cyclic Graph";
    }
    else
    {
        cout << "Non cyclic!";
    }

    return 0;
}