class Solution {
public:
    string getPermutation(int n, int k) {
        long long cycle = 1;
        for(int i = 2; i <= n; ++i)
            cycle *= i;
        k %= cycle;
        if(k == 0)
            k = cycle;

        long long temp = cycle;
        int nums[9];
        memset(nums, 0, sizeof(nums));
        string ret;
        for(int i = 0; i < n; ++i)
        {
            if(ret.size() == n - 1)
            {
                for(int i = 0; i < 9; ++i)
                {
                    if(nums[i] == 0)
                    {
                        ret.push_back('0' + i + 1);
                        break;
                    }
                }
            }
            if(ret.size() == n)
                break;
            temp /= n - i;
            int j = 0;
            for(; j < n; ++j)
            {
                if(k - temp > 0)
                    k -= temp;
                else
                    break;
            }

            int k = 0;
            int index = -1;
            while(k <= j)
            {
                if(nums[index] == 0)
                {
                    index++;
                }
                else
                {
                    while(nums[index] == 1)
                        index++;
                }
                k++;
            }
            while(index <= n && nums[index - 1] == 1)
                        index++;
            nums[index - 1] = 1;
            ret += '0' + index;
        }

        return ret;
    }
};