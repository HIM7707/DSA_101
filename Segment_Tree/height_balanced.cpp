class Solution {
public:
    bool check = true;
    int helper_isBalanced(TreeNode* root){
        if(root == NULL) return 0;
        int left = helper_isBalanced(root->left);
        int right = helper_isBalanced(root->right);
        int diff = abs(left - right);
        if(diff > 1 ) check =  false;
        return max(left,right)+1;
    }
   
    bool isBalanced(TreeNode* root) {
       if(root == NULL) return true; 
       helper_isBalanced(root);
       return check;

    }
};
