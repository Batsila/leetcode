class Solution
{
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> subsets;
        subsets.push_back({});

        for (int num : nums)
        {
            vector<vector<int>> current_subsets;

            for (auto subset : subsets)
            {
                vector<int> current = subset;
                current.push_back(num);
                current_subsets.push_back(current);
            }

            subsets.insert(subsets.end(), current_subsets.begin(), current_subsets.end());
        }
        
        return subsets;
    }
};