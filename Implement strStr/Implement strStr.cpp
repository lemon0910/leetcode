class Solution {
public:
    int strStr(string haystack, string needle) {
        int index = -1;
        for(int i = 0; i < haystack.size(); ++i)
        {
            if(haystack.size() - i < needle.size())
                break;

            int j = 0;
            while(j < needle.size() && haystack[i + j] == needle[j])
                j++;
            if(j == needle.size())
            {
                index = i;
                return index;
            }
        }

        return index;
    }
};
