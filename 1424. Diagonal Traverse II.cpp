class Solution 
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) 
    {
        vector<tuple<int, int, int>> items;
        
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = 0; j < nums[i].size(); ++j)
            {
                items.push_back(make_tuple(i + j, i, nums[i][j]));
            }
        }
        
        sort(items.begin(), items.end(), [](auto const &t1, auto const &t2)
        {
            if (get<0>(t1) == get<0>(t2)) 
            {
                return get<1>(t1) > get<1>(t2);
            }
            
            return get<0>(t1) < get<0>(t2);
        });

        vector<int> ans;

        for_each(items.begin(), items.end(), [&ans](auto const &t)
        {
            ans.push_back(get<2>(t));
        });
        
        return ans;
    }
};