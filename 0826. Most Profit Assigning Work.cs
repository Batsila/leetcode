public class Solution
{
    public int MaxProfitAssignment(int[] difficulty, int[] profit, int[] worker)
    {
        var jobs = difficulty.Zip(profit, (d, p) => (d, p))
                             .OrderBy(x => x.d)
                             .ToArray();

        for (var i = 1; i < jobs.Length; ++i)
        {
            jobs[i].p = Math.Max(jobs[i].p, jobs[i - 1].p);
        }

        var result = 0;

        foreach (var skill in worker)
        {
            result += FindJob(jobs, skill);
        }

        return result;
    }

    private int FindJob((int d, int p)[] jobs, int skill)
    {
        var l = 0;
        var r = jobs.Length - 1;
        var profit = 0;

        while (l <= r)
        {
            var m = (l + r) / 2;

            if (skill >= jobs[m].d)
            {
                profit = Math.Max(profit, jobs[m].p);
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }

        return profit;
    }
}