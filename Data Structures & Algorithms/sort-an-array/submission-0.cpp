class Solution {
public:
    int pos(vector<int> &nums, int l, int r){
        int pivot = nums[r];
        int idx = l-1;
        for(int i=l;i<r;i++){
            if(nums[i]<pivot)
            {
                idx++;
                swap(nums[idx], nums[i]);
            }
        }
        swap(nums[idx+1], nums[r]);
        return idx+1;
    }
    void quickSort(vector<int> &nums,int l,int r ){
        if(l<r){
            int pivot = pos(nums, l , r);
            quickSort(nums, l, pivot-1);
            quickSort(nums, pivot+1, r);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1);
        return nums;
    }
};