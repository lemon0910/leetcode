class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        height.push_back(0);
        stack<int> s;
        int i = 0;
        int ans = 0;
        while(i < height.size())
        {
        	if(s.empty() || height[s.top()] <= height[i])
        	{
        		s.push(i++);
        	}
        	else
        	{
        		int front = s.top();
        		s.pop();
        		ans = max(ans, height[front] * (s.empty()? i : i - s.top() - 1));
        	}
        }

        return ans;
    }
};