class Solution
{
public:
    bool validMountainArray(vector<int>& arr)
    {
        if (arr.size() < 3)
        {
            return false;
        }
        
        int ind = 0;
        
        bool r = false;
        
        for (; ind < arr.size() - 1; ++ind)
        {
            if (arr[ind] == arr[ind + 1])
            {
                return false;
            }
            else if (arr[ind] > arr[ind + 1])
            {
                break;
            }
            
            r = true;
        }
        
        bool d = false;
        
        for (; ind < arr.size() - 1; ++ind)
        {
            if (arr[ind] <= arr[ind + 1])
            {
                return false;
            }
            
            d = true;
        }
        
        return r and d;
    }
};