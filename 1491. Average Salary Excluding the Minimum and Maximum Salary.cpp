class Solution
{
public:
    double average(vector<int>& salary)
    {
        int maxSalary = INT_MIN;
        int minSalary = INT_MAX;
        int sum = 0;

        for (int curSalary : salary)
        {
            sum += curSalary;
            maxSalary = max(maxSalary, curSalary);
            minSalary = min(minSalary, curSalary);
        }

        return (sum - maxSalary - minSalary) * 1.0 / (salary.size() - 2);
    }
};