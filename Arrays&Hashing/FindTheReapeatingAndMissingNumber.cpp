#include<bits/stdc++.h>

vector<int> findMissingRepeatingNumbers(vector<int> a){
    int n = a.size();
    int xr = 0;
    for(int i=0; i<n; i++){
       xr^=a[i];
       xr^=(i+1);
    }
    int bitno=0;
    // while(1){
    //   if((xr & (1<<bitno))!=0){
    //     break;
    //   }
    //    bitno++;
    // }
    int num = xr & ~(xr-1);
    int one=0;
    int zero=0;
    for(int i=0; i<n; i++){
      if((a[i]&(num))!=0){
        one^=a[i];
      }
      else{
        zero^=a[i];
      }
    }
    for(int i=1; i<=n; i++){
      if(( i&(num))!=0){
        one^=i;
      }
      else{
        zero^=i;
      }
    }
    int cnt=0;
    for(int i=0; i<n; i++){
      if(a[i]==zero) cnt++;
    }
    if(cnt==2) return {zero,one};
    return {one,zero};
    // long long s1=0,s2=0,s3=0,s4=0;
    // for (int i = 0; i < n; i++) {
    //   s1 += a[i];
    //   s3 += pow(a[i], 2);
    // }
    // s2=n*(n+1)/2;
    // s4=s2*(2*n+1)/3;
    // long long val1 = s2-s1; //q-p
    // long long val2 = s4-s3; //(q-p)(q+p)
    // val2 = val2/val1;
    // long long q = (val1+val2)/2;
    // long long p = val2 - q;
    // vector<int> v(n+1,0);
    // for(int i=0; i<n; i++){
    //   v[a[i]]++;
    // }
    // int p,q;
    // for(int i=1; i<=n; i++){
    //     if(v[i]==0) q=i;
    //     else if(v[i]==2) p=i;
    // }

    // for(int i=1; i<=n; i++){
    //     map[i]=0;
    // }
    // for(int i=0; i<n; i++){
    //    map[a[i]]++;
    // }
    // int p,q;
    // for(auto it: map){
    //     if(it.second==0) q=it.first;
    //     else if(it.second==2) p=it.first;
    // }

    
    // int p;
    // for(auto it: map){
    //     if(it.second==2) p=it.first;
    // }
    // int sum = n*(n+1)/2;
    // int sum2 = 0;
    // for(int i=0; i<n; i++) sum2+=a[i];
    // int q = sum - sum2 + p;
    //return {p,q};
}