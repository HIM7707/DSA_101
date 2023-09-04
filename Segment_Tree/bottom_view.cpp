 vector <int> bottomView(Node *root) {
        // Your Code Here
        vector <int> ans;
        if (root == NULL) return ans;
        queue <pair<Node*,int>> Qpp ; 
        map <int,int> mpp;
        Qpp.push({root,0});
        while(!Qpp.empty()){
            int sizz = Qpp.size();
            for(int i=0;i<sizz;i++){
                auto curr = Qpp.front();
                int line = curr.second;
                Node* curr_node = curr.first;
                mpp[line] = curr_node->data;
                if(curr_node->left != NULL) Qpp.push({curr_node->left,line-1});
                if(curr_node->right != NULL) Qpp.push({curr_node->right,line+1});
                Qpp.pop();
            }
        }
        for (auto i:mpp){
            ans.push_back(i.second);
        }
        
    }
