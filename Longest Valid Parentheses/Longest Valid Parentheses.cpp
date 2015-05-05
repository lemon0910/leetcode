class Solution {
public:
    struct node
    {
        int x;
        int y;
        node(int a, int b)
        {
            x = a;
            y = b;
        }
    };
    int longestValidParentheses(string s) {
        stack<int> index;
        stack<char> ch;
        deque<node> result;
        int ret = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == ')')
            {
                if(ch.empty())
                {
                    continue;
                }
                else
                {
                    node temp(index.top(), i);
                    int k = result.size() - 1;
                    while(k >= 0 && result[k].x > temp.x && result[k].y < temp.y)
                    {
                        k--;
                        result.pop_back();
                    }
                    result.push_back(temp);
                    ch.pop();
                    index.pop();
                }
            }
            else
            {
                ch.push(s[i]);
                index.push(i);
            }
        }
        
        for(int i = 0; i < result.size(); )
        {
            int left = result[i].x;
            int right = result[i].y;
            int low = i;
            int fast = i + 1;
            while(fast < result.size() && (result[fast].x - result[low].y == 1))
            {
                fast++;
                low++;
            }
            
            right = result[fast - 1].y;
            ret = max(ret, right - left + 1);
            i = fast;
        }

        return ret;
    }
};
