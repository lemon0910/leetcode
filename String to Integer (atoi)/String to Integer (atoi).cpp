class Solution {
public:
    int atoi(string str) {
        long long num = 0;
        int sign = 1;
        const int n = str.size();

        int i = 0;
        while(str[i] == ' ' && i < n) 
            i++;

        if(str[i] == '+')
            i++;
        else if(str[i] == '-')
        {
            sign = -1;
            i++;
        }

        for(; i < n; ++i)
        {
            if(str[i] < '0' || str[i] > '9')
                break;

            num = num * 10 + str[i] - '0';
            if(num * sign > INT_MAX || num * sign < INT_MIN)
                return sign == -1 ? INT_MIN : INT_MAX;
        }

        return num * sign;
    }
};