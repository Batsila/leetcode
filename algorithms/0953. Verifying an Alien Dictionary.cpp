class Solution 
{
    map<char, int> m;
public:
    bool isAlienSorted(vector<string>& words, string order) 
    {
        for (int i = 0; i < order.size(); ++i)
        {
            m.insert(make_pair(order[i], i));
        }
        
        for (int i = 0; i < words.size() - 1; ++i)
        {
            if (!check(words[i], words[i + 1]))
            {
                return false;
            }
        }
        
        return true;
    }
    
    bool check(string a, string b)
    {
        int i = 0;
        
        while (i < a.size() && i < b.size())
        {
            if (m.find(a[i])->second > m.find(b[i])->second)
            {
                return false;
            }
            else if (m.find(a[i])->second < m.find(b[i])->second)
            {
                return true;
            }
            
            ++i;
        }
        
        return a.size() <= b.size();
    }
};