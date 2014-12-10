class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        int len = s.size();
        if(0 == len)
        	return false;

        for(int i = 0; i < len; ++i)
        {
        	char temp = s[i];
        	if(temp == '(' || temp == '{' || temp == '[')
        	{
        		st.push(temp);
        	}

        	if(temp == ')')
        	{
        		if(st.empty() || st.top() != '(')
        			return false;

        		st.pop();
        	}

        	if(temp == '}')
        	{
        		if(st.empty() || st.top() != '{')
        			return false;

        		st.pop();
        	}

        	if(temp == ']')
        	{
        		if(st.empty() || st.top() != '[')
        			return false;

        		st.pop();
        	}
        }

        if(st.empty())
        	return true;

        return false;
    }
};