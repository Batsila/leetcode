class Solution
{
public:
    int maxResult(vector<int>& nums, int k)
    {
        deque<int> dq;
        dq.push_back(0);
        
        for (int i = 1; i < nums.size(); ++i)
        {
            nums[i] += nums[dq.front()];
            
            while (!dq.empty() and nums[dq.back()] <= nums[i])
            {
                dq.pop_back();
            }
            
            dq.push_back(i);

            if (i - dq.front() >= k)
            {
                dq.pop_front();
            }
        }
        
        return nums[nums.size() - 1];
    }
};