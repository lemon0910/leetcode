/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 bool cmp(Interval a, Interval b)
 {
     return a.start < b.start;
 }
 
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ret;
        if(intervals.empty())
            return ret;
        Interval temp;
        sort(intervals.begin(), intervals.end(), cmp);
        temp = intervals[0];
        for(int i = 1; i < intervals.size(); ++i)
        {
            if(intervals[i].start >= temp.start && intervals[i].start <= temp.end)
            {
                if(intervals[i].end > temp.end)
                    temp.end = intervals[i].end;
            }
            else
            {
                ret.push_back(temp);
                temp = intervals[i];
            }
        }
        
        ret.push_back(temp);
        return ret;
    }
};
