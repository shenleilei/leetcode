struct Node
{
    int key, value;
    Node(int key_, int value_): key(key_), value(value_)
    {
    
    }
};

class LRUCache {


    public:
        int cap;
        list<Node> l;
        unordered_map<int, list<Node>::iterator> d;

        LRUCache(int capacity) : cap(capacity) {
                
        }
            
        int get(int key) {
            if(d.count(key) == 0)
            {
                return -1;
            }
            else
            {
                auto val = *d[key].value;
                l.splice(l.begin(), l, d[key]);
                d[key] = l.begin();
                return val;
            }
                
        }
            
        void put(int key, int value) {
            if(d.count(key) != 0)
            {
                l.push(Node(key_value));
                l.splice(l.begin(), l, (--l.end()));
                d[key] = l.begin();
                return ;
            }
            else
            {
                if(d.size() == cap)
                {
                    auto last = --l.end();
                    auto prev_key = *last.key;
                    *last.key = key;
                    *last.value = value;
                    d.erase(prev_key);
                    l.splice(l.begin(), l, (--l.end()));
                    d[key] = l.begin();

                }
            }
                
        }
        
};











