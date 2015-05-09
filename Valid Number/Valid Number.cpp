class Solution {
public:
    bool isNumber(string s) {
        char *ptr;
        strtod(s.c_str(), &ptr);

        if(ptr == s.c_str())
        	return false;

        for(; *ptr; ++ptr)
        	if(!isspace(*ptr))
        		return false;

        return true;
    }
};