class Solution
{
public:
    vector<int> majorityElement(vector<int>& nums)
    {
        unordered_map<int, int> m;

        for (int num : nums)
        {
            m[num]++;
        }

        vector<int> ans;

        for (auto p : m)
        {
            if (p.second > nums.size() / 3)
            {
                ans.push_back(p.first);
            }
        }

        return ans;
    }
};