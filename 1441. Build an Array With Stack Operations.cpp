class Solution 
{
public:
    vector<string> buildArray(vector<int>& target, int n) 
    {
        int ind = 0;
        vector<string> ans;
        
        for (int i = 1; i <= n; ++i)
        {
            if (ind == target.size())
            {
                break;
            }
            
            ans.push_back("Push");
            
            if (target[ind] != i)
            {
                ans.push_back("Pop");
            }
            else
            {
                ++ind;
            }
        }
        
        return ans;
    }
};