class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.size();
        if(len<2)
        {
            return 0;
        }
        else
        {
            stack<int> leftPart;
            
            bool* parentheses = new bool[len];
            for(int i=0;i<len;i++)
            {
                parentheses[i] = false;
            }
            
            for(int i=0;i<len;i++)
            {
                if(s[i]=='(')
                {
                    leftPart.push(i);
                }
                else if(!leftPart.empty())
                {
                    int index = leftPart.top();
                    leftPart.pop();
                    parentheses[index] = true;
                    parentheses[i] = true;
                }
            }
            
            int max=0;
            int count=0;
            for(int i=0;i<len;i++)
            {
                if(parentheses[i])
                {
                    count++;
                }
                else
                {
                    if(count>max)
                    {
                        max=count;
                    }
                    count=0;
                }
            }
            if(count>max)
            {
                max=count;
            }
            return max;
        }
        
    }
};