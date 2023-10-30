class Solution
{
public:
    vector<int> sortByBits(vector<int>& arr)
    {
        sort(arr.begin(), arr.end(), [](const int a, const int b)
        {
            int ac = 0;
            int bc = 0;

            for (int i = 0; i < 31; ++i)
            {
                ac += (a >> i) & 1;
                bc += (b >> i) & 1;
            }

            return ac == bc ? a < b : ac < bc;
        });

        return arr;
    }
};