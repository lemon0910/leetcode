class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        string temp(digits.size(), ' ');
        dfs(digits, 0, temp, ret);
        return ret;
    }
     
    void dfs(const string &digits, int index, string &temp, vector<string>&ret)
    {
        string numap[] = {" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        if(index == digits.size())
        {
            ret.push_back(temp);
            return;
        }
        for(int i = 0; i < numap[digits[index] - '0'].size(); i++)
        {
            temp[index] = numap[digits[index] - '0'][i];
            dfs(digits, index+1, temp, ret);
        }
    }
};