#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define INF 9;

int dp[101][101];
int result[101];

int main(){
	int N, M;

	cin>>N;
	cin>>M;

	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=N; j++)
		{
			if(i == j)
			{
				dp[i][j] = 1;
				continue;
			}
			dp[i][j] = INF;
		}
		result[i] = 0;
	}

	int A,B;
	for(int i=0; i<M; i++){
		cin>>A>>B;
		dp[A][B] = 1;
	}

	for(int k=1; k<=N; k++)
	{
		for(int i=1; i<=N; i++)
		{
			for(int j=1; j<=N; j++)
			{
				if(dp[i][k] == 1 && dp[k][j] == 1){
					dp[i][j] = 1;
				}
			}
		}
	}

	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=N; j++)
		{
			if(dp[i][j] == 1)
			{
				result[i]++;
				if( i == j )
				{
					continue;
				}
				result[j]++;
			}
			//cout<<dp[i][j]<<" ";
		}
	}

	for(int i=1; i<=N; i++)
	{
		cout<<N-result[i]<<endl;
	}

	return 0;
}
