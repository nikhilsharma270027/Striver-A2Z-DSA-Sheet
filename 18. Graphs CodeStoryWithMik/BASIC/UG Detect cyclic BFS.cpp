#include <bits/stdc++.h>
using namespace std;

// Cycle detection in Undirected Graph using BFS

// condition will be that
// it should not be  the parent of the node and also not be visited = false if true its cyclic

class Solution
{
public:
    bool iscyclicbfs(vector<vector<int>> adj, int u, vector<bool> &visited, int parent)
    {
        visited[u] = true;

        for (auto &v : adj[u])
        {
            if (v == parent)
                continue;
            if (visited[v])
            {
                return true;
            }
            if (iscyclicdfs(adj, v, visited, u))
            {
                return true;
            }
        }
        return false;
    }

    bool iscyclic(int n, vector<vector<int>> adj)
    {
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                if (iscyclicbfs(adj, i, visited, -1))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    Solution obj;
    int n = 5; // Number of nodes
    vector<vector<int>> adj(n);

    // Example edges (undirected graph)
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0};
    adj[3] = {1};
    adj[4] = {1}; 

    obj.iscyclic(n, adj);

    if (obj.iscyclic(n, adj))
    {
        cout << "The graph contains a cycle." << endl;
    }
    else
    {
        cout << "The graph does not contain a cycle." << endl;
    }

    return 0;
}