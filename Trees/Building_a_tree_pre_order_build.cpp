#include <bits/stdc++.h>
using namespace std;
class node {
    public:
        int data;
        node *left;
        node *right;
    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }        
}

node* buildtree(){
    int d;
    cin>>d;
    // base condition
    if(d==-1){
        return NULL;
    }
    
    node *n= new node(d);
    n->left = buildtree();
    n->right = buildtree();
    return n;
}
int main() {
  node *root = buildtree();
  
  
}
