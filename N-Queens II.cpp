class Solution {
public:
    void solveNQueensUtil(int n, int curRow, int upc, int ld, int rd, int& totalCnt)
    {
        if(curRow == n)
        {
            totalCnt++;
            return;
        }
        
        for(int j = 0; j < n; ++j)
        {
            int curNum = 1<<j;
            if(curNum & (ld | rd | upc)) continue;
            solveNQueensUtil(n, curRow+1, upc|curNum, (ld|curNum)>>1, (rd|curNum)<<1, totalCnt);
        }
    }
    int totalNQueens(int n) {
        int totalCnt = 0;
        solveNQueensUtil(n, 0, 0, 0, 0, totalCnt);
        return totalCnt;
    }
};