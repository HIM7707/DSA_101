int dp[10010];
    int min_coins(vector<int>& coins, int amt){
        if(amt ==0) return  0;
        if(dp[amt] !=-1){
            return dp[amt];
        }
         int  ans = INT_MAX;
        for(int i=0;i<coins.size();i++){
            if((amt-coins[i])>=0){
                ans = min(ans+0LL   ,min_coins(coins,amt - coins[i])+1LL);
            }
        }
        return  dp[amt]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        int ans =min_coins(coins,amount);
        return ans==INT_MAX ? -1 : ans;
    }


// link to question -> https://leetcode.com/problems/coin-change/submissions/
