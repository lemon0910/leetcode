class Solution {
public:
	int threeSumClosest(vector<int> &num, int target) {
		int result = 0;
		int min_gap = -1;

		sort(num.begin(), num.end());

		for (auto a = num.begin(); a != prev(num.end(), 2);
			a = upper_bound(a, prev(num.end(), 2), *a))
		{
			auto b = next(a);
			auto c = prev(num.end());

			while (b < c)
			{
				const int sum = *a + *b + *c;
				const int gap = abs(sum - target);

				if (gap < min_gap || min_gap == -1)
				{
					result = sum;
					min_gap = gap;
				}

				if (sum < target)
					b++;
				else
					c--;
			}
		}

		return result;
	}
};