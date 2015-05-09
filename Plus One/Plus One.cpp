class Solution {
public:
	vector<int> plusOne(vector<int> &digits) {
		int len = digits.size();
		int carry = 1;
		for (int i = len - 1; i >= 0; --i)
		{
			digits[i] += carry;
			carry = digits[i] / 10;
			digits[i] %= 10;
		}

		if (carry > 0)
			digits.insert(digits.begin(), carry);

		return digits;
	}
};