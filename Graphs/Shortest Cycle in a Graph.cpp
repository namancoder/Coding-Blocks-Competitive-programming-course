#include <bits/stdc++.h>
using namespace std;

const int N = 100005, M = 22;
vector<int> graph[N];

void bfs(int src, int n, int &ans)
{
    vector<int> dis(n + 1, INT_MAX);
    queue<int> Q;
    Q.push(src);
    dis[src] = 0;
    while (!Q.empty())
    {
        int cur = Q.front();
        Q.pop();
        for (auto x : graph[cur])
        {
            if (dis[x] == INT_MAX)
            {
                dis[x] = dis[cur] + 1;
                Q.push(x);
                //means neighbour is not visited
            }

            else if (dis[x] >= dis[cur])
            {
                ans = min(ans, dis[x] + dis[cur] + 1);
            }
        }
    }
}

void solve()
{

    int i, j, n, m, ans;
    ans = n + 1;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
    {
        bfs(i, n, ans);
    }

    if (ans == n + 1)
        cout << "No Cycle" << endl;
    else
    {
        cout << "length of shortest cycle is" << ans << endl;
    }
}

int main()
{
    solve();
    return 0;
}

//5 6 1 2 1 3 2 4 2 5 4 5 5 3