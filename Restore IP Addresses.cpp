class Solution {
public:
    void restoreUtil(string& s, int curIdx, vector<int>& curPath, vector<string>& allPath)
    {
        if(curPath.size() == 4 && curIdx == s.size())
        {
            string tmp = s;
            for(int i = curPath.size()-2; i >= 0; --i) tmp.insert(curPath[i]+1, 1, '.');
            allPath.push_back(tmp);
            return;
        }

        if(curPath.size() >= 4 || curIdx >= s.size()) return;
        
        int curNum = s[curIdx]-'0';
        int end = curIdx;
        do
        {
            curPath.push_back(end);
            restoreUtil(s, end+1, curPath, allPath);
            curPath.pop_back();
            end++;
            curNum = curNum*10+s[end]-'0';
        }while(end < s.size() && curNum <= 255 && s[curIdx] != '0');
    }

    vector<string> restoreIpAddresses(string s) 
    {
        vector<int> curPath;
        vector<string> allPath;
        restoreUtil(s, 0, curPath, allPath);
        return allPath;
    }
};