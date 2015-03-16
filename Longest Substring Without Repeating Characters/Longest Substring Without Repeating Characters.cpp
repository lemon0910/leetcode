class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int start = 0;
		int end = 0;
		int ret = 0;
		int index[300];
		memset(index, 0, sizeof(index));
		int len = s.size();
		for (int i = 0; i < len; ++i)
		{
			int pos = s[i];
			if (index[pos] == 0 || index[pos] < start)
			{
				index[pos] = i + 1;
			}
			else
			{
				int temp = i - start;
				ret = max(ret, temp);
				start = index[pos];
				index[pos] = i + 1;
			}
		}

		ret = max(ret, len - start);

		return ret;
	}
};