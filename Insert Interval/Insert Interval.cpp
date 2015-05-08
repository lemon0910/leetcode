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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> ret = intervals;
        if(ret.empty())
        {
            ret.push_back(newInterval);
            return ret;
        }
        int index = -1;
        int left = 0;
        int right = ret.size() - 1;
        while(left <= right)
        {
            int mid = (left + right) / 2;
            if(ret[mid].start == newInterval.start)
            {
                index = mid;
                break;
            }
            else if(ret[mid].start > newInterval.start)
                right = mid - 1;
            else
                left = mid + 1;
        }

        if(index != -1)
        {
            vector<Interval>::iterator it = ret.begin();
            int temp = index;
            while(temp > 0)
            {
                temp--;
                it++;
            }
            vector<Interval>::iterator itt = it;
            while(it != ret.end() && newInterval.end >= it->end)
            {
                it++;
            }
            if(it != ret.end() && it->start <= newInterval.end)
                it++;
            it--;
            newInterval.end = max(newInterval.end, it->end);
            ret.erase(itt, it + 1);
            ret.insert(itt, newInterval);
        }
        else
        {
            int flag = false;
            if(left - 1 >= 0 && newInterval.start >= ret[left - 1].start && newInterval.start <= ret[left - 1].end)
            {
                flag = true;
                newInterval.start = min(ret[left - 1].start, newInterval.start);
                newInterval.end = max(ret[left - 1].end, newInterval.end);
            }

            vector<Interval>::iterator it = ret.begin();
            int temp = left;
            if(flag)
                temp--;
            while(temp > 0)
            {
                temp--;
                it++;
            }
            vector<Interval>::iterator itt = it;
            bool diret = true;
            while(it != ret.end() && newInterval.end >= it->end)
            {
                it++;
                diret = false;
            }
            if(it != ret.end() && it->start <= newInterval.end)
            {
                it++;
                diret = false;
            }
            it--;
            newInterval.end = max(newInterval.end, it->end);
            if(!diret)
                ret.erase(itt, it + 1);
            ret.insert(itt, newInterval);
        }

        return ret;
    }
};
