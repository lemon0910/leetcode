class Solution {
public:
	int longestConsecutive(vector<int> &num) {
		unordered_map<int, bool> used;
		int ans = 0;

		for (int i = 0; i < num.size(); ++i)
			used[num[i]] = false;

		for (int i = 0; i < num.size(); ++i)
		{
			if (used[num[i]])
				continue;
			int len = 1;
			for (int j = num[i] + 1; used.find(j) != used.end(); j++)
			{
				used[j] = true;
				len++;
			}
			for (int j = num[i] - 1; used.find(j) != used.end(); j--)
			{
				used[j] = true;
				len++;
			}

			if (len > ans)
				ans = len;
		}

		return ans;
	}
};