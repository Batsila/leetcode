public class Solution
{
    public int NumWaterBottles(int numBottles, int numExchange)
    {
        var result = numBottles;

        while (numBottles >= numExchange)
        {
            result += numBottles / numExchange;
            numBottles = numBottles / numExchange + numBottles % numExchange;
        }

        return result;
    }
}