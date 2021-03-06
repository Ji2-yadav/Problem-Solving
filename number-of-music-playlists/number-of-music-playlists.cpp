class Solution {
public:
   #define mod 1000000007
int numMusicPlaylists(int N, int L, int K) 
{
	vector<vector<int>> dp(L+1,vector<int>(N+1,0));
	dp[0][0]=1;
	for(int i=1;i<=L;++i)
		for(int n=1;n<=N;++n)
		{
            long x=0;
			if(n<=i)
				x=((long)N-n+1)*dp[i-1][n-1];
			if(n>K)
				x+=((long)n-K)*dp[i-1][n];
			dp[i][n]=x%mod;
		}
    return dp[L][N];
}
};