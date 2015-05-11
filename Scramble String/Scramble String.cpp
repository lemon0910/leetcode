class Solution {
public:
    bool isScramble(string s1, string s2) {
        return compareString(s1, s2);
    }

    bool compareString(string s1, string s2)
    {
        if(s1 == s2)
            return true;
        if(s1.size() != s2.size())
            return false;
        if(s1.size() == 2)
        {
            if(s1[0] == s2[1] && s1[1] == s2[0])
                return true;

            return false;
        }
        if(s1.size() <= 1)
            return false;

        int len = s1.size();

        for(int i = 1; i < len; ++i)
        {
            if(isValid(s1.substr(0, i), s2.substr(0, i)) &&
            isValid(s1.substr(i, len - i), s2.substr(i, len - i)))
            {
                if(compareString(s1.substr(0, i), s2.substr(0, i)) &&
                 compareString(s1.substr(i, len - i), s2.substr(i, len - i)))
                    return true;
            }
            if(isValid(s1.substr(0, i), s2.substr(len - i, i)) &&
            isValid(s1.substr(i, len - i), s2.substr(0, len - i)))
            {
                if(compareString(s1.substr(0, i), s2.substr(len - i, i)) &&
                 compareString(s1.substr(i, len - i), s2.substr(0, len - i)))
                    return true;
            }
        }

        return false;
    }

    bool isValid(string s1, string s2)
    {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        return s1 == s2;
    }
};