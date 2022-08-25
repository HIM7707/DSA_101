#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector <int> V;
int dp[N];
// 4 5 6 3 2 8 6

int lcs(int p){
    int ans=1;
    if(dp[p] != -1){
        return dp[p];
    }
    for(int i=0;i<p;i++){
         
        if(V[i]<V[p]){
            ans = max(ans ,lcs(i) + 1);
        }
        
    }
    return dp[p]=ans;
}


int main() {
    memset(dp,-1,sizeof(dp));
    int s; cin>>s;
    int si = s;
    while(si--){
        int a; cin>>a;
        V.push_back(a);
    }
    
    int ans = 0;
    for(int i=0;i<s;i++){
        ans = max(ans, lcs(i) );
    }
    cout<<ans;
    
    
    
    
  
  
}








