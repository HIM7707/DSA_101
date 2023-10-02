//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool dfs_helper(int node , vector <int> &visited,vector<vector<int> >& adj_list,vector <int> &rec_stack){
        visited[node] = 1;
        rec_stack[node] = 1;
        // traverse over the neighbours
        for(int i:adj_list[node]){
            if(!visited[i]){
                if( dfs_helper(i,visited,adj_list,rec_stack)) return true;
            }
            else if(rec_stack[i]){
                return true;
            }
        }
        rec_stack[node] = 0;
        return false;
    }
	bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector <int> visited(N,0);
	    vector <vector <int>> adj_list(N);
	    vector <int> rec_stack(N,0);
	    for(int i=0;i<P;i++){
	        int start = prerequisites[i].first;
	        int end = prerequisites[i].second;
	        adj_list[start].push_back(end);
	    }
	    for (int i=0;i<N;i++){
	        if(!visited[i]){
	            if (dfs_helper(0,visited,adj_list,rec_stack)) return false;
	        }
	    }
	    return true;
	    
	   // dfs_helper(0,visited,adj_list,rec_stack);
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends
