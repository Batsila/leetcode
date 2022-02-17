class Solution
{
    vector<int> s;
    int t;
    
    vector<int> c;
    int sum = 0;
    
    vector<vector<int>> ans;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        s = candidates;
        t = target;
        
        help();
        
        return ans;
    }
    
    void help(int ind = 0)
    {
        if (sum == t)
        {
            ans.push_back(c);
        }
        else
        {
            for (int i = ind; i < s.size(); ++i)
            {
                if (sum + s[i] <= t)
                {
                    c.push_back(s[i]);
                    sum += s[i];
                    help(i);
                    c.pop_back();
                    sum -= s[i];
                }
            }
        }
    }
};