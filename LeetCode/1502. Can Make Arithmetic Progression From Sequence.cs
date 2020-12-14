public class Solution 
{
    public bool CanMakeArithmeticProgression(int[] arr) 
    {
        Array.Sort(arr);
        
        int d = arr[1] - arr[0];
        
        for (int i = 1; i < arr.Count() - 1; ++i)
        {
            if (d != arr[i + 1] - arr[i])
            {
                return false;
            }
        }
        
        return true;
    }
}