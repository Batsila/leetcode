class Solution
{
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges)
    {
        vector<int> deltas;
        long long sum = 0;

        for (int num : nums)
        {
            deltas.push_back((num ^ k) - num);
            sum += num;
        }

        sort(deltas.begin(), deltas.end());

        for (int i = deltas.size() - 1; i > 0; i -= 2)
        {
            if (deltas[i] + deltas[i - 1] > 0)
            {
                sum += deltas[i];
                sum += deltas[i - 1];
            }
        }
        
        return sum;
    }
};