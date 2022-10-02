class Solution
{
public:
    int openLock(vector<string>& deadends, string target)
    {
        unordered_set<string> d(deadends.begin(), deadends.end());
        
        queue<string> q;
        
        if (d.find("0000") == d.end())
        {
            q.push("0000");
        }
        
        int ans = 0;
        
        while (!q.empty())
        {
            queue<string> cq = q;
            q = queue<string>();
            
            while (!cq.empty())
            {
                string c = cq.front();
                cq.pop();
                
                if (c == target)
                {
                    return ans;
                }
                
                for (string n : get_n(c))
                {
                    if (d.find(n) == d.end())
                    {
                        q.push(n);
                        d.insert(n);
                    }
                }
            }
            
            ++ans;
        }
        
        return -1;
    }
    
    vector<string> get_n(string s)
    {
        vector<string> v;
        
        for (int i = 0; i < 4; ++i)
        {
            for (int j : { 1, 9 })
            {
                string t = s;
                t[i] = '0' + (s[i] - '0' + j) % 10;
                v.push_back(t);
            }
        }
        
        return v;
    }
};