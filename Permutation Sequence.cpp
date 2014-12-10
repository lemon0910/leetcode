class Solution {
public:
	string getPermutation(int n, int k) {
		int pow[n + 1];
		pow[0] = 1, pow[1] = 1;
		for (int i = 2; i <= n; i++) {
			pow[i] = pow[i - 1] * i;
		}

		string ans;
		bool selected[n + 1];
		memset(selected, false, sizeof(bool)* (n + 1));
		for (int i = n; i >= 1; i--) {
			for (int j = n; j >= 1; j--) {
				if (!selected[j]) {
					int count = 0;
					for (int q = 1; q <= n; q++) {
						if (!selected[q] && q < j) {
							count++;
						}
					}
					if (pow[i - 1] * count < k) {
						k -= pow[i - 1] * count;
						ans += (char)(j + '0');
						selected[j] = true;
						break;
					}
				}
			}
		}

		return ans;
	}
};