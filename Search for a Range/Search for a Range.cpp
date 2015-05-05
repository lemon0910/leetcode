class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = -1;
        int end = -1;
        int index = -1;
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right)
        {
            int mid = (left + right) / 2;
            if(nums[mid] == target)
            {
                index = mid;
                break;
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
        
        if(index == -1)
        {
            return vector<int>{-1, -1};
        }
        
        start = index;
        while(start >= 0 && nums[start] == target)
        {
            start--;
        }
        start++;
        end = index;
        while(end < nums.size() && nums[end] == target)
        {
            end++;
        }
        end--;
        
        return vector<int>{start, end};
    }
};
