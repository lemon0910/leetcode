class Solution {
public:
    int maxArea(vector<int> &height) {
        int size = height.size();
    	int left = 0, right = size-1;
		int max = 0;
		while(left < right)
		{
			int minheight = min(height[left], height[right]);
			int tmp = minheight * (right - left);
			max = max > tmp ? max : tmp;
			if(height[left] < height[right])
				left++;
			else right--;
		}
		return max;
    }
};