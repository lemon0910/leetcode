class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int l = distance(A, lower_bound(A, A + n, target));
        int r = distance(A, prev(upper_bound(A, A + n, target)));

        if(A[l] != target)
        {
        	return vector<int> {-1, -1};
        }
        else
        	return vector<int>{l, r};
    }
};