class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
        	return false;

        int val = x;
        long long ret = 0;
        while(val)
        {
        	int temp = val % 10;
        	val /= 10;
        	ret = ret * 10 + temp;
        }

        return ret == x;
    }
};