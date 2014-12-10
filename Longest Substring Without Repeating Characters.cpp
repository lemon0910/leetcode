class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int len = s.size();
		if (!len)
			return 0;

		map<char, int> m;
		int ret = 0;
		int temp = 0;
		int start = 0;

		for (int i = 0; i < len; ++i)
		{
			char ch = s[i];
			if (m.end() == m.find(ch) || -1 == m[ch])
			{
				temp++;
				m[ch] = i;
			}
			else
			{
				int end = m[ch] + 1;
				for (int j = start; j < end; ++j)
					m[s[j]] = -1;

				m[ch] = i;
				ret = max(ret, temp);
				temp -= end - start - 1;
				start = end;
			}
		}

		return max(ret, temp);
	}
};