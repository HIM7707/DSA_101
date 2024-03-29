int floorInBST(TreeNode<int> * root, int X)
{
    // Write your code here.
    int min = -1;
    while(root != NULL){
        if(root->val >X){
            root = root->left;

        }
        else if(root -> val <X){
            if (min == -1) min = INT_MAX;
            int rem = X- (root->val);
            root = root -> right;
            
            if(min>rem) min = rem;
        }
        else{
            return root-> val;
        }
    }
    if(min == -1) return -1 ;
    else return X-min;
}
// much smarter and better approach by gfg founder
    TreeNode<int> *ans = NULL;
    while(root !=NULL){
        if(root->val >X){
            root = root->left;

        }
        else if(root -> val <X){
           ans = root;
           root = root-> right;
        }
        else{
            return root-> val;
        }
    }
    if(ans == NULL) return -1;
    else return ans->val;
