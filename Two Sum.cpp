struct SLItem
{
	int index;
	int value;
	SLItem(){}
	SLItem(int v, int idx) : value(v), index(idx){}

	bool operator<(const SLItem &item) const
	{
		return value < item.value;
	}
};

class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		vector<SLItem> temp;
		for (int i = 0; i < numbers.size(); ++i)
		{
			temp.push_back(SLItem(numbers[i], i + 1));
		}

		sort(temp.begin(), temp.end());
		int l = 0;
		int r = temp.size() - 1;
		while (l < r)
		{
			if (target == temp[l].value + temp[r].value)
			{
				vector<int> ret;
				int minIndex = min(temp[l].index, temp[r].index);
				int maxIndex = max(temp[l].index, temp[r].index);
				ret.push_back(minIndex);
				ret.push_back(maxIndex);
				return ret;
			}
			else if (target < temp[l].value + temp[r].value)
				r--;
			else
				l++;
		}
	}
};