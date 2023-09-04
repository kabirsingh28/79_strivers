class Solution {
    int f(vector<int>& a, int n){
        if(n==1 || a[0]>a[1]) return 0;
        if(a[n-1]>a[n-2]) return n-1;
        int l=0,h=n-1,m=0;
        while(l<=h){
            m=(l+h)/2;
            if(a[m]>a[m+1]&&a[m]>a[m-1]) return m;
            if(a[m]<a[m+1]) l=m+1;
            else h=m-1;
        }
        return 0; 
    }
public:
    int findPeakElement(vector<int>& a) {
        return f(a,a.size());
    }
};