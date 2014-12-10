class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
    	if(strs.size() == 0)
    		return "";
        string ret;
        int len = strs.size();
        int flag = 0;
        for(int i = 0; i < strs[0].size(); ++i)
        {
        	char temp = strs[0][i];
        	for(int j = 1; j < len; ++j)
        	{
        		if(i >= strs[j].size() || strs[j][i] != temp)
        		{
        			flag = 1;
        			break;
        		}
        	}

        	if(flag)
        	{
        		break;
        	}
        	ret += temp;
        }

        return ret;
    }
};