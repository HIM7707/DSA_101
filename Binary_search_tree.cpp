
// Function to search a node in BST.
bool search(Node* root, int x) {
    // Your code here
    // This is iterative implementation
    /*
    while(root != NULL){
        if(root->data == x) return true;
        else if (root->data > x) root = root->left;
        else root = root->right;
    }
    return false;
    */ 
    // this is recursive 
    if ( root == NULL) return false;
    if(root->data == x) return true;
    else if(root->data > x) search(root->left , x);
    else search (root->right, x);
    
    // time complexity = o(h) -> h is the height
    // space comp -> iterative -> o(1) -> recursive -> 0(h) bcoz of function call stack.
}
