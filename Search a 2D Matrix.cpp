class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if(matrix.empty())
        	return false;

        int start = 0, end = matrix.size() - 1;
        while(start <= end)
        {
        	int mid = (start + end) / 2;
        	if(matrix[mid][0] == target)
        		return true;
        	else if(matrix[mid][0] > target)
        		end = mid - 1;
        	else
        		start = mid + 1;
        }

        if(end < 0)
        	return false;

        int l = 0, r = matrix[end].size() - 1;
        while(l <= r)
        {
        	int mid = (l + r) / 2;
        	if(matrix[end][mid] == target)
        		return true;
        	else if(matrix[end][mid] > target)
        		r = mid - 1;
        	else
        		l = mid + 1;
        }

        return false;
    }
};