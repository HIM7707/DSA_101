class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void Swapping(Node *node){
        if(node->left== NULL && node->right == NULL) return ;
        Node * left = node -> left;
        Node * right = node -> right;
        node -> left = right ;
        node -> right = left;
        
    }
    void mirror(Node* node) {
        // code here
        if(node == NULL) return ;
        mirror(node -> left);
        mirror(node -> right);
        Swapping(node);
    }
};
