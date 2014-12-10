/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        if(intervals.size() == 0)
        {
            vector<Interval> r;
            r.push_back(newInterval);
            return r;
        }
        else
        {
            int begin = 0;
            int end = intervals.size()-1;
            if(newInterval.end < intervals[begin].start)
            {
                intervals.insert(intervals.begin(),newInterval);
            }
            else if(newInterval.start > intervals[end].end)
            {
                intervals.insert(intervals.end(),newInterval);
            }
            else
            {
                while(end >= begin)
                {
                    if(newInterval.end < intervals[end].start)
                    {
                        end--;
                    }else if(newInterval.start > intervals[begin].end)
                    {
                        begin++;
                    }
                    else
                    {
                        break;
                    }
                };
                if(end >= begin)
                {
                    int s = intervals[begin].start>newInterval.start?newInterval.start:intervals[begin].start;
                    int e = intervals[end].end<newInterval.end?newInterval.end:intervals[end].end;
                    intervals.erase(intervals.begin()+begin, intervals.begin()+end+1);
                    intervals.insert(intervals.begin()+begin,*(new Interval(s,e)));
                }
                else
                {
                    intervals.insert(intervals.begin()+begin,newInterval);
                }
            }
            return intervals;
        }
    }
};