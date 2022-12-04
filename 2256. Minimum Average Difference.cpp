class Solution
{
public:
    int minimumAverageDifference(vector<int>& nums)
    {
        vector<long long> avgLeft;
        long long sum = 0;
        long long count = 0;
        
        for (int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
            count += 1;
            avgLeft.push_back(sum / count);
        }
        
        vector<long long> avgRight;
        sum = 0;
        count = 0;
        
        for (int i = nums.size() - 1; i >= 0; --i)
        {
            sum += nums[i];
            count += 1;
            avgRight.push_back(sum / count);
        }
        
        reverse(avgRight.begin(), avgRight.end());
        
        int ans = -1;
        int dif = INT_MAX;
        
        for (int i = 0; i < nums.size(); ++i)
        {
            int curDif = abs(avgLeft[i] - (i < nums.size() - 1 ? avgRight[i + 1] : 0));
            
            if (curDif < dif)
            {
                dif = curDif;
                ans = i;
            }
        }
        
        return ans;
    }
};