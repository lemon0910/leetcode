class Solution {
public:
    string multiply(string num1, string num2) {
        string s(num1.size() + num2.size(), '0');
        
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        for(int i = 0; i < num1.size(); i++)
        {
            int flag = 0;
            for(int j = 0; j < num2.size(); j++)
            {
                int digit = s[i+j] - '0';
                int num = (num1[i] - '0') * (num2[j] - '0');
                int res = digit + num + flag;
                s[i+j] = (res % 10) + '0';
                flag = res / 10;
            }
            int index = i + num2.size();
            while(flag)
            {
                int digit = s[index] - '0';
                int res = digit + flag;
                s[index] = (res % 10) + '0';
                flag = res / 10;
            }
        }
        
        while(true)
        {
            if (s[s.size()-1] == '0' && s.size() > 1)
                s.erase(s.size() - 1, 1);
            else
                break;
        }
        
        reverse(s.begin(), s.end());
        
        return s;
    }
};
