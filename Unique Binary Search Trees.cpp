class Solution {
public:
    int numTrees(int n) {
        if(n == 0)
        	return 0;

        int ret = dfs(1, n);

        return ret;
    }

    int dfs(int start, int end)
    {
    	if(start > end)
    		return 1;
    	if(start == end)
    		return 1;

    	int ret = 0;
    	for(int i = start; i <= end; i++)
    	{
    		int left = dfs(start, i - 1);
    		int right = dfs(i + 1, end);

    		ret += left * right;
    	}

    	return ret;
    }
};