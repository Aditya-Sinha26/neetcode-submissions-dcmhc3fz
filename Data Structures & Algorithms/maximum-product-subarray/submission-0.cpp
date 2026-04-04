class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefix =1, mx=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            prefix*=nums[i];
            mx=max(prefix, mx);
            if(prefix==0)
            prefix=1;
        }
        prefix=1;
        for(int i=n-1;i>=0;i--){
            prefix*=nums[i];
            mx=max(prefix, mx);
            if(prefix==0)
            prefix=1;
        }
        return mx;
    }
};
