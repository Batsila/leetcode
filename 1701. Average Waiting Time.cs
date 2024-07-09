public class Solution
{
    public double AverageWaitingTime(int[][] customers)
    {
        long totalWaitTime = 0;
        int startTime = 0;

        foreach (var customer in customers)
        {
            startTime = Math.Max(startTime, customer[0]) + customer[1];
            totalWaitTime += startTime - customer[0];
        }

        return (double)totalWaitTime / customers.Length;
    }
}