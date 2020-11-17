public class Solution 
{
    public int[] Intersect(int[] nums1, int[] nums2) 
    {
        var d = new Dictionary<int, int>();
        
        foreach (var e in nums1)
        {
            if (!d.ContainsKey(e))
            {
                d[e] += 1;
            }
            else
            {
                d.Add(e, 1);
            }
        }
        
        var ans = new List<int>();
        
        foreach (var e in nums2)
        {
            if (d.ContainsKey(e) && d[e] > 0)
            {
                ans.Add(e);
                d[e] -= 1;
            }
        }
        
        return ans.ToArray();
    }
}