class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int ret = -1;
        while(left <= right)
        {
            int mid = (left + right) / 2;
            if(nums[mid] == target)
            {
                ret = mid;
                return ret;
            }

            if(nums[left] <= nums[right])
            {
                if(nums[mid] > target)
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else
            {
                if(nums[mid] >= nums[left])
                {
                    if(nums[left] > target)
                    {
                        left = mid + 1;
                    }
                    else if(nums[mid] > target)
                    {
                        right = mid - 1;
                    }
                    else
                    {
                        left = mid + 1;
                    }
                }
                else
                {
                    if(nums[right] < target)
                    {
                        right = mid - 1;
                    }
                    else if(nums[mid] > target)
                    {
                        right = mid - 1;
                    }
                    else
                    {
                        left = mid + 1;
                    }
                }
            }
        }
        
        return ret;
    }
};
