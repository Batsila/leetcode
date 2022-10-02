class Solution
{
    set<vector<int>> p;
    vector<int> c;
    vector<bool> u;
    vector<int> n;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        u = vector<bool>(nums.size(), false);
        n = nums;
        help();
        
        return vector<vector<int>>(p.begin(), p.end());
    }
    
    void help()
    {
        if (c.size() == u.size())
        {
            p.insert(c);
        }
        else
        {
            for (int i = 0; i < n.size(); ++i)
            {
                if (u[i] == false)
                {
                    c.push_back(n[i]);
                    u[i] = true;
                    help();
                    u[i] = false;
                    c.pop_back();
                }
            }
        }
    }
};