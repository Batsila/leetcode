class Solution
{
public:
    bool canReorderDoubled(vector<int>& arr)
    {
        unordered_map<int, int> m;
        vector<int> p;
        vector<int> n;
        
        for (int a : arr)
        {
            if (m.find(a) != m.end())
            {
                ++m[a];
            }
            else
            {
                m[a] = 1;
            }
            
            if (a < 0)
            {
                n.push_back(a);
            }
            else
            {
                p.push_back(a);
            }
        }
        
        sort(n.begin(), n.end());
        reverse(n.begin(), n.end());
        sort(p.begin(), p.end());
        
        for (int a : n)
        {
            if (m[a] > 0)
            {
                if (m.find(a * 2) != m.end() and m[a * 2] > 0)
                {
                    --m[a];
                    --m[a * 2];
                }
                else
                {
                    return false;
                }
            }
        }
        
        for (int a : p)
        {
            if (m[a] > 0)
            {
                if (m.find(a * 2) != m.end() and m[a * 2] > 0)
                {
                    --m[a];
                    --m[a * 2];
                }
                else
                {
                    return false;
                }
            }
        }
        
        return true;
    }
};