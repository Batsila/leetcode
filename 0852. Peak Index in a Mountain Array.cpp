class Solution 
{
public:
    int peakIndexInMountainArray(vector<int>& A) 
    {
        for (int i = 1; i < A.size() - 1; ++i)
        {
            if (A[i - 1] < A[i] && A[i + 1] < A[i])
            {
                return i;
            }
        }
        
        return -1;
    }
};