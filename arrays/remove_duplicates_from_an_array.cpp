 int remove_duplicate(int a[],int n){
        // code here
        int res = 1;
        int siz = sizeof(a)/sizeof(int);
        for(int i=1;i<siz;i++){
            // if diff  
           if(a[i]!=a[res-1]){
               a[res] = a[i];
               res++;
           }
        }
        return res;
    }
