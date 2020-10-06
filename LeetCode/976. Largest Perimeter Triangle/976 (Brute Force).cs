public class Solution 
{
    public int LargestPerimeter(int[] A) 
    {
        int p = 0;
        
        for (int i = 0; i < A.Count(); ++i)
        {
            int a = A[i];
            
            for (int j = i + 1; j < A.Count(); ++j)
            {
                int b = A[j];
                
                for (int k = j + 1; k < A.Count(); ++k)
                {
                    int c = A[k];
                    
                    if (c < a + b && b < a + c && a < c + b)
                    {
                        p = Math.Max(p, a + b + c);
                    }
                }
            }
        }
        
        return p;
    }
}