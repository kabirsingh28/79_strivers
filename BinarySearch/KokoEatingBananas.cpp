class Solution {
    bool isPossible(int m, vector<int>& p, double hr){
         double timeReq=0;
         for(int i=0; i<p.size(); i++){
             timeReq+=ceil((double)p[i]/(double)m);
         }
         return timeReq<=hr;
    }
public:
    int minEatingSpeed(vector<int>& p, int hr) {
        int l=1,h=*max_element(p.begin(),p.end()),m=0;
        while(l<=h){
            m=(l+h)/2;
            if(isPossible(m,p,hr)) h=m-1;
            else l=m+1;
        }
        return l;
    }
};