class Solution {
public:
    int reverse(int x) {
    	int flag = 1;
        if(x < 0)
        	flag = -1;

        int val = x * flag;
        int ret = 0;
        while(val)
        {
        	int temp = val % 10;
        	val /= 10;
        	ret = ret * 10 + temp;
        }

        ret *= flag;

        return ret;
    }
};