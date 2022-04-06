class Solution
{
public:
    int threeSumMulti(vector<int>& arr, int target)
    {
        long ans = 0;
        
        sort(arr.begin(), arr.end());
        
        for (int i = 0; i < arr.size(); ++i)
        {
            int l = i + 1;
            int r = arr.size() - 1;
            
            while (l < r)
            {
                if (arr[l] + arr[r] < target - arr[i])
                {
                    ++l;
                }
                else if (arr[l] + arr[r] > target - arr[i])
                {
                    --r;
                }
                else if (arr[l] != arr[r])
                {
                    int lc = 1;
                    int rc = 1;
                    
                    while (l + 1 < r and arr[l] == arr[l + 1])
                    {
                        ++lc;
                        ++l;
                    }
                    
                    while (r - 1 > l and arr[r] == arr[r - 1])
                    {
                        ++rc;
                        --r;
                    }
                    
                    ans += lc * rc;
                    ans %= 1000000007;
                    ++l;
                    --r;
                }
                else
                {
                    ans += (r - l + 1) * (r - l) / 2;
                    ans %= 1000000007;
                    break;
                }
            }
        }
        
        return ans;
    }
};