class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > ret;
        vector<int> temp;
        sort(S.begin(), S.end());
        dfs(S, temp, 0, ret);

        return ret;
    }

    void dfs(vector<int> &S, vector<int> &temp, int index, vector<vector<int> > &ret)
    {
        if(index == S.size())
        {
            ret.push_back(temp);
            return;
        }

        dfs(S, temp, index + 1, ret);
        temp.push_back(S[index]);
        dfs(S, temp, index + 1, ret);
        temp.pop_back();
    }
};