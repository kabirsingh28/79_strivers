class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int left=0,right=n-1;
        int maxleft=0,maxright=0,res=0;
        while(left<right){
            if(height[left]<=height[right]){
                if(maxleft<=height[left]) maxleft=height[left];
                else res+=maxleft-height[left];
                left++;
            }
            else{
                if(maxright<=height[right]) maxright=height[right];
                else res+=maxright-height[right];
                right--; 
            }
        }
        return res;
    }
};