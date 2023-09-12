// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  
    bool cycleDFS(int curr,int pre, vector <bool> & visited, vector <int>adj[]){
        visited[curr] = true;
        // traversion over neighbours
        for(int a:adj[curr]){
            if(visited[a]==false){
                if(cycleDFS(a,curr,visited,adj)) return true;   
            } 
            // best move of the code -> only at the end of recursion a!= pre + both are visited
            else if(a!=pre) return true;
        }
        return false;
    }  
  
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector <bool> visited(V,false);
        // We use a loop to access every component of a graph.
        for(int i=0;i<V;i++){
            if(visited[i]==false){
                if(cycleDFS(i,-1,visited,adj)){
                    return true;
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.
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
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends
 // Function to detect cycle in an undirected graph.
    // IN THIS APPROCH I AM USING A FLAG CHECK_CYCLE TO FIND THE CORRECT ANSWER
    /*bool check_cycle = false;
    void helper_isCycle( int curr ,vector<int> adj[],vector<bool> &visited,int previous){
        visited[curr] = true;
        for(int neighbour : adj[curr]){
            if(!visited[neighbour]){
                helper_isCycle(neighbour,adj,visited,curr);
            }
            else {
                if(neighbour != previous){
                    check_cycle = true;
                    return;
                }
            }
        }
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited (V,false);
        int previous = -1;
        //int curr = 0;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                helper_isCycle(i,adj,visited,previous);
                if(check_cycle) return true;
            }
        }
        return false;
        
    }
    */ 
