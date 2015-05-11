class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.size();
        int l = 0;
        int r = len - 1;
        while(l < r)
        {
        	char c1, c2;
        	c1 = s[l];
        	c2 = s[r];

        	if(!isRight(c1))
        	{
        		l++;
        		continue;
        	}

        	if(!isRight(c2))
        	{
        		r--;
        		continue;
        	}

        	if(c1 != c2)
        		return false;

        	l++;
        	r--;
        }

        return true;
    }

    bool isRight(char &c)
    {
    	if(c >= '0' && c <= '9')
    		return true;
    	if(c >= 'a' && c <= 'z')
    		return true;
    	if(c >= 'A' && c <= 'Z')
    	{
    		c += 'a' - 'A';
    		return true;
    	}

    	return false;
    }
};