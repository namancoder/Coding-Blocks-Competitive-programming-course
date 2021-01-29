#include <bits/stdc++.h>
using namespace std;

bool dfs_helper(vector<int> graph[], int node, int *visited, int parent, int color)
{
    visited[node] = color;
    for (auto nbr : graph[node])
    {
        if (visited[nbr] == 0)
        {
            bool subprob = dfs_helper(graph, nbr, visited, node, 3 - color);
            if (subprob == false)
                return false;
        }

        else if (nbr != parent and color == visited[nbr])
            return false;
    }
    return true;
}

bool dfs(vector<int> graph[], int N)
{
    int visited[N] = {0};

    int color = 1;
    int ans = dfs_helper(graph, 0, visited, -1, color);

    for (int i = 0; i < N; i++)
    {
        cout << i << " COLOR " << visited[i] << endl;
    }

    return ans;
}

int main()
{
    int N, M;

    cin >> N >> M;

    vector<int> graph[N];
    while (M--)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    if (dfs(graph, N))
        cout << "BP" << endl;
    else
        cout << "NOT BP" << endl;
    //Color nodes at each step

    return 0;
}