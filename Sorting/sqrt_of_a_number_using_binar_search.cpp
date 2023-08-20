//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        // Your code goes here   
        long start = 1 ; long end = x;
        long ans = 0;
        while (start <= end){
            long mid = (start+end)/2;
            long squrt = mid * mid ;
            // conditions 
            if (x == squrt ){
                return mid ;
            }
            else if (x > squrt){
                start = mid + 1;
                ans = mid ;
            }
            else {
                end = mid  - 1;
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}

// } Driver Code Ends
