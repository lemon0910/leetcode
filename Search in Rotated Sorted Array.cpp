class Solution {
public:
	int search(int A[], int n, int target) 
	{
		if (0 >= n || A == NULL)
			return -1;

		int low, high, mid;
		low = 0;
		high = n - 1;
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (A[mid] == target)
				return mid;

			if (A[low] <= A[high])
			{
				if (A[mid] > target)
					high = mid - 1;
				else
					low = mid + 1;
			}
			else
			{
				//未考虑这种情况，一直出错
				if (A[mid] == A[low])
					low = mid + 1;
				else if (A[mid] > A[low])
				{
					if (target > A[mid])
						low = mid + 1;
					else if (target >= A[low])
						high = mid - 1;
					else
						low = mid + 1;
				}
				else
				{
					if (target < A[mid])
						high = mid - 1;
					else if (target <= A[high])
						low = mid + 1;
					else
						high = mid - 1;
				}

			}
		}

		return -1;
	}
};