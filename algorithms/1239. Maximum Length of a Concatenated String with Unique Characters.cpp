class Solution
{
public:
    int maxLength(vector<string>& arr)
    {
        return help(arr, 0, "");
    }
    
    int help(vector<string>& arr, int ind, string c)
    {
        set<char> s(c.begin(), c.end());
        
        if (c.size() != s.size())
        {
            return 0;
        }
        
        int ans = c.size();
        
        for (int i = ind; i < arr.size(); ++i)
        {
            ans = max(ans,  help(arr, i + 1, c + arr[i]));
        }
        
        return ans;
    }
};