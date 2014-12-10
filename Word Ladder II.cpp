class Solution {
public:
	vector<vector<string> > findLadders(string start, string end, const unordered_set<string> &dict) {
		unordered_set<string> visited;
		unordered_map<string, vector<string> > father;
		unordered_set<string> current, next; 
		bool found = false;
		current.insert(start);

		while (!current.empty() && !found) 
		{

			for (auto word : current)
				visited.insert(word);
			for (auto word : current) 
			{
				for (size_t i = 0; i < word.size(); ++i) 
				{
					string new_word = word;
					for (char c = 'a'; c <= 'z'; ++c) 
					{
						if (c == new_word[i]) 
							continue;
						swap(c, new_word[i]);
						if (new_word == end)
							found = true;
						if (visited.count(new_word) == 0 && (dict.count(new_word) > 0 || new_word == end)) 
						{
							next.insert(new_word);
							father[new_word].push_back(word);
						}
						swap(c, new_word[i]);
					}
				}
			}

			current.clear();
			swap(current, next);
		}

		vector<vector<string> > result;
		if (found) 
		{
			vector<string> path;
			buildPath(father, path, start, end, result);
		}
		return result;
	}
private:
	void buildPath(unordered_map<string, vector<string> > &father,
					vector<string> &path, const string &start, const string &word,
					vector<vector<string> > &result) 
	{
		path.push_back(word);
		if (word == start) 
		{
			result.push_back(path);
			reverse(result.back().begin(), result.back().end());
		}
		else 
		{
			for (auto f : father[word]) 
			{
				buildPath(father, path, start, f, result);
			}
		}

		path.pop_back();
	}
};