/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    static bool comp(Interval a, Interval b){
        return a.start < b.start;
    }
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n = intervals.size();
        if(n==0 || n==1)
        return true;
        sort(intervals.begin(), intervals.end(), comp);
        Interval a = intervals[0];
        for(int i=1;i<n;i++){
            if(a.end>intervals[i].start)
            return false;
            a = intervals[i];
        }
        return true;
    }
};
