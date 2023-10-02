class Solution {
  public:
    // Function to find the number of islands.
    void call_bfs(int i,int j,vector <vector<int>>& visited, vector<vector<char>>& grid){
        visited[i][j]=1;
        queue<pair<int,int>> q;
        q.push({i,j});
        int n = grid.size();
        int m = grid[0].size();
        
        while(q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            // now traverse over all the neightbours of the land that you have found ;
            for (int delrow = -1; delrow<=1;delrow++){
                for(int delcol = -1;delcol<=1;delcol++ ){
                    int nrow = row+delrow;
                    int ncol = col+delcol;
                    if(nrow >= 0 && nrow< n && ncol >= 0 && ncol< m && grid[nrow][ncol] == '1' && !visited[nrow][ncol]){
                        visited[nrow][ncol] = 1;
                        q.push({nrow,ncol});
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        vector <vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        int island = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    island++;
                    call_bfs(i,j,visited,grid);
                }
            }
        }
        return island;
        
    }
};
