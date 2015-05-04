class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> > ret;
        for(auto iti = num.begin(); iti != num.end(); iti = upper_bound(num.begin(), num.end(), *iti))
        {
            int sum = *iti;
            for(auto itj = iti + 1; itj != num.end(); itj = upper_bound(itj + 1, num.end(), *itj))
            {
                sum = *iti + *itj;
                int target = -1 *sum;
                auto itk = lower_bound(itj + 1, num.end(), target);
                if(itk != num.end() && *itk == target)
                {
                    vector<int> temp;
                    temp.push_back(*iti);
                    temp.push_back(*itj);
                    temp.push_back(target);
                    ret.push_back(temp);
                }
            }
        }

        return ret;
    }
};
