//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int count_tab(vector <vector <long long int>> &dp,int coins[],int N,int sum){
         if(dp[N][sum]== -1 ){
            if(sum == 0) return 1;
            if (sum < 0) return 0;
            if (N ==0) return 0;
        
        
            // recrsive conditions 
            dp[N][sum] = count_tab(dp,coins,N,sum-coins[N-1]) + count_tab(dp,coins,N-1,sum);
         }
         return dp[N][sum];
         
        
    }
    long long int count(int coins[], int N, int sum) {
        // base condition 
        vector <vector <long long int>> dp (N+1,vector<long long int>(sum+1,-1));
        return count_tab(dp,coins,N,sum);
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends
