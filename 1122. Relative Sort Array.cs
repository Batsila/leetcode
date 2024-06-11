public class Solution
{
    public int[] RelativeSortArray(int[] arr1, int[] arr2)
    {
        var frequencies = arr2.ToDictionary(x => x, x => 0);
        var extraItems = new List<int>();

        foreach (var num in arr1)
        {
            if (frequencies.ContainsKey(num))
            {
                ++frequencies[num];
            }
            else
            {
                extraItems.Add(num);
            }
        }

        var result = new List<int>();

        foreach (var num in arr2)
        {
            result.AddRange(Enumerable.Range(0, frequencies[num]).Select(x => num));
        }

        result.AddRange(extraItems.Order());

        return result.ToArray();
    }
}