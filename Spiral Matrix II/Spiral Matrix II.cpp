class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > matrix;
        if(n < 0)
            return matrix;
        int** m = new int*[n];
        for(int i = 0; i < n; i++)
        {
            m[i]= new int[n];
            memset(m[i], 0, sizeof(int) * n);
        }
        int currentnum = 1;
        int loop = 0;
        while(loop < (n + 1) / 2)
        {
            int tmp = n-1-loop;
            for(int i = loop; i <= tmp; i++)
                m[loop][i] = currentnum++;

            for(int i= loop+1; i <= tmp;i++)
                m[i][tmp] = currentnum++;

            for(int i = tmp-1; i >= loop; i--)
                m[tmp][i] = currentnum++;

            for(int i = tmp-1; i>= loop+1; i--)
                m[i][loop] = currentnum++;
            loop++;
        }
        for(int i = 0; i< n; i++)
        {
            vector<int> tmp;
            for(int j = 0; j < n; j++)
                tmp.push_back(m[i][j]);

            matrix.push_back(tmp);
        }
        for(int i = 0; i < n; i++)
            delete[] m[i];
        delete[] m;
        return matrix;
    }

};