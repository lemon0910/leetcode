class Solution {
public:
    int divide(int dividend, int divisor) {
        long long a = (dividend >= 0)? dividend : -(long long)dividend;
        long long b = (divisor >= 0)? divisor : -(long long)divisor;

        long long result = 0;
        while(a >= b)
        {
            long long c = b;
            for(int i = 0; a >=c; i++, c <<= 1)
            {
                a -= c;
                result += 1 << i;
            }
        }
        long long ret;
        ((dividend ^ divisor) >> 31)?(ret = -result) : ret = result;
        if(ret > INT_MAX)
            ret = INT_MAX;
        if(ret < INT_MIN)
            ret = INT_MIN;

        return ret;
    }
};
