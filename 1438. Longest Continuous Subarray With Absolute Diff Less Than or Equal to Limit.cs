public class Solution
{
    public int LongestSubarray(int[] nums, int limit)
    {
        var result = 0;
        var maxHeap = new PriorityQueue<(int, int), int>();
        var minHeap = new PriorityQueue<(int, int), int>();
        var l = 0;
        var r = 0;

        while (r < nums.Length)
        {
            maxHeap.Enqueue((nums[r], r), -nums[r]);
            minHeap.Enqueue((nums[r], r), nums[r]);

            while (maxHeap.Peek().Item1 - minHeap.Peek().Item1 > limit)
            {
                l = Math.Min(maxHeap.Peek().Item2, minHeap.Peek().Item2) + 1;

                while (maxHeap.Peek().Item2 < l)
                {
                    maxHeap.Dequeue();
                }

                while (minHeap.Peek().Item2 < l)
                {
                    minHeap.Dequeue();
                }
            }

            ++r;
            result = Math.Max(result, r - l);
        }

        return result;
    }
}