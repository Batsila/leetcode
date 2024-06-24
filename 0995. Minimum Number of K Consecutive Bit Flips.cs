public class Solution
{
    public int MinKBitFlips(int[] nums, int k)
    {
        var result = 0;
        var currentlyFliped = 0;
        var isFliped = new bool[nums.Length];

        for (int i = 0; i < nums.Length; ++i)
        {
            if (i >= k && isFliped[i - k])
            {
                --currentlyFliped;
            }

            if (currentlyFliped % 2 == nums[i])
            {
                if (i + k <= nums.Length)
                {
                    isFliped[i] = true;
                    ++currentlyFliped;
                    ++result;
                }
                else
                {
                    return -1;
                }
            }
        }

        return result;
    }
}