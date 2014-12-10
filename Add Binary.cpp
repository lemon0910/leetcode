class Solution {
public:
    string addBinary(string a, string b) {
        int len1 = a.size();
        int len2 = b.size();

        string l = change(a);
        string r = change(b);

        int carry = 0;
        string ret;
        int i, j;

        for(i = 0, j = 0; i < len1 && j < len2; ++i, ++j)
        {
        	int num1 = l[i] - '0';
        	int num2 = r[j] - '0';
        	int sum = num1 + num2 + carry;
        	carry = sum / 2;
        	ret += sum % 2 + '0';
        }

        while(i < len1)
        {
        	int num1 = l[i] - '0';
        	int sum = num1 + carry;
        	carry = sum / 2;
        	ret += sum % 2 + '0';
        	i++;
        }
        while(j < len2)
        {
        	int num2 = r[j] - '0';
        	int sum = num2 + carry;
        	carry = sum / 2;
        	ret += sum % 2 + '0';
        	j++;
        }

        if(carry)
        	ret += '1';

        return change(ret);

    }

    string change(string s)
    {
    	int len = s.size();
    	string ret;
    	for(int i = len - 1; i >= 0; --i)
    	{
    		ret += s[i];
    	}

    	return ret;
    }
};