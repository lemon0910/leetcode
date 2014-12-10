class Solution {
public:
    bool isNumber(const char *s) {
        char *ptr;
        strtod(s, &ptr);

        if(ptr == s)
        	return false;

        for(; *ptr; ++ptr)
        	if(!isspace(*ptr))
        		return false;

        return true;
    }
};