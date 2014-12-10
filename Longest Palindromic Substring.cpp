class Solution {
public:
    string longestPalindrome(string s) {
    	if(0 == s.size())
    		return "";
        int len = s.size();
        //vector<vector<int> > f(len, vector<int>(len, 0));
        //string ret = s[0];
        bool f[len][len];
        fill_n(&f[0][0], len * len, false);
        string ret;
        ret += s[0];

        for(int i = 0; i < len; ++i)
        	f[i][i] = true;
        for(int i = 1; i < len; ++i)
        {
        	if(s[i - 1] == s[i])
        	{
        		f[i - 1][i] = true;
        		if(ret.size() < 2)
        			ret = s.substr(i - 1, 2); 
        	}
        }

        for(int k = 3; k <= len; ++k)
        {
        	for(int i = 0; i + k - 1 < len; ++i)
        	{
        		if(f[i + 1][i + k - 2] && s[i] == s[i + k - 1])
        		{
        			f[i][i + k - 1] = true;
        			if(ret.size() < k)
        				ret = s.substr(i, k);
        		}
        	}
        }

        return ret;
    }
};