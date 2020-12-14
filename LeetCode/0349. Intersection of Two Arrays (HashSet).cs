public class Solution 
{
    public int[] Intersection(int[] nums1, int[] nums2) 
    {
        var s1 = new HashSet<int>(nums1);
        
        var ans = new HashSet<int>();
        
        foreach (var num in nums2)
        {
            if (s1.Contains(num))
            {
                ans.Add(num);
            }
        }
        
        return ans.ToArray();
    }
}