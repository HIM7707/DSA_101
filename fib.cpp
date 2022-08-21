#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

int DP[N];

int fib(int Nth){
    if(Nth == 0) return 0;
    if(Nth == 1) return 1;
    
    if(DP[Nth] != -1){
        return DP[Nth];
    }
    return DP[Nth]=fib(Nth-1)+fib(Nth-2);
}

int main() {
    // we need to find the Nth number of fib series.
    memset(DP,-1,sizeof(DP));
    int Nth; cin>>Nth;
    cout<<fib(Nth);
    
    
  
  
}



//0 1 1 2 






