class Solution
{
public:
    int numberOfWeakCharacters(vector<vector<int>>& props)
    {
        sort(props.begin(), props.end(), [](vector<int> &a,vector<int> &b)
             {
                 return a[0] != b[0] ? a[0] > b[0] : a[1] < b[1];
             });

        int ans = 0;
        int maxDef = INT_MIN;
        
        for (auto prop : props)
        {
            if (maxDef > prop[1])
            {
                ++ans;
            }
            else
            {
                maxDef = prop[1];
            }
        }
        
        return ans;
    }
};