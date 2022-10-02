class Solution 
{
    unsigned long long sum[100];
    unsigned long long dp[100][100];
public:
    unsigned long long numTrees(int n) 
    {

	    dp[0][0] = 1;
	    sum[0] = 1;

	    for (int i = 1; i <= n; ++i)
	    {
		    for (int j = i; j > 0; --j)
		    {
			    dp[i][j] = sum[i - j] * sum[j - 1];
			    sum[i] += dp[i][j];
		    }
	    }
        
        return sum[n];
    }
};