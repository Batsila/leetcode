class RandomizedSet
{
    map<int, int> m;
    vector<int> v;
    
public:
    bool insert(int val)
    {
        if (m.find(val) != m.end())
        {
            return false;
        }
        
        m[val] = v.size();
        v.push_back(val);
        
        return true;
    }
    
    bool remove(int val)
    {
        if (m.find(val) == m.end())
        {
            return false;
        }
        
        int ind = m[val];
        m.erase(val);
        
        if (ind < v.size() - 1)
        {
            v[ind] = v[v.size() - 1];
            m[v[ind]] = ind;
        }
        
        v.pop_back();
        
        return true;
        
    }
    
    int getRandom()
    {
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */