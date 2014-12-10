class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> ret;
		int len = 1 << n;
		ret.reserve(len);

		for (int i = 0; i < len; ++i)
			ret.push_back(gray(i));

		return ret;
	}

	int gray(int n)
	{
		return n ^ (n >> 1);
	}
};