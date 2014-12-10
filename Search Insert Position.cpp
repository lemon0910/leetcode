class Solution {
public:
    int searchInsert(int A[], int n, int target) {
    	if(0 == n)
    		return 0;

        int start = 0;
        int end = n - 1;
        while(start <= end)
        {
        	int mid = (start + end) / 2;
        	if(A[mid] == target)
        		return mid;
        	else if(A[mid] > target)
        		end = mid - 1;
        	else
        		start = mid + 1;
        }

        return start;
    }
};