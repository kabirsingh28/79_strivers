class Solution {
public:
    int findKthLargest(vector<int>& a, int k) {
        int n=a.size();
        priority_queue <int, vector<int>, greater<int> > pq;
        for(int i=0; i<k; i++){
            pq.push(a[i]);
        }
        vector<int> ans;
        for(int i=k; i<n; i++){
            if(a[i]>pq.top()){
                pq.pop();
                pq.push(a[i]);
            }
        }

        return pq.top();
    }
};