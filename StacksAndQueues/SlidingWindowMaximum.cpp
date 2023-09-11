class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        vector<int> ans;
        int n=a.size();
    deque<int> dq;
    for(int i=0; i<n; i++){
        if(!dq.empty() && dq.front()==i-k) dq.pop_front();
        while(!dq.empty() && a[dq.back()]<a[i]) dq.pop_back();
        dq.push_back(i);
        if(i>=k-1) ans.push_back(a[dq.front()]);
    }
    return ans;
    }
};