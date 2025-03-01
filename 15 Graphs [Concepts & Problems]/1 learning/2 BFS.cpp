#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] = {0}; // created a visting 
        vis[0] = 1;
        std::queue<int> q;
        q.push(0);
        vector<int> BFS; // storing the result
        while(!q.empty()) { // Traversal until its empty
            // take the value of Q and pop it
            int node = q.front();
            q.pop();
            
            BFS.push_back(node);
            
            for(auto it: adj[node]) { 
                // Traversal over the adjlist to check if its visited 0
                // if its 1 it is visited
                if(!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        return BFS;
    }
}; 

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(vector<int> &ans) {
    for(int i = 0;i<ans.size();i++) {
        cout << ans[i] << " ";
    }
}


int main() {
    vector<int> adj[6];
    
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 0, 4);

    Solution obj;
    vector <int> ans = obj.bfsOfGraph(5, adj);
    printAns(ans);

    return 0;
}

// O/P : 0 1 2 3 4