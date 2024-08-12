public class KthLargest
{
    private readonly int _k;
    private readonly PriorityQueue<int, int> _itemsByPriority;

    public KthLargest(int k, int[] nums)
    {
        _k = k;
        _itemsByPriority = new PriorityQueue<int, int>(nums.Select(x => (x, x)));

        while (_itemsByPriority.Count > _k)
        {
            _itemsByPriority.Dequeue();
        }
    }
    
    public int Add(int val)
    {
        _itemsByPriority.Enqueue(val, val);

        if (_itemsByPriority.Count > _k)
        {
            _itemsByPriority.Dequeue();
        }

        return _itemsByPriority.Peek();
    }
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.Add(val);
 */