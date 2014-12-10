class LRUCache{
public:
    LRUCache(int capacity) {
        n = capacity;
    }
    
    int get(int key) {
        auto pos = m.find(key);
        if(pos == m.end())
            return -1;
        node temp = *(pos->second);
        mlist.erase(pos->second);
        mlist.push_back(temp);
        m[key] = --mlist.end();
        return temp.value;
    }
    
    void set(int key, int value) {
        if(0 >= n)
            return;
        if(get(key) != -1)
        {
            mlist.back().value = value;
            return;
        }
        if(mlist.size() < n)
        {
            node temp(key, value);
            mlist.push_back(temp);
            m[key] = --mlist.end();
            return;
        }

        node temp = mlist.front();
        m.erase(temp.key);
        mlist.pop_front();
        mlist.push_back(node(key, value));
        m[key] = --mlist.end();
    }

private:
    struct node
    {
        int key;
        int value;
        node(int k, int v) : key(k), value(v){}
    };

    list<node> mlist;
    map<int, list<node>::iterator> m;
    int n;
};
