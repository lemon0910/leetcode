class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> t;
        int len = tokens.size();
        if(0 == len)
            return 0;
            
        for(int i = 0; i < len; ++i)
        {
            string s = tokens[i];
            if(isNum(s))
            {
                int temp = getNum(s);
                t.push(temp);
            }
            else
            {
                int temp;
                int num1 = t.top();
                t.pop();
                int num2 = t.top();
                t.pop();
                switch(s[0])
                {
                    case '+':
                        temp = num1 + num2;
                        break;
                     case '-':
                        temp = num2 - num1;
                        break;
                     case '*':
                        temp = num1 * num2;
                        break;
                     case '/':
                        temp = num2 / num1;
                        break;
                }
                t.push(temp);
            }
        }
        
        return t.top();
    }
    
private:
    int getNum(string s)
    {
        int ret = 0;
        int flag = 1;
        int i = 0;
        if(s[0] == '-')
        {
            flag = -1;
            i++;
        }
        for(; i < s.size(); i++)
        {
            ret = ret * 10 + s[i] - '0';
        }
        
        return flag * ret;
    }
    bool isNum(string s)
    {
        if((s[0] == '-' && s.size() > 1) || (s[0] >= '0' && s[0] <= '9'))
            return true;
            
        return false;
    }
};
