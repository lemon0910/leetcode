class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0) return 0;

        vector<int> arr(s.size() + 2, 1);

        for (int i = s.size() - 1; i >= 0; --i)
        {
            if (s[i] == '0')
                arr[i] = 0;
            else
                arr[i] = arr[i + 1];

            if (i + 1 < s.size() && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')))
                arr[i] += arr[i + 2];
        }

        return arr[0];
    }
};