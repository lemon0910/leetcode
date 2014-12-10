class Solution {
public:
	string convert(string s, int nRows) {
		int len = s.size();
		if (!len || nRows == 1)     //pay attention to nRows == 1
			return s;
		int level = 1;
		string ret;
		for (; level <= nRows; ++level)
		{
			int temp = level;
			while (temp -1 < len)
			{
				ret += s[temp - 1];
				if (level != 1 && level != nRows)
				{
					int index = temp + nRows - level + nRows - level;
					if (index - 1 < len)
						ret += s[index - 1];
				}
				temp += nRows + nRows - 2;
			}
		}

		return ret;
	}
};