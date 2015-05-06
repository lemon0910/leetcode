class Solution {
public:
    int jump(vector<int>& nums) {
        int farthest = 0;
        int reachable = 0;
        int step = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(i > reachable)
            {
                step++;
                reachable = farthest;
            }
            
            farthest = max(farthest, i + nums[i]);
        }
        
        return step;
    }
};
