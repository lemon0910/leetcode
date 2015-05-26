class Solution {
public:
    int candy(vector<int> &ratings)
    {
        vector<int> candyNum(ratings.size());

        for(int i = 0; i < ratings.size(); i++)
            candyNum[i] = 1;

        for(int i = 1; i < ratings.size(); i++)
            if(ratings[i] > ratings[i-1])
                candyNum[i] = candyNum[i-1] + 1;

        for(int i = ratings.size()-2; i>=0; i--)
            if(ratings[i] > ratings[i+1] && candyNum[i] <= candyNum[i+1])
                candyNum[i] = candyNum[i+1] + 1;

        int result = 0;
        for(int i = 0; i < ratings.size(); i++)
            result += candyNum[i];

        return result;
    }
};