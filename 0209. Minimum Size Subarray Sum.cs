public class Solution
{
    public int MinSubArrayLen(int target, int[] nums)
    {
        var result = int.MaxValue;
        var sum = 0;
        var r = 0;
        var l = 0;

        while (r < nums.Length)
        {
            sum += nums[r];

            while (sum >= target)
            {
                result = Math.Min(result, r - l + 1);
                sum -= nums[l];
                ++l;
            }

            ++r;
        }

        return result == int.MaxValue ? 0 : result;
    }
}