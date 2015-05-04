class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ret = nums[0] + nums[1] + nums[2];
        for(auto iti = nums.begin(); iti != nums.end(); iti = upper_bound(nums.begin(), nums.end(), *iti))
        {
            for(auto itj = iti + 1; itj != nums.end(); itj = upper_bound(itj + 1, nums.end(), *itj))
            {
                int temp = target - *iti - *itj;
                auto itk = lower_bound(itj + 1, nums.end(), temp);
                if(itk != nums.end())
                {
                    if(abs(*iti + *itj + *itk - target) < abs(ret - target))
                        ret = *iti + *itj + *itk;
                }
                if(itk - 1 > itj)
                {
                    if(abs(*iti + *itj + *(itk - 1) - target) < abs(ret - target))
                        ret = *iti + *itj + *(itk - 1);
                }
            }
        }

        return ret; 
    }
};
