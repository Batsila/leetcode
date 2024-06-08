public class Solution
{
    public bool CheckSubarraySum(int[] nums, int k)
    {
        var modIndexies = new Dictionary<int, int>
        {
            { 0, -1 }
        };
        var prefixMod = 0;

        for (int i = 0; i < nums.Length; ++i)
        {
            prefixMod = (prefixMod + nums[i]) % k;

            if (modIndexies.TryGetValue(prefixMod, out var modIndex))
            {
                if (i - modIndex > 1)
                {
                    return true;
                }
            }
            else
            {
                modIndexies[prefixMod] = i;
            }
        }

        return false;
    }
}