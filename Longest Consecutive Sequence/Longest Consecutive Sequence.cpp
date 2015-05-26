class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> used;

        for(int i : nums)
            used[i] = false;

        int maxlength = 0;
        for(int i : nums)
        {
            if(used[i])
                continue;

            int len = 1;
            for(int j = i + 1; used.find(j) != used.end(); ++j)
            {
                used[j] = true;
                len++;
            }

            for(int j = i - 1; used.find(j) != used.end(); --j)
            {
                used[j] = true;
                len++;
            }

            maxlength = max(len, maxlength);
        }

        return maxlength;
    }
};