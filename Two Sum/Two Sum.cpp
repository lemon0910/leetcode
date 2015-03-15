class Solution {
public:
    struct Node
    {
        int value;
        int index;
    };

    struct {
        bool operator()(Node a, Node b)
        {
            return a.value < b.value;
        }
    } customLess;

    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<Node> node;
        int len = numbers.size();
        for (int i = 0; i < len; ++i)
        {
            Node t;
            t.value = numbers[i];
            t.index = i + 1;
            node.push_back(t);
        }
        sort(node.begin(), node.end(), customLess);
    
        vector<int> ans;
        for (int i = 0; i < len; ++i)
        {
            if (i > 0 && node[i].value == node[i - 1].value)
                continue;
            int value = target - node[i].value;
            int ret = -1;
            int l = i + 1, r = len - 1;
            while (l <= r)
            {
                int mid = (l + r) / 2;
                if (node[mid].value == value)
                {
                    ret = mid;
                    break;
                }
                else if (node[mid].value > value)
                    r = mid - 1;
                else
                    l = mid + 1;
            }

            if (ret != -1)
            {
                ans.push_back(min(node[i].index, node[ret].index));
                ans.push_back(max(node[i].index, node[ret].index));
                return ans;
            }
        }
    }
};