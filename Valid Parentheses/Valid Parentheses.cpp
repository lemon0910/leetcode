class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        map<char, char> m;
        m[')'] = '(';
        m[']'] = '[';
        m['}'] = '{';
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == ')' || s[i] == ']' || s[i] == '}')
            {
                if(st.empty())
                {
                    return false;
                }
                else
                {
                    if(st.top() != m[s[i]])
                    {
                        return false;
                    }
                    else
                    {
                        st.pop();
                    }
                }
            }
            else
            {
                st.push(s[i]);
            }
        }

        if(st.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
