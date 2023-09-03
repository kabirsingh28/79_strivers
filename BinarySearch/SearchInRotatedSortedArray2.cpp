class Solution {

    bool f(vector<int>&a, int n, int tarr){
    int l=0, h=n-1, m=0;
    while(l<=h){
      m=(l+h)/2;
      if(a[m]==tarr) return true;
      if(a[l]==a[m]&&a[m]==a[h]){
          l=l+1;
          h=h-1;
          continue;
      }
      if(a[l]<=a[m]){
          if(tarr>=a[l]&&tarr<=a[m]) h=m-1;
          else l=m+1;
      }
      else{       
          if(tarr>=a[m]&&tarr<=a[h]) l=m+1;
          else h=m-1;
      }
    }
    return false;
}
public:
    bool search(vector<int>& a, int tarr) {
        return f(a,a.size(),tarr);
    }
};