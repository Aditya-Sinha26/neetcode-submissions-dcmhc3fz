class Solution {
public:
    vector<vector<int>> ans;
    set<vector<int>> st;
    void solve(int idx, vector<int>& nums, vector<int> &t){
        if(idx == nums.size()){
            if(st.find(t)==st.end()){
                st.insert(t);
                ans.push_back(t);
            }
            return;
        }
        t.push_back(nums[idx]);
        solve(idx+1, nums, t);
        t.pop_back();
        solve(idx+1, nums, t);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> t;
        solve(0,nums, t);

        return ans;
    }
};
