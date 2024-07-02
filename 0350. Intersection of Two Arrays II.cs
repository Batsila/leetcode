public class Solution 
{
    public int[] Intersect(int[] nums1, int[] nums2) 
    {
        var frequencies = new Dictionary<int, int>();
        
        foreach (var num in nums1)
        {
            if (frequencies.ContainsKey(num))
            {
                ++frequencies[num];
            }
            else
            {
                frequencies.Add(num, 1);
            }
        }
        
        var result = new List<int>();
        
        foreach (var num in nums2)
        {
            if (frequencies.ContainsKey(num) && frequencies[num] > 0)
            {
                result.Add(num);
                --frequencies[num];
            }
        }
        
        return result.ToArray();
    }
}