public class Solution
{
    public int[] SingleNumber(int[] nums)
    {
        var xor = 0;

        foreach (var num in nums)
        {
            xor ^= num;
        }

        var a = 0;
        var b = 0;

        var mask = xor & (-xor);

        foreach (var num in nums)
        {
            if ((num & mask) == 0)
            {
                a ^= num;
            }
            else
            {
                b ^= num;
            }
        }

        return [a, b];
    }
}