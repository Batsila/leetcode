class Solution
{
public:
    int maxIceCream(vector<int>& costs, int coins)
    {
        sort(costs.begin(), costs.end());

        int ans = 0;
        int ind = 0;

        while (ind < costs.size() and costs[ind] <= coins)
        {
            ++ans;
            coins -= costs[ind++];
        }

        return ans;
    }
};