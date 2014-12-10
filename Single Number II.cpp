class Solution {
public:
	int singleNumber(int A[], int n) {
		int len = sizeof(int) * 8;
		int num[len];
		memset(num, 0, sizeof(num));

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < len; ++j)
			{
				num[j] += (A[i] >> j) & 1;
				num[j] %= 3;
			}
		}

		int result = 0;
		for (int i = 0; i < len; ++i)
			result += num[i] << i;

		return result;
	}
};