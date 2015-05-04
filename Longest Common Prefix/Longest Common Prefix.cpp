class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix;
        if(strs.empty())
            return prefix;
        for(unsigned int i = 0; i < strs[0].size(); ++i)
        {
            char ch = strs[0][i];
            bool flag = true;
            for(unsigned int j = 1; j < strs.size(); ++j)
            {
                if(i >= strs[j].size() || ch != strs[j][i])
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
                prefix += ch;
            else
                break;
        }

        return prefix;
    }
};
