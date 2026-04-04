class Solution {
public:
    int findMin(vector<int> &nums) {
        int n= nums.size();
        int st=0, en=n-1;
        while(st<=en){
            int mid = st+(en-st)/2;
            int next = (mid+1)%n;
            int prev = (mid+n-1)%n;
            if(nums[mid]<=nums[next] && nums[mid]<=nums[prev])
            return nums[mid];
            else if(nums[st]>=nums[en] && nums[mid]>=nums[st]){
                st=mid+1;
            }
            else{
                en=mid-1;
            }
        }
        return -1;
    }
};
