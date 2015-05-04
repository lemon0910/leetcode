class Solution {
public:
    vector<string> generateParenthesis(int n) {
        set<string> ret;
        generate("", n, 0, 0, ret);
        return vector<string>(ret.begin(), ret.end());
    }

    void generate(string value, int n, int left, int right, set<string>& ret)
    {
        if(left == n && right == n)
        {
            ret.insert(value);
        }

        if(left < n)
            generate(value + '(', n, left + 1, right, ret);
        if(right < n && left > right)
            generate(value + ')', n, left, right + 1, ret);
    }
};
