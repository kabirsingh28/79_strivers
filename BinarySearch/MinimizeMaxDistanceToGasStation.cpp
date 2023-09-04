#include<bits/stdc++.h>

int cntofgas(vector<int> &a,long double mid){
	int cnt=0;
	for(int i=1; i<a.size(); i++){
       int numberinbt=(a[i]-a[i-1])/mid;
	   if((a[i]-a[i-1])==numberinbt*mid){
		   numberinbt--;
	   }
	   cnt+=numberinbt;
	}
	return cnt;
}

long double minimiseMaxDistance(vector<int> &a, int k){
	int n=a.size();
// 	vector<int> howMany(n-1,0);
// 	priority_queue<pair<long double,int>> pq;
//     for(int i=0; i<n-1; i++){
// 		pq.push({a[i+1]-a[i],i});
// 	}
// 	for(int gasS=1; gasS<=k; gasS++){
// 		auto tp = pq.top();
// 		pq.pop();
// 		int index = tp.second;
// 		howMany[index]++;
// 		long double diff = a[index+1]-a[index];
// 		long double newLength = diff/(long double)(howMany[index]+1);
// 		pq.push({newLength,index});		
// 	}
//    return pq.top().first;
     long double l=0,h=0,mid=0,x=1e-6;
	 for(int i=0; i<n-1; i++){
		 h=max(h,(long double)(a[i+1]-a[i]));
	 }
	while(h-l>x){
		mid=(l+h)/2.0;
		int cnt = cntofgas(a,mid);
		if(cnt>k) l=mid;
		else h=mid;
	}
	return h;
}