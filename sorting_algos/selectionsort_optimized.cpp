void selectionSort(int arr[], int n)
    {
       //code here
       vector<int> ans;
       for(int j=0;j<n;j++){
        int min = INT_MAX;
        int index = -1;
        for(int i=0;i<n;i++){
            if(arr[i]<min){
                min = arr[i];
                index = i;
            }
        }
        
         ans.push_back(arr[index]);
         arr[index] = INT_MAX;
         
       } 
       
       for(int i=0;i<n;i++){
           arr[i] = ans[i];
       }
       
    }
};
