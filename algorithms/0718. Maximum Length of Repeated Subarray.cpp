class Solution
{
    int dp[1000][10000];
public:
    int findLength(vector<int>& A, vector<int>& B)
    {
        int n = A.size();
	    int m = B.size();
	    
	    for (int i = 0; i < n; ++i)
	    {
		    dp[i][m - 1] = A[i] == B[m - 1] ? 1 : 0;
	    }

	    for (int i = 0; i < m; ++i)
	    {
		    dp[n - 1][i] = B[i] == A[n - 1] ? 1 : 0;
	    }
        
        int ans = 0;

	    for (int i = n - 2; i >= 0; --i)
	    {
		    for (int j = m - 2; j >= 0; --j)
		    {
			    dp[i][j] = A[i] == B[j] ? dp[i + 1][j + 1] + 1 : 0;
			    ans = max(ans, dp[i][j]);
		    }
	    }
        
        return ans;
    }
};