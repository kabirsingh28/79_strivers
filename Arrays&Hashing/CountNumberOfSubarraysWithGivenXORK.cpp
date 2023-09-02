#include<bits/stdc++.h>

int subarraysWithSumK(vector < int > a, int t) {
   int n=a.size();
   int xr=0;
   int cnt=0;
   unordered_map<int,int> map;
   map[0]=1;
   for(int i=0; i<n; i++){
       xr=xr^a[i];
       int x = xr^t;
       cnt+=map[x];
       map[xr]++;
   }
   return cnt;
}