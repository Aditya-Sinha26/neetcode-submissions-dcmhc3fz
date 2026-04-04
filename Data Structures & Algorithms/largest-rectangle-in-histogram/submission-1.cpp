class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> st1;
        stack<pair<int,int>> st2;
        int n=heights.size();
        vector<int> left, right;
        for(int i=0;i<n;i++){
            while(!st1.empty() && st1.top().first>=heights[i]){
                st1.pop();
            }
            if(st1.empty())
            left.push_back(-1);
            else if(!st1.empty() && st1.top().first<heights[i]){
                left.push_back(st1.top().second);
            }
            st1.push({heights[i], i});
        }
        for(int i=n-1;i>=0;i--){
            while(!st2.empty() && st2.top().first>=heights[i]){
                st2.pop();
            }
            if(st2.empty())
            right.push_back(n);
            else if(!st2.empty() && st2.top().first<heights[i]){
                right.push_back(st2.top().second);
            }
            st2.push({heights[i], i});
        }
        reverse(right.begin(), right.end());
        int ans=0, temp =0;
        for(int i=0;i<n;i++){
            temp = heights[i];
            int length = right[i]-left[i]-1;
            if(length>0)
            temp = heights[i]*length;
            ans=max(ans, temp);
        }
        return ans;
    }
};
