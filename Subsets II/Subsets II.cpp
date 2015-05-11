class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int> > ret;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        dfs(nums, temp, 0, ret);

        return vector<vector<int>>(ret.begin(), ret.end());
    }

    void dfs(vector<int> &S, vector<int> &temp, int index, set<vector<int> > &ret)
    {
        if(index == S.size())
        {
            ret.insert(temp);
            return;
        }

        dfs(S, temp, index + 1, ret);
        temp.push_back(S[index]);
        dfs(S, temp, index + 1, ret);
        temp.pop_back();
    }
};