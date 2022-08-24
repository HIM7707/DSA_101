#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

vector <int> h;
int dp[N];

int find_min_jumps(int i){
    if(i==0 || i==1) return 0 ;
    if(dp[i]!=-1) return dp[i];
    
    int i_minus_1 = find_min_jumps(i-1)+abs(h[i-1]-h[i]);
    //cout<<i_minus_1<<" ";
    //int i_minus_2 = INT_MAX;
    
    int i_minus_2 = find_min_jumps(i-2)+abs(h[i-2]-h[i]);
    
    return dp[i] = min(i_minus_1,i_minus_2);
    
}


int main() {
    memset(dp,-1,sizeof(dp));
    int t; cin>>t;
    int t_ = t;
    while(t_ --){
        int a; cin>>a;
        h.push_back(a);
    }
    cout<< find_min_jumps(t-1);
    
  
  // https://atcoder.jp/contests/dp/tasks/dp_a    -- problem link
    
    
  
  
}








