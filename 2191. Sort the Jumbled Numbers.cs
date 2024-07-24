public class Solution
{
    public int[] SortJumbled(int[] mapping, int[] nums)
    {
        return nums
            .Select(x => (source: x, mapped: ConvertNumber(x, mapping)))
            .OrderBy(x => x.mapped)
            .Select(x => x.source)
            .ToArray();
    }

    private static int ConvertNumber(int num, int[] mapping)
    {
        int newNum = 0;
        int position = 1;

        do
        {
            var digit = num % 10;
            num /= 10;
            newNum += mapping[digit] * position;
            position *= 10;
        }
        while (num > 0);

        return newNum;
    }
}