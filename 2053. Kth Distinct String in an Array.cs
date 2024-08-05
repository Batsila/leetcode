public class Solution
{
    public string KthDistinct(string[] arr, int k)
    {
        var distinctStrings = arr.GroupBy(x => x).Where(x => x.Count() == 1).Select(x => x.Key).ToList();

        return distinctStrings.Count >= k ? distinctStrings[k - 1] : "";
    }
}