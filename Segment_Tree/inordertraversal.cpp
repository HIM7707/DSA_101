vector<int> levelOrder(Node* node)
    {
      //Your code here
      vector <int> ans;
      if(node == NULL) return ans;
      queue <Node*> Q;
      Q.push(node);
      Q.push(NULL);  
      
      while(!Q.empty()){
          // access the front element
          // push its children
          // pop the front element
          Node * curr = Q.front();
          if(curr == NULL){
              cout<<endl;
              Q.pop();
              if(!Q.empty()){
                  Q.push(NULL);
              }
          }
          else{
               
          Q.pop();
          
          ans.push_back(curr->data);
         // cout<<curr->data<<" ";
          if(curr->left != NULL){
              Q.push(curr->left);
          }
          if(curr->right != NULL){
              Q.push(curr->right);
          }
          }   
              

          
          Q.pop();
          
          
      }
      return ans;
    }
