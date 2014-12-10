class Solution {
public:
    void reverseWords(string &s) {
        if(s.size() == 0)
        	return;
        string temp;
        for(int i = s.size() - 1; i >= 0; --i)
        {
        	if(' ' == s[i])
        		continue;
        	int j = i;
        	while(j - 1 >= 0 && s[j - 1] != ' ')
        		j--;
        	i = j;
        	for(; s[j] != ' ' && s[j] != '\0'; ++j)
        		temp += s[j];
        	temp += ' ';
        }

        if(temp.size() > 0)
        	temp.pop_back();
        s = temp;
    }
};