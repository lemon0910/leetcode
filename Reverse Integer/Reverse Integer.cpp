class Solution {
public:
    int reverse(int x) {
    	int flag = 1;
        if(x < 0)
        	flag = -1;

        int val = x * flag;
        long long ret = 0;
        while(val)
        {
        	int temp = val % 10;
        	val /= 10;
        	ret = ret * 10 + temp;
        }

        ret *= flag;

        if(ret > INT_MAX || ret < INT_MIN)
            ret = 0;

        return ret;
    }
};