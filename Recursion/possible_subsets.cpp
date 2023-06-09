#include <iostream>
#include <vector>
using namespace std;
int possible_subsets(int i,vector <int> &arr,int target,int siz){
    // now recursive calls
    if(i>siz){
        if(target==0){
            return 1;
        }
        else{
            return 0;
        }
    }
    int a = possible_subsets(i+1,arr,target-arr[i],siz);
    int b = possible_subsets(i+1,arr,target,siz);
    return a+b;
}
int main() {
	vector <int> arr = {2,3,1,4,6,20};
	int a = possible_subsets(0,arr,5,arr.size()-1);
	cout<< a;
}
