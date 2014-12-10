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
    static bool compareInterval(const Interval& a, const Interval& b)
	{
		return a.start < b.start;
	}

    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> ret;
		if(intervals.size() > 0)
		{
			sort(intervals.begin(), intervals.end(), Solution::compareInterval);
			Interval temp = intervals.at(0);
			for(int i = 1; i < intervals.size(); ++i)
			{
				if(intervals.at(i).end < temp.start || intervals.at(i).start > temp.end)
				{
					ret.push_back(temp);
					temp = intervals.at(i);
				}
				else
				{
					temp.start = min(temp.start, intervals.at(i).start);
					temp.end = max(temp.end, intervals.at(i).end);
				}
			}
			ret.push_back(temp);
		}
		return ret;
    }
};