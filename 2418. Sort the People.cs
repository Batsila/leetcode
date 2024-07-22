public class Solution
{
    public string[] SortPeople(string[] names, int[] heights)
    {
        return names.Zip(heights, (n, h) => (n, h)).OrderByDescending(x => x.h).Select(x => x.n).ToArray();
    }
}