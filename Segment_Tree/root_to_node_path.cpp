vector <string> ans ;
void helper_path(BinaryTreeNode<int> * root,string str_path){
  if (root == NULL) {
        return;
    }
    // left traversal
    int value = root -> data;
    string a = to_string(value);
    str_path = str_path + a+" ";
    if (root->left == NULL && root->right == NULL) {
        ans.push_back(str_path);
        return;
    }
     helper_path(root->left,str_path );
     helper_path(root->right,str_path );
     //str_path.pop_back();
}

vector <string> allRootToLeaf(BinaryTreeNode<int> * root) {
    // Write your code here.
    string str_path = "";
    helper_path(root,str_path);
    return ans;
}
