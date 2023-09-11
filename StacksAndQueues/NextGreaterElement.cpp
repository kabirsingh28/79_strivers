class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
    vector<int> v(n);
  for (int i = 0; i<=2n-1; i++) {
	    while(!st.empty()&&st.top()<=a[i%n]) st.pop();
		if(st.empty()) v[i]=-1;
		else v[i]=st.top();
		st.push(a[i]);
  }
  return v;
    }
};