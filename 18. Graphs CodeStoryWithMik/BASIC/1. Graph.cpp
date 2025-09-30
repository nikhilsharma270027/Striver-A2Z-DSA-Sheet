// create graph using Hash Map
#include <iostream>
#include <unordered_map>
#include <vector>

// create the code now
// my code to create
unordered_map<int, vector<int>> adj;

for(vector<int>& vec : prerequisities) {
    int v = vec[1];
    adj[v].push_back(vec[0]);
}

    