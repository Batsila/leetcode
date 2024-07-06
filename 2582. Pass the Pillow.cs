public class Solution
{
    public int PassThePillow(int n, int time)
    {
        var iteration = time / (n - 1);
        var index = time % (n - 1);

        if (iteration % 2 == 0)
        {
            return index + 1;
        }
        else
        {
            return n - index;
        }
    }
}