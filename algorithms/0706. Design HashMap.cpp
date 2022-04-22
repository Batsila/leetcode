class MyHashMap
{
    vector<int> vals;
public:
    MyHashMap()
    {
        vals = vector<int>(1000004, -1);
    }
    
    void put(int key, int value)
    {
        vals[key] = value;
    }
    
    int get(int key)
    {
        return vals[key];
    }
    
    void remove(int key)
    {
        vals[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */