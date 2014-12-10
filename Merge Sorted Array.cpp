class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int l = m - 1;
        int r = n - 1;
        int index = m + n - 1;
        while(l >= 0 && r >= 0)
        	A[index--] = A[l] > B[r] ? A[l--] : B[r--];

        while(r >= 0)
        	A[index--] = B[r--];
    }
};