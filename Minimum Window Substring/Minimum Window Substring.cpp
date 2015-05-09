class Solution {
public:
    string minWindow(string S, string T) {
        int nT = T.size();
        int nS = S.size();

        int needToFind[256] = {0};
        for (int i = 0; i < nT; ++i)
            ++needToFind[T[i]];
        int hasFound[256] = {0};
        int minBegin;
        int minEnd;
        int minWindow = nS + 1;
        int count = 0;

        char ch;
        for (int begin = 0, end = 0; end < nS; ++end)
        {
            if (needToFind[S[end]] == 0)
                continue;
            ch = S[end];
            ++hasFound[ch];
            if (hasFound[ch] <= needToFind[ch])
                ++count;

            if (count == nT)
            {
                while (needToFind[S[begin]] == 0
                || hasFound[S[begin]] > needToFind[S[begin]])
                {
                    if (hasFound[S[begin]] > needToFind[S[begin]])
                        --hasFound[S[begin]];
                    ++begin;
                }

                int length = end - begin + 1;
                if (length < minWindow)
                {
                    minBegin = begin;
                    minEnd = end;
                    minWindow = length;
                }
            }
        }

        return minWindow <= nS ? S.substr(minBegin, minEnd-minBegin+1) : "";
    }

};