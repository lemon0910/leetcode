class Solution {
public:
    int trap(vector<int>& height) {
        int start = 0;
        int area = 0;
        while(start < height.size() && height[start] == 0)
            start++;
            
        for(; start < height.size(); )
        {
            int maxn = 0;
            int index = -1;
            int end = start + 1;
            for(; end < height.size(); ++end)
            {
                if(height[end] >= height[start])
                    break;
                if(height[end] > maxn)
                {
                    maxn = height[end];
                    index = end;
                }
            }
            
            if(end < height.size())
            {
                int h = min(height[start], height[end]);
                for(int j = start; j <= end; ++j)
                {
                    if(height[j] < h)
                    {
                        area += h - height[j];
                    }
                }
                start = end;
            }
            else
            {
                if(index != -1)
                {
                    int h = min(height[start], height[index]);
                    for(int j = start; j <= index; ++j)
                    {
                        if(height[j] < h)
                        {
                            area += h - height[j];
                        }
                    }
                    start = index;
                }
                else
                {
                    break;
                }
            }
        }
        
        return area;
    }
};
