class Solution
{
    string gens = "ACGT";
public:
    int minMutation(string start, string end, vector<string>& bank)
    {
        queue<string> q;
        set<string> u;
        set<string> b(bank.begin(), bank.end());
        
        q.push(start);
        u.insert(start);
        int ans = 0;
        
        while (not q.empty())
        {
            queue<string> cq = q;
            q = {};
            
            while (not cq.empty())
            {
                string c = cq.front();
                cq.pop();
                
                if (c == end)
                {
                    return ans;
                }
                else
                {
                    for (char g : gens)
                    {
                        for (int i = 0; i < c.size(); ++i)
                        {
                            string t = c;
                            t[i] = g;
                            
                            if (u.find(t) == u.end()
                                and b.find(t) != b.end())
                            {
                                q.push(t);
                                u.insert(t);
                            }
                        }
                    }
                }                
            }
            
            ++ans;
        }
        
        return -1;
    }
};