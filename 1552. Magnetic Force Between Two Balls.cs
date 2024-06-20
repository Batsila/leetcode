public class Solution
{
    public int MaxDistance(int[] positions, int m)
    {
        Array.Sort(positions);

        var left = 1;
        var right = positions.Max();

        while (left <= right)
        {
            var mid = (left + right) / 2;

            if (CanPlace(positions, mid, m))
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        
        return left - 1;
    }

    private bool CanPlace(int[] positions, int distance, int m)
    {
        var count = 1;
        var previous = positions[0];

        for (int i = 1; i < positions.Length; ++i)
        {
            if (positions[i] - previous >= distance)
            {
                ++count;
                previous = positions[i];
            }
        }

        return count >= m;
    }
}