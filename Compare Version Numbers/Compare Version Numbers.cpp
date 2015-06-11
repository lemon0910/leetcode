class Solution {
public:
    vector<int> getVersion(string version)
    {
        vector<int> ret;
        int num = 0;
        for(int i = 0; i < version.size(); ++i)
        {
            if(version[i] == '.')
            {
                ret.push_back(num);
                num = 0;
                continue;
            }

            num = num * 10 + version[i] - '0';
        }

        ret.push_back(num);

        return ret;
    }

    int compareVersion(string version1, string version2)
    {
        vector<int> ret1 = getVersion(version1);
        vector<int> ret2 = getVersion(version2);

        int m, n;
        m = n = 0;

        for(;m < ret1.size() && n < ret2.size(); m++, n++)
        {
            if(ret1[m] > ret2[n])
            {
                return 1;
            }
            if(ret1[m] < ret2[n])
            {
                return -1;
            }
        }

        for(; m < ret1.size(); m++)
        {
            if(ret1[m] != 0)
                return 1;
        }
        for(; n < ret2.size(); n++)
        {
            if(ret2[n] != 0)
                return -1;
        }

        return 0;
    }
};