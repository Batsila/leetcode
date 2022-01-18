class Solution
{
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n)
    {
        int c = 0;
        
        for (int i = 0; i < flowerbed.size(); ++i)
        {
            if (flowerbed[i] == 0
               and (i == 0 or flowerbed[i - 1] == 0)
               and (i == flowerbed.size() - 1 or flowerbed[i + 1] == 0))
            {
                flowerbed[i] = 1;
                ++c;
            }
        }
        
        return c >= n;
    }
};