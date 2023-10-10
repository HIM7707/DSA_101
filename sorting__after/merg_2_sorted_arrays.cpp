void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            // code here 
                        int i=0;
                        int j=0;
            
                        while(i<n && j<m){
                            if(arr1[i]> arr2[j]){
                                cout<<arr2[j++]<<" ";
                               
                            }
                            else{
                                cout<<arr1[i++]<<" ";
                                
                            }
                        }
                        cout<<i<< "->" <<j;
                        while(i<n){
                            cout<<arr1[i++]<<" ";
                        }
                        while(j<m){
                            cout<<arr2[j++]<<" ";
                        }
        } 
