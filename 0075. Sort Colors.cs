public class Solution
{
    public void SortColors(int[] nums)
    {
        var redCount = 0;
        var whiteCount = 0;
        var blueCount = 0;

        foreach (var num in nums)
        {
            if (num == 0)
            {
                ++redCount;
            }
            else if (num == 1)
            {
                ++whiteCount;
            }
            else
            {
                ++blueCount;
            }
        }

        var ind = 0;
        ind = UpdateArray(nums, ind, 0, redCount);
        ind = UpdateArray(nums, ind, 1, whiteCount);
        ind = UpdateArray(nums, ind, 2, blueCount);
    }

    private int UpdateArray(int[] nums, int start, int value, int count)
    {
        var end = start + count;

        for (int i = start; i < end; ++i)
        {
            nums[i] = value;
        }

        return end;
    }
}