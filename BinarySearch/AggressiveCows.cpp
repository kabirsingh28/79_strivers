#include<bits/stdc++.h>

bool canWePlace(vector<int> &s,int m, int cows){
    int lastcow=s[0];
    int cntcow=1;
    for(int i=0; i<s.size(); i++){
        if(s[i]-lastcow>=m){
            lastcow=s[i];
            cntcow++;
        }
    }

    return cntcow>=cows;
}

int aggressiveCows(vector<int> &s, int cows)
{   int n=s.size();
    sort(s.begin(),s.end());
    int l=1, h=s[n-1]-s[0],m=0;
    while(l<=h){
        m=(l+h)/2;
        if(canWePlace(s,m,cows)) l=m+1;
        else h=m-1;
    }
    return h;
}