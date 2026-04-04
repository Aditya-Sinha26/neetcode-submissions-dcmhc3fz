class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> suf(n, 1);
        for(int i=n-2;i>=0;i--){
            suf[i] = nums[i+1]*suf[i+1];
        }
        vector<int> ans;
        int pr=1;
        ans.push_back(suf[0]);
        for(int i=1;i<n;i++){
            pr = pr*nums[i-1];
            ans.push_back(pr*suf[i]);
        }
        return ans;
    }
};
