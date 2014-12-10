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
            if(num[mid] >= num[left] && num[mid] >= num[right])
                left = mid + 1;
            else if(num[mid] >= num[left] && num[mid] <= num[right])
                right = mid - 1;
            else if(num[mid] <= num[left])
                right = mid - 1;

            ret = min(ret, num[mid]);
        }

        return ret;
    }
};
