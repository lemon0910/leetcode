class Solution {
public:
	int removeDuplicates(int A[], int n) {
		if (n == 0)
			return 0;
		int i, k = 0;
		for (int i = 1; i < n; ++i)
		{
			if (A[i] != A[k])
			{
				A[++k] = A[i];
			}
		}

		return k + 1;
	}
};