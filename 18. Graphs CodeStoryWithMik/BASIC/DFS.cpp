#include<bits/stdc++.h>
using namespace std;

void dfs(int u, vector<bool>& visited, vector<vector<int>>& adj) {
    if (visited[u] == true)  {
        return; // if already visited
    }
    visited[u] = true; // if not mark as visited
    cout << "Visiting node: " << u << endl;

    for (int &v : adj[u]) {
        if (!visited[v]) {
            dfs(v, visited, adj);
        }
    }
}

int main() {
    int n = 5;  // Number of nodes
    vector<vector<int>> adj(n);

    // Example edges (undirected graph)
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0};
    adj[3] = {1};
    adj[4] = {1};

    vector<bool> visited(n, false);
    cout << "Starting DFS from node 0:" << endl;
    dfs(0, visited, adj);

    return 0;
}