#include<bits/stdc++.h>
int subarrayWithMaxProduct(vector<int> &a){
	int n = a.size();
	int maxi=INT_MIN;
	int prefix=1;
	int suffix=1;
	for(int i=0; i<n; i++){
		if(prefix==0) prefix=1;
		if(suffix==0) suffix=1;
		prefix*=a[i];
		suffix*=a[n-1-i];
		maxi=max(maxi,max(prefix,suffix));
	}
	return maxi;
}