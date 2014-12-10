class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.length() != s2.length())
            return false;

        int length = s1.length();
        bool f[length][length][length];
        memset(f, false, sizeof(bool) * length * length * length);
        
        for (int k = 1; k <= length; k++) 
        {
            for (int i = 0; i <= length - k; i++) 
            {
                for (int j = 0; j <= length - k; j++) 
                {
                    if (k == 1) 
                    {
                        f[i][j][k] = s1[i] == s2[j];
                    }
                    else 
                    {
                        for (int l = 1; l < k; l++) 
                        {
                            if ((f[i][j][l] && f[i + l][j + l][k - l]) || (f[i][j + k - l][l] && f[i + l][j][k - l])) 
                            {
                                f[i][j][k] = true;
                                break;
                            }                            
                        }
                    }
                }
            }            
        }
                
        return f[0][0][length];
    }
};