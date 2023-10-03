class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    vector<vector<int>> dp (n,vector<int>(m,-1));
    int lcs(int n, int m, string s1, string s2)
    {   
        if(dp[n][m] == -1){
            if(n==0 || m==0) return 0;
            // your code here
            if(s1[n-1] == s2[m-1]){
                dp[n][m] =  1+lcs(n-1,m-1,s1,s2);
            }
            else{
                dp[n][m]= max(lcs(n-1,m,s1,s2),lcs(n,m-1,s1,s2));
            }
        }
        
        return dp[n][m];
    }
};
