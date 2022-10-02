class MyHashSet
{
    vector<bool> vals;
public:
    MyHashSet()
    {
        vals = vector<bool>(1000004, false);
    }
    
    void add(int key)
    {
        vals[key] = true;
    }
    
    void remove(int key)
    {
        vals[key] = false;
    }
    
    bool contains(int key)
    {
        return vals[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */