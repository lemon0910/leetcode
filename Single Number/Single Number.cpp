class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = nums[0];
        for (size_t i = 1; i < nums.size(); ++i)
            x ^= nums[i];
        return x;
    }
};