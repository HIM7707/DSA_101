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
              if(!Q.empty()){   // to prevent the infinite loop if the last element is null -> which will always be.
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








2. even better code 
class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* node)
    {
      //Your code here
      vector <int>ans;
      queue <Node*> Q;
      Q.push(node);
      while(!Q.empty()){
          int sizee = Q.size();
          for(int i=0;i<sizee;i++){
              Node* curr = Q.front();
              ans.push_back(curr->data);
              if(curr->left !=NULL) Q.push(curr->left);
              if(curr->right !=NULL) Q.push(curr->right);
              Q.pop();
          }
      }
      return ans;
    }
};
