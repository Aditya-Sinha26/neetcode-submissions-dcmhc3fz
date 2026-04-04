class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int t = n/3;
        int cnt1=0, cnt2=0, c1=0,c2=0;
        for(int i=0;i<n;i++){
            if(cnt1==0 && c2!=nums[i])
            {
                cnt1++;
                c1=nums[i];
            }
            else if(cnt2==0 && c1!=nums[i]){
                cnt2++;
                c2=nums[i];
            }
            else if(c1==nums[i])
            cnt1++;
            else if(c2==nums[i])
            cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1=0;
        cnt2=0;
        for(int i=0;i<n;i++){
            if(c1==nums[i])
            cnt1++;
            else if(c2==nums[i])
            cnt2++;
        }
        vector<int> ans;
        if(cnt1>t)
        ans.push_back(c1);
        if(cnt2>t)
        ans.push_back(c2);

        return ans;
    }
};