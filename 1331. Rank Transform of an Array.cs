public class Solution
{
    public int[] ArrayRankTransform(int[] arr)
    {
        var ranks = arr.Distinct()
                       .Order()
                       .Select((x, ind) => (item: x, rank: ind + 1))
                       .ToDictionary(x => x.item, x => x.rank);

        return arr. Select(x => ranks[x]).ToArray();
    }
}