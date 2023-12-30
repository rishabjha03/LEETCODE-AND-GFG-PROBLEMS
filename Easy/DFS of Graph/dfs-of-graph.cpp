//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<bool> visited(V,false);
        vector<int> temp;
        
        for(int i=0;i<V;i++){
            if(visited[i] == false){
                dfsRec(adj,visited,i,temp);
            }
        }
        
        return temp;
        
        
    }
    
     void dfsRec(vector<int> adj[],vector<bool>& visited,int source,vector<int>& temp){
         
         visited[source] = true;
         temp.push_back(source);
         
         for(int x:adj[source]){
             if(visited[x] == false){
             dfsRec(adj,visited,x,temp);
             }
             
         }
         
     }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends