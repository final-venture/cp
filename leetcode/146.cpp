class LL
{
public:
    int key;
    int val;
    LL *next;
    LL *prev;
    LL(int key, int val) : key{key}, val{val}, next{nullptr}, prev{nullptr} {}
    ~LL()
    {
        if (prev)
            prev->next = next;
        if (next)
            next->prev = prev;
    }
};

class LRUCache
{
public:
    unordered_map<int, LL *> cache;
    int cap;
    LL *left = new LL(-1, -1);
    LL *right = new LL(-1, -1);

    LRUCache(int capacity)
    {
        cap = capacity;
        left->next = right;
        right->prev = left;
    }

    void ins(LL *node)
    {
        node->prev = left;
        node->next = left->next;
        left->next->prev = node;
        left->next = node;
    }

    int get(int key)
    {
        if (cache.find(key) != cache.end())
        {
            int tmp = cache[key]->val;
            delete cache[key];
            cache[key] = new LL(key, tmp);
            ins(cache[key]);
            return tmp;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (cache.find(key) != cache.end())
        {
            delete cache[key];
            cache[key] = new LL(key, value);
            ins(cache[key]);
        }
        else if (cap)
        {
            cache[key] = new LL(key, value);
            ins(cache[key]);
            --cap;
        }
        else
        {
            cache.erase(right->prev->key);
            delete right->prev;
            cache[key] = new LL(key, value);
            ins(cache[key]);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */