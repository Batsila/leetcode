public class Solution
{
    public long MaxKelements(int[] nums, int k)
    {
        var score = 0L;
        var heap = new PriorityQueue<int, int>();

        foreach (var num in nums)
        {
            heap.Enqueue(num, -num);
        }

        for (int i = 0; i < k; ++i)
        {
            var num = heap.Dequeue();
            score += num;
            num = num / 3 + (num % 3 > 0 ? 1 : 0);
            heap.Enqueue(num, -num);
        }

        return score;
    }
}