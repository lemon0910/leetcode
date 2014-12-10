class Solution {
public:
    char *strStr(char *haystack, char *needle) {
    	if(!*needle)
    		return haystack;
        int len1 = strlen(haystack);
        int len2 = strlen(needle);

        int flag;

        for(int i = 0; i < len1; ++i)
        {
        	flag = 0;
        	if(len1 - i >= len2)
        	{
        		for(int j = 0, k = i; j < len2; ++j, ++k)
        		{
        			if(haystack[k] != needle[j])
        			{
        				flag = 1;
        				break;
        			}
        		}

        		if(flag)
        			continue;

        		return haystack + i;
        	}
        }

        return NULL;
    }
};