class Solution {
public:
    void sortColors(int A[], int n) {
       if(n <= 1)
       		return;

       int start = 0, end = n  - 1;
       int current = start;

       while(current <= end)
       {
       		if(A[current] == 0)
       		{
       			if(current == start)
       			{
       				current++;
       				start++;
       			}
       			else
       				swap(A[start++], A[current]);
       		}
       		else if(A[current] == 2)
       		{
       			if(current == end)
       			{
       				return;
       			}
       			else
       			{
       				swap(A[end--], A[current]);
       			}
       		}
       		else
       			current++;
       }
    }
};