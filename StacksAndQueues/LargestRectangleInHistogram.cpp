class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n=h.size();
   stack<int> s;
   int leftsmall[n],rightsmall[n];

   for(int i=0; i<n; i++){
     while(!s.empty() && h[s.top()]>=h[i]) s.pop();
     if(s.empty()) leftsmall[i]=0;
     else leftsmall[i] = s.top()+1;
     s.push(i);
   }

   while(!s.empty()) s.pop();

   for(int i=n-1; i>=0; i--){
     while(!s.empty() && h[s.top()]>=h[i]) s.pop();
     if(s.empty()) rightsmall[i]=n-1;
     else rightsmall[i] = s.top()-1;
     s.push(i);
   }
   
   int maxi=0;
   for(int i=0; i<n; i++){
     maxi=max(maxi,h[i]*(rightsmall[i]-leftsmall[i]+1));
   }
   return maxi;
    }
};