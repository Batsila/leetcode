class Solution
{
public:
    int subarraysDivByK(vector<int>& nums, int k)
    {
        int ans = 0;
        int mod = 0;

        vector<int> v(k);
        v[0] = 1;

        for (int num : nums)
        {
            mod = (mod + num % k + k) % k;
            ans += v[mod];
            v[mod]++;
        }

        return ans;
    }
};