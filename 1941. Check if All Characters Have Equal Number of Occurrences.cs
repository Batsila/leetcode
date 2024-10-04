public class Solution
{
    public bool AreOccurrencesEqual(string s)
    {
        var frequencies = s.ToCharArray().GroupBy(x => x).Select(x => (character: x.Key, count: x.Count())).ToList();

        for (int i = 1; i < frequencies.Count; ++i)
        {
            if (frequencies[i].count != frequencies[i - 1].count)
            {
                return false;
            }
        }

        return true;
    }
}