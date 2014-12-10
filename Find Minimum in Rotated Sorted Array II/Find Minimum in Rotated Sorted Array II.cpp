class Solution {
public:
    int findMin(vector<int> &num) 
    {
        int len = num.size();
        if(0 == len)
            return 0;

        int left = 0;
        int right = len - 1;
        int ret = num[0];
        while(left <= right)
        {
            int mid = (left + right) / 2;
            if(mid == left)
            {
                ret = min(ret, min(num[left], num[right]));
                break;
            }
            
            ret = min(ret, num[mid]);
            if(num[mid] > num[left])
            {
                if(num[mid] <= num[right])
                {
                    right = mid - 1;
                    continue;
                }
                else
                {
                    left = mid + 1;
                    continue;
                }
            }
            else if(num[mid] == num[left])
            {
                if(num[mid] < num[right])
                {
                    break;
                }
                else if(num[mid] == num[right])
                {
                    left++;
                    right--;
                    continue;
                }
                else
                {
                    left = mid + 1;
                    continue;
                }
            }
            else
            {
                if(num[mid] < num[right])
                {
                    right = mid - 1;
                    continue;
                }
                else if(num[mid] == num[right])
                {
                    right = mid - 1;
                    continue;
                }
            }
        }

        return ret;
    }
};
