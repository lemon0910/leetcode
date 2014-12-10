/*
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        int n = strlen(s);
        int m = strlen(p);
        if(n == 0 || m == 0)
        	return false;

        bool f[n][m];
        fill_n(&f[0][0], n * m, false);

        if(s[0] == p[0] || s[0] == '.' || p[0] == '.')
        	f[0][0] = true;

        for(int i = 1; i < n; ++i)
        {
        	for(int j = 1; j < m; ++j)
        	{
        		if(!f[i - 1][j - 1])
        			break;

        		if(s[i] == p[j] || s[i] == '.' || p[j] == '.')
        			f[i][j] = true;

        		if(!f[i][j] && s[i] == '*')
        		{
        			if(s[i - 1] == '.')
        				f[i][j] = true;
        			else
        			{
        				int temp = i - 1;
        				while(temp > 0 && s[temp] == '*') temp--;
        				if(s[temp] == p[j])
        					f[i][j] = true;
        			}
        		}

        		if(!f[i][j] && p[j] == '*')
        		{
        			if(p[j - 1] == '.')
        				f[i][j] = true;
        			else
        			{
        				int temp = j - 1;
        				while(temp > 0 && p[temp] == '*') temp--;
        				if(p[temp] == s[i])
        					f[i][j] = true;
        			}
        		}

        		if(!f[i][j])
        			break;
        	}
        }

        return f[n - 1][m - 1];
    }
};
*/

class Solution{
public:
	bool isMatch(const char *s, const char *p){
		if(*p == '\0')
			return *s == '\0';

		if(*(p + 1) != '*')
		{
			if(*p == *s || (*p == '.' && *s != '\0'))
				return isMatch(s + 1, p + 1);
			else
				return false;
		}
		else
		{
			while(*p == *s || (*p == '.' && *s != '\0'))
			{
				if(isMatch(s, p + 2))
					return true;
				s++;
			}

			return isMatch(s, p + 2);
		}
	}
};