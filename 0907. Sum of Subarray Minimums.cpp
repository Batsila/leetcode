class Solution
{
public:
    int sumSubarrayMins(vector<int>& arr)
    {
        stack<int> s;
        long ans = 0;
        
        for (int i = 0; i <= arr.size(); ++i)
        {
            while (not s.empty() 
                   and (i == arr.size()
                        or arr[s.top()] >= arr[i]))
            {
                int m = s.top();
                s.pop();
                int l = s.empty() ? - 1 : s.top();
                int r = i;
                
                ans += ((m - l) * (r - m) * (long)arr[m]);
                ans %= 1000000007;
            }
            
            s.push(i);
        }
        
        return ans;
    }
};