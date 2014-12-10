class Solution {
public:
	int evalRPN(vector<string> &tokens) {
		if (tokens.size() == 0)
			return 0;
		stack<int> num;

		for (int i = 0; i < tokens.size(); ++i)
		{
			string ch = tokens[i];
			if (ch == "+")
			{
				int num1 = num.top();
				num.pop();
				int num2 = num.top();
				num.pop();
				int result = num2 + num1;
				num.push(result);
			}
			else if (ch == "-")
			{
				int num1 = num.top();
				num.pop();
				int num2 = num.top();
				num.pop();
				int result = num2 - num1;
				num.push(result);
			}
			else if (ch == "*")
			{
				int num1 = num.top();
				num.pop();
				int num2 = num.top();
				num.pop();
				int result = num2 * num1;
				num.push(result);
			}
			else if (ch == "/")
			{
				int num1 = num.top();
				num.pop();
				int num2 = num.top();
				num.pop();
				int result = num2 / num1;
				num.push(result);
			}
			else
				num.push(getnum(ch));
		}

		return num.top();
	}

	int getnum(string s)
	{
		int flag = 1, i = 0;
		if(s[0] == '-')
		{
			flag = -1;
			i++;
		}
		int ret = 0;
		for (; i < s.size(); ++i)
		{
			ret = ret * 10 + s[i] - '0';
		}

		return ret * flag;
	}
};