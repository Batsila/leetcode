public class Solution
{
    public int NumRescueBoats(int[] people, int limit)
    {
        Array.Sort(people);

        var ans = 0;
        var l = 0;
        var r = people.Length - 1;

        while (r >= l)
        {
            if (people[r] + people[l] <= limit)
            {
                ++l;
            }

            ++ans;
            --r;
        }

        return ans;
    }
}