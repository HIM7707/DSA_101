class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> vpp;
        queue <pair<TreeNode*,int>> Qpp;
        map <int,vector<int>> mpp;
        if(root == NULL) return vpp;
        Qpp.push({root,0});
        while(!Qpp.empty()){
            int sizz = Qpp.size();
            for(int i=0;i<sizz;i++){
                auto curr = Qpp.front();
                TreeNode* curr_node = curr.first;
                int line = curr.second;
                mpp[line].push_back(curr_node->val);
                if(curr_node->left !=NULL) Qpp.push({curr_node->left,line-1});
                if(curr_node->right !=NULL) Qpp.push({curr_node->right,line+1});
                Qpp.pop();
            }
            
        }
        for(auto i:mpp){
            vpp.push_back(i.second);
        }
        return vpp;
    }
};


only passing 16/32 testcase at leetcode....
