class Solution {
public:
    void reverseWords(string &s) {
        int len = s.size();
        if(0 == len)
            return;

        string ret;
        for(int i = len - 1; i >= 0; )
        {
            while(i >= 0 &&s[i] == ' ')
                i--;
            
            if(i == -1)
                break;
                
            while(i != -1 && s[i] != ' ')
                i--;
            int start = i + 1;
            while(s[start] != '\0' && s[start] != ' ')
                ret += s[start++];

            ret += ' ';
        }

        if(ret.size() > 0)
            ret.pop_back();
        
        s = ret;
    }
};
