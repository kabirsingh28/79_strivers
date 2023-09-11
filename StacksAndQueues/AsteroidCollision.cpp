class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
      stack<int>s;
    for(int i=0;i<a.size();i++)
    {
        bool flag=true;
        while(!s.empty() && s.top()>0 && a[i]<=0 && flag)
        {
            if(abs(a[i])>s.top()) s.pop();
            
            else if(abs(a[i])==s.top())
            {
                s.pop();
                flag=false;
            }
            else flag=false;    
        }
        if(flag) s.push(a[i]);
    }
    vector<int>ans(s.size());
    for(int i=s.size()-1;i>=0;i--)
    {
        ans[i]=s.top();
        s.pop();
    }
    return ans;
    }
};