class Solution
{
public:
    long long maximumHappinessSum(vector<int>& happiness, int k)
    {
        sort(happiness.begin(), happiness.end(), greater<int>());

        long long ans = 0;
        int ind = 0;

        while (k > 0)
        {
            int current_happiness = happiness[ind] - ind;
            ans += current_happiness > 0 ? current_happiness : 0;
            ++ind;
            --k;
        }

        return ans;
    }
};