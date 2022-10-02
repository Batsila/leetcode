class Solution
{
public:
    int maxTurbulenceSize(vector<int>& arr)
    {
        int ans = 1;
        int ind = 0;
        
        for (int i = 1; i < arr.size(); ++i)
        {
            if (arr[i - 1] == arr[i])
            {
                ind = i;
            }
            else if (i == arr.size() - 1 or not ((arr[i - 1] < arr[i] and arr[i] > arr[i + 1]) or (arr[i - 1] > arr[i] and arr[i] < arr[i + 1])))
            {
                ans = max(ans, i - ind + 1);
                ind = i;
            }
        }
        
        return ans;
    }
};