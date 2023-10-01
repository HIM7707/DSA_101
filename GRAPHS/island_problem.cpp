
class Solution {
  public:
  void dfs_helper(int node ,vector<vector<int>> &adj,int V,vector<int> &visited){
      visited[node] = 1;
      
      for(int i=0;i<V;i++){
          if(visited[i]== 0 && adj[node][i]==1){
              dfs_helper(i,adj,V,visited);
          }
      }
  }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector <int> visited(V,0);
        int island=0;
        for(int i=0;i<V;i++){
            if(visited[i]==0){
                island++;
                dfs_helper(i,adj,V,visited);
            }
        }
        return island;
    }
};
