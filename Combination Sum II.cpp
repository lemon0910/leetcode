class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<int> temp;
        vector<vector<int> > rst;
        sort(num.begin(), num.end());
        dfs(num, target, temp, rst, 0);
        return rst;
    }

    void dfs(vector<int> &num, int target, vector<int> &temp, vector<vector<int> > &rst, int pos)
    {
        if (target < 0)
            return;
        if (target == 0)
        {
            rst.push_back(temp);
            return;
        }

        for (int i = pos; i < num.size(); i++)
        {
            temp.push_back(num[i]);
            dfs(num, target - num[i], temp, rst, i + 1);
            temp.pop_back();
            while (i < num.size() - 1 && num[i] == num[i+1])
                i++;
        }
    }
};