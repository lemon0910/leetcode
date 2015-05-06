class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int> > result;
        sort(candidates.begin(), candidates.end());
        vector<int> values;
        findResult(candidates, result, 0, values, 0, target);
        
        return vector<vector<int> >(result.begin(), result.end());
    }
    
    void findResult(vector<int>& candidates, set<vector<int> > &result, int index, vector<int> values, int sum, int target)
    {
        if(sum > target)
            return;
        if(sum == target)
        {
            result.insert(values);
            return;
        }
        if(index >= candidates.size())
            return;
        
        int cur = sum;
        vector<int> temp = values;
        findResult(candidates, result, index + 1, temp, cur, target);
        if(cur + candidates[index] <= target)
        {
            cur += candidates[index];
            temp.push_back(candidates[index]);
            findResult(candidates, result, index + 1, temp, cur, target);   
        }
    }
};
