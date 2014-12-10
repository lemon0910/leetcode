struct SLItem
{
	int key;
	int value;
};

class LRUCache{
public:
	LRUCache(int capacity) : m_capacity(capacity){
		
	}

	int get(int key) {
		map<int, list<SLItem>::iterator>::iterator it = m_map.find(key);
		if (it == m_map.end())
			return -1;

		int ret = (*(it->second)).value;
		m_list.erase(it->second);
		SLItem item;
		item.key = key;
		item.value = ret;
		m_list.push_front( item);
		m_map[key] = m_list.begin();

		return ret;
	}

	void set(int key, int value) {
		if (0 >= m_capacity)
			return;
		if (-1 != get(key))
		{
			map<int, list<SLItem>::iterator>::iterator it = m_map.find(key);
			(*(it->second)).value = value;
			return;
		}
		if (m_list.size() < m_capacity)
		{
			SLItem item;
			item.key = key;
			item.value = value;
			m_list.push_front(item);
			m_map[key] = m_list.begin();
			return;
		}

		SLItem item = m_list.back();
		m_map.erase(item.key);
		m_list.pop_back();
		item.key = key;
		item.value = value;
		m_list.push_front(item);
		m_map[key] = m_list.begin();
	}

private:
	int m_capacity;
	list<SLItem> m_list;
	map<int, list<SLItem>::iterator> m_map;
};