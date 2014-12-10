class Solution {
public:
	void nextPermutation(vector<int> &num) {
		if (num.empty())
			return;
		int len = num.size();
		int index = -1;
		for (int i = len - 2; i >= 0; --i)
		{
			if (num[i] < num[i + 1])
			{
				index = i;
				break;
			}
		}

		if (-1 == index)
		{
			sort(num.begin(), num.end());
			return;
		}

		for (int i = len - 1; i > index; --i)
		{
			if (num[i] > num[index])
			{
				swap(num[i], num[index]);
				break;
			}
		}

		sort(num.begin() + index + 1, num.end());
		
	}
};