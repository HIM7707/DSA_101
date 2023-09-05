class Solution {
public:
    int maxiDepth = -1;
    void helper_maxDepth(TreeNode* root,int height){
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL){
            if(maxiDepth < height){
                maxiDepth = height;
            }
        }
        helper_maxDepth(root->left,height+1);
        helper_maxDepth(root->right,height+1);
    }
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        helper_maxDepth(root,1);
        return maxiDepth;
    }
};
