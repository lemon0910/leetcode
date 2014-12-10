class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > ret;
        vector<int> path;
        dfs(1, path, ret, n, k);

        return ret;
    }

    void dfs(int index, vector<int> &path, vector<vector<int> > &ret, int n, int k)
    {
    	if(path.size() == k)
    	{
    		ret.push_back(path);
    		return;
    	}
    	if(index > n)
    	{
    		if(path.size() == k)
    			ret.push_back(path);

    		return;
    	}

    	dfs(index + 1, path, ret, n, k);
    	path.push_back(index);
    	dfs(index + 1, path, ret, n, k);
    	path.pop_back();
    }
};