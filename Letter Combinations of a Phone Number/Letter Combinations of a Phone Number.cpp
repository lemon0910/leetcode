class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        if(digits.empty())
        {
            return ret;
        }
        map<char, string> m;
        m['0'] = " ";
        m['1'] = "";
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";

        find_str(digits, 0, "", m, ret);
        return ret;
    }

    void find_str(string digits, int step, string ans,  map<char, string> &m, vector<string> &ret)
    {
        if(step >= digits.size())
        {
            ret.push_back(ans);
            return;
        }

        string temp = m[digits[step]];
        for(int i = 0; i < temp.size(); ++i)
        {
            string next = ans + temp[i];
            find_str(digits, step + 1, next, m, ret);
        }
    }
};
