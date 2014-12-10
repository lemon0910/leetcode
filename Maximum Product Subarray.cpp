class Solution {
public:
    int maxProduct(int A[], int n) {
        int maxn = A[0];
        int minn = A[0];
        
        int ret = A[0];
        
        for(int i = 1; i < n; ++i)
        {
            int tempMax = maxn * A[i];
            int tempMin = minn * A[i];
            
            maxn = max(max(tempMax, tempMin), A[i]);
            minn = min(min(tempMax, tempMin), A[i]);
            ret = max(maxn, ret);
        }
        
        return ret;
    }
};
