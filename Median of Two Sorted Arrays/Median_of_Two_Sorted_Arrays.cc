class Solution {
public:
	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		int len = m + n;
		if (len % 2 != 0)
		{
			return findKth(A, m, B, n, (len + 1) / 2);
		}
		else
		{
			return 1.0 * (findKth(A, m, B, n, len / 2) +
				findKth(A, m, B, n, len / 2 + 1)) / 2;
		}
	}

private:
	int findKth(int A[], int m, int B[], int n, int k)
	{
		if (m > n)
			findKth(B, n, A, m, k);

		if(m == 0)
			return A[k - 1];
		if(n == 0)
			return B[k - 1];

		if (k == 1)
			return min(A[0], B[0]);
		
		if(m +n == k)
			return max(A[m - 1], B[n - 1]);

		int mid = min(k / 2, m);

		if(A[mid - 1] > B[n - mid - 1])
			return findKth(A, mid, B, n, k);
		else if(A[mid] == B[n - mid])
			return findKth(A, mid, B, n, k);
		else
			return findKth(A, m, B, n - mid, k);
	}
};