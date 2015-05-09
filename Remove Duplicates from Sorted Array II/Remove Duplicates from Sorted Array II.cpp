class Solution {
public:
    int removeDuplicates(vector<int>& A) {
        int n = A.size();
        if (0 == n)
            return 0;
        int index = 0;
        int flag = 0;
        for (int i = 1; i < n; ++i)
        {
            if (A[index] == A[i] && !flag)
            {
                flag++;
                A[++index] = A[i];
            }
            else if (A[index] != A[i])
            {
                flag = 0;
                A[++index] = A[i];
            }
        }

        return index + 1;
    }
};