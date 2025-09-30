#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void bfs(int u, vector<bool> &visited, unordered_map<int, vector<int>> &adj, vector<int> &result)
    {
        queue<int> que;

        que.push(u);
        visited[u] = true;
        result.push_back(u);

        while (!que.empty()) {
            int u = que.front();
            que.pop();

            for (int &v : adj[u])
            {
                if (!visited[v])
                {
                    que.push(v);
                    visited[v] = true;
                    result.push_back(v);
                }
            }
        }

    }

    vector<int> bfs(int v, vector<int> adj[])
    {
        unordered_map<int, vector<int>> adjMap;

        for (int i = 0; i < v; i++)
        {
            for (int j : adj[i])
            {
                adjMap[i].push_back(j);
            }
        }

        vector<bool> visited(v, false);
        vector<int> result;

        bfs(0, visited, adjMap, result);
        return result;
    }
};

int main()
{
    // main function
    Solution sol;
    vector<int> adj[5];
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0};
    adj[3] = {1};
    adj[4] = {1};

    vector<int> result = sol.bfs(5, adj);
    for (int node : result)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}