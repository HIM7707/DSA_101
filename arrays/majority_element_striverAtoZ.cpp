int majorityElement(vector<int> v) {
	// Write your code here
	int el;
	int count =0;
	for(int i=0;i<v.size();i++){
		if(count ==0){
			el = v[i];
			count ++;
			continue;
		}
		else{
			if(v[i]==el){
				count++;
			}
			else{
				count--;
			}
		}
	}
	return el;
}
