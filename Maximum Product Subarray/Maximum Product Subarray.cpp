class Solution {
public:
    int maxProduct(int A[], int n) {
        if(0 == n)
            return 0;

        int maxn = A[0];
        int minn = A[0];
        int ret = A[0];

        for(int i = 1; i < n; i++)
        {
            int tempmax = max(max(maxn * A[i], minn * A[i]), A[i]);
            int tempmin = min(min(maxn * A[i], minn * A[i]), A[i]);

            maxn = tempmax;
            minn = tempmin;
            ret = max(maxn, ret);
        }

        return ret;
    }
};
