class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        if(num.size() < 4)
			return vector<vector<int> >();
		
		sort(num.begin(), num.end());
		
		map<int, vector<pair<int, int> > > cache;
		for(size_t a = 0; a < num.size(); ++a)
		{
			for(size_t b = a + 1; b < num.size(); ++b)
			{
				cache[num[a] + num[b]].push_back(pair<int, int>(a, b));
			}
		}
		set <vector<int> > result;
		for(size_t c = 2; c < num.size(); ++c)
		{
			for(size_t d = c + 1; d < num.size(); ++d)
			{	
				const int key = target - num[c] - num[d];
				if (cache.find(key) != cache.end()) 
				{
					for (size_t k = 0; k < cache[key].size(); ++k) 
					{
						if (c <= cache[key][k].second) 
							continue;
						result.insert(vector<int> { num[cache[key][k].first],
						num[cache[key][k].second], num[c], num[d] });
					}
				}
			}
		}
		return vector<vector<int> >(result.begin(), result.end());
	}
};