class Solution
{
public:
    int maxSubarraySumCircular(vector<int>& nums)
    {
        int maxSum = nums[0];
        int currentMaxSum = 0;
        int minSum = nums[0];
        int currentMinSum = 0;
        int sum = 0;

        for (int num : nums)
        {
            currentMaxSum = max(currentMaxSum, 0) + num;
            maxSum = max(maxSum, currentMaxSum);

            currentMinSum = min(currentMinSum, 0) + num;
            minSum = min(minSum, currentMinSum);

            sum += num;
        }

        return sum == minSum
            ? maxSum
            : max(maxSum, sum - minSum);
    }
};