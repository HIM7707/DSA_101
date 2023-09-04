 vector<int> topView(Node *root)
    {
        //Your code here
        vector <int> ans;
        if(root == NULL ) return ans;
        queue<pair<Node*,int>> Qpp;
        Qpp.push({root,0});
        map <int,int> mpp;
        while(!Qpp.empty()){
            int sizz = Qpp.size();
            for(int i=0;i<sizz;i++){
                auto curr = Qpp.front();
                Node* curr_node = curr.first;
                int line = curr.second;
                if(mpp.find(line)==mpp.end()) mpp[line] = curr_node->data;
                if(curr_node -> left != NULL) Qpp.push({curr_node->left,line - 1});
                if(curr_node -> right != NULL) Qpp.push({curr_node->right,line + 1});
                Qpp.pop();
            }
        }
        for(auto i : mpp){
            ans.push_back(i.second);
        }
        return ans;
    }
