class Solution {
public:
    int numDistinct(string S, string T) {
        int lenS = S.length(), lenT = T.length();
        if (lenS < lenT)
            return 0;

        int f[lenS + 1][lenT + 1];
        memset(f, 0, sizeof(int) * (lenS + 1) * (lenT + 1));
        for (int i = 0; i<= lenS; i++)
            f[i][0] = 1;
  
        for (int i = 1; i <= lenS; i++) 
        {
            for (int j = 1; j <= i && j <= lenT; j++) 
            {
                f[i][j] = S[i - 1] == T[j - 1] ? f[i - 1][j - 1] : 0;
                if (i - 1 >= j) 
                    f[i][j] += f[i - 1][j];
            }
        }
        
        return f[lenS][lenT];
    }
};