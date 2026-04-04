class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        vector<int> newInt = intervals[0];
        for(int i=1;i<n;i++){
            if(intervals[i][0]<=newInt[1]){
                newInt[0] = min(intervals[i][0], newInt[0]);
                newInt[1] = max(intervals[i][1], newInt[1]);
            }
            else{
                ans.push_back(newInt);
                newInt = intervals[i];
            }
        }
        ans.push_back(newInt);
        return ans;
    }
};
