public class Solution
{
    public int FindTheWinner(int n, int k)
    {
        var queue = new Queue<int>(Enumerable.Range(1, n));

        while (queue.Count > 1)
        {
            for (int i = 0; i < k - 1; ++i)
            {
                queue.Enqueue(queue.Dequeue());
            }

            queue.Dequeue();
        }

        return queue.Peek();
    }
}