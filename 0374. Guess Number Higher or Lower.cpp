/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution
{
    
public:
    int guessNumber(int n)
    {
        int l = 1;
        int r = n;
        
        while (l <= r)
        {
            int c = l + (r - l) / 2;
            
            int g = guess(c);
            
            if (g == 0)
            {
                return c;
            }
            else if (g < 0)
            {
                r = c - 1;
            }
            else
            {
                l = c + 1;
            }
            
        }
        
        return 42;
    }
};