class MapSum
{
    map<string, int> m;
    map<string, int> prefix_m;
public:
    /** Initialize your data structure here. */
    MapSum()
    {
        
    }
    
    void insert(string key, int val)
    {
        int cur_val = 0;
        
        if (m.find(key) != m.end())
        {
            cur_val = m[key];
        }
        
        m[key] = val;
        
        string prefix = "";
        
        for (char c : key)
        {
            prefix += c;
            
            if (prefix_m.find(prefix) != prefix_m.end())
            {
                prefix_m[prefix] += val - cur_val;
            }
            else
            {
                prefix_m[prefix] = val;
            }
        }
    }
    
    int sum(string prefix)
    {
        if (prefix_m.find(prefix) != prefix_m.end())
        {
            return prefix_m[prefix];
        }
        else
        {
            return 0;
        }
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */