class Solution 
{
public:
    int getWinner(vector<int>& arr, int k) 
    {
        deque d(arr.begin(), arr.end());
        
        int current = d.front();
        int c = 0;
        
        while (c < k && c != arr.size())
        {
            int a = d.front();
            d.pop_front();
            int b = d.front();
            d.pop_front();
            
            if (a < b)
            {
                current = b;
                c = 1;
                
                d.push_front(b);
                d.push_back(a);
            }
            else
            {
                ++c;
                
                d.push_front(a);
                d.push_back(b);
            }
        }
        
        return current;
    }
};