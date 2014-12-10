class Solution {
public:
	int candy(vector<int> &ratings) {
		int len = ratings.size();
		if (!len)
			return 0;

		int num = 1;
		vector<int> increment(len);

		for (int i = 1; i < len; ++i)
		{
			if (ratings[i] > ratings[i - 1])
				increment[i] = num++;
			else
				num = 1;
		}

		num = 1;
		for (int i = len - 2; i >= 0; --i)
		{
			if (ratings[i] > ratings[i + 1])
				increment[i] = max(increment[i], num++);
			else
				num = 1;
		}

		int result = len;
		for (int i = 0; i < len; ++i)
		{
			result += increment[i];
		}

		return result;
	}
};