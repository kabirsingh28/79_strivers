class Solution {
public:
    int maxSubArray(vector<int>& a) {
        int n=a.size();
        int sum=0;
        int maxSum=0;
        int i=0;
        for(; i<n; i++){
            if(a[i]<0) continue;
            else break;
        }
       
        if(i==n) return *max_element(a.begin(),a.end());

        for(int i=0; i<n; i++){
            sum+=a[i];
            maxSum=max(sum,maxSum);
            if(sum<0) sum=0;
        }
        return maxSum;
    }
};