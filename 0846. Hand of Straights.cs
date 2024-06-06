public class Solution
{
    public bool IsNStraightHand(int[] hand, int groupSize)
    {
        if (hand.Length % groupSize == 0)
        {
            var frequencies = hand.GroupBy(x => x).ToDictionary(x => x.Key, x => x.Count());

            while (frequencies.Count > 0)
            {
                if (!TryCreateGroup(frequencies, groupSize))
                {
                    return false;
                }
            }

            return true;
        }
        else
        {
            return false;
        }
    }

    private bool TryCreateGroup(
        IDictionary<int, int> frequencies,
        int groupSize)
    {
        int start = frequencies.Keys.Min();

        for (int i = start; i < start + groupSize; ++i)
        {
            if (frequencies.TryGetValue(i, out var count))
            {
                if (count > 1)
                {
                    --frequencies[i];
                }
                else
                {
                    frequencies.Remove(i);
                }
            }
            else
            {
                return false;
            }
        }

        return true;
    }
}