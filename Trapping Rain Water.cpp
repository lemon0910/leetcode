class Solution {
public:
	int trap(int A[], int n) {
		if (0 == n)
			return 0;
		vector<int> lmax, rmax;
		int tempmax = A[0];
		for (int i = 1; i < n - 1; ++i)
		{
			tempmax = max(tempmax, A[i]);
			lmax.push_back(tempmax);
		}

		tempmax = A[n - 1];
		for (int i = n - 2; i > 0; --i)
		{
			tempmax = max(tempmax, A[i]);
			rmax.push_back(tempmax);
		}

		int ret = 0;
		for (int i = 1; i < n - 1; ++i)
		{
			int temp = min(lmax[i - 1], rmax[n - 2 - i]);
			ret += temp - A[i];
		}

		return ret;
	}
};