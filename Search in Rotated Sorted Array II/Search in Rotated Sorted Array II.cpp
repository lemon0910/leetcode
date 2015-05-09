class Solution {
public:
    bool search(vector<int>& A, int target) {
        int n = A.size();
        if (0 >= n || A.empty())
            return false;

        int low = 0, high = n - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (A[mid] == target)
                return true;
            if (A[low] < A[mid])
            {
                if (A[low] <= target && target < A[mid])
                {
                    high = mid - 1;
                }
                else
                    low = mid + 1;
            }
            else if (A[low] > A[mid])
            {
                if (A[mid] <= target && target <= A[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
            else
                low++;
        }

        return false;
    }
};