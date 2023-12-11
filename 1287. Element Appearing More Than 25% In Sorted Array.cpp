class Solution
{
public:
    int findSpecialInteger(vector<int>& arr)
    {
        int targetSize = arr.size() / 4;

        for (int i = 0; i < arr.size() - targetSize; ++i)
        {
            if (arr[i] == arr[i + targetSize])
            {
                return arr[i];
            }
        }

        return -1;
    }
};