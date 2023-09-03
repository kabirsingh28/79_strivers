class Solution {
    int f(vector<int>& a, int n){
        int l=0,h=n-1,m=0;
        int mini=INT_MAX;
        while(l<=h){
            m=(l+h)/2;
            if(a[l]<=a[m]){
             mini=min(mini,a[l]);
             l=m+1;
            }
            else{
             mini=min(mini,a[m]);
             h=m-1;
            }
        }
        return mini;
    }
public:
    int findMin(vector<int>& a) {
        return f(a,a.size());
    }
};