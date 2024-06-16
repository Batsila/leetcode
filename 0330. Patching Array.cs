public class Solution
{
    public int MinPatches(int[] nums, int n)
    {
        long current = 1;
        int index = 0;
        int result = 0;

        while (current <= n)
        {
            if (index < nums.Length && nums[index] <= current)
            {
                current += nums[index];
                ++index;
            }
            else
            {
                current *= 2;
                ++result;
            }
        }

        return result;
    }
}