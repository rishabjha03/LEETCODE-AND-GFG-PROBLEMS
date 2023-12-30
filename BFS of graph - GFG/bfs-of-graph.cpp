//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    vector<bool> visited(V, false); // To track visited nodes
    vector<int> bfsTraversal; // To store the BFS traversal result
    queue<int> q;

    visited[0] = true; // Marking the starting node 0 as visited
    q.push(0); // Enqueue the starting node

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        bfsTraversal.push_back(current);

        // Traverse the adjacent nodes of the current node
        for (int neighbor : adj[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true; // Mark the neighbor as visited
                q.push(neighbor); // Enqueue the neighbor for further traversal
            }
        }
    }

    return bfsTraversal; // Return the BFS traversal result
}

};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends