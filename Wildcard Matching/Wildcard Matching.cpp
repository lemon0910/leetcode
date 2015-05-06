class Solution {
public:
    bool isMatch(string s, string p) {
        bool star = false;
        int i, j, k, l;
        i = j = k = l = 0;
        for (; k < s.size(); k++, l++) {
            switch (p[l]) {
                case '?':
                    break;
                case '*':
                    star = true;
                    i = k;
                    j = l;
                    while (p[j] == '*') j++; //skip continuous '*'
                    if (j == p.size()) return true;
                    k = i - 1;
                    l = j - 1;
                    break;
                default:
                    if (s[k] != p[l]) 
                    {
                        if (!star) return false;
                        i++;
                        k = i - 1;
                        l = j - 1;
                    }
            }
        }
        while (l < p.size() && p[l] == '*') l++;
        return (l == p.size());
    }
};
