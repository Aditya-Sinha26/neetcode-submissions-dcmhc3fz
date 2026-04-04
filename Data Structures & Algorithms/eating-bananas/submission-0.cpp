class Solution {
public:
    bool solve(int h, long long mid, vector<int>& piles){
        int cnt=0;
        int n = piles.size();
        for(int i=0;i<n;i++){
            int d = piles[i]/mid;
            if(piles[i]%mid==0)
            cnt+=d;
            else{
                cnt+=d+1;
            }
            if(cnt>h)
            return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        long long st=1, en=0;
        for(int i=0;i<n;i++){
            en=max((long long)piles[i], en);
        }
        long long ans=0;
        while(st<=en){
            long long mid=st+(en-st)/2;
            if(solve(h, mid, piles)){
                ans=mid;
                en=mid-1;
            }
            else{
                st=mid+1;
            }
        }
        return (int)ans;
    }
};
