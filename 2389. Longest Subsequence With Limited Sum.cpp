class Solution
{
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries)
    {
       sort(nums.begin(), nums.end());
       vector<int> ps(nums.begin(), nums.end());

       for (int i = 1; i < ps.size(); ++i)
       {
           ps[i] += ps[i - 1];
       }

       vector<int> ans;

       for (auto q : queries)
       {
           ans.push_back(upper_bound(ps.begin(), ps.end(), q) - ps.begin());
       }

       return ans;
    }
};