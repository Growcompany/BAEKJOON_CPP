#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define INF 1e9

vector<pair<int,int>> matrix;
int dp[501][501];

int func(int start, int end)
{
	if(dp[start][end] != -1) return dp[start][end];
	if ( start - end == 0) return 0;
	int mm = INF;
	for(int i=start; i<end; i++){
		mm = min(mm, func(start, i) + func(i+1, end)+matrix[start].first*matrix[i+1].first*matrix[end].second);
	}
	return dp[start][end] = mm;
}

int main(){
	int n;
	cin>>n;

	int r,c;
	for(int i=0; i<n; i++){
		cin>>r>>c;
		matrix.push_back({r,c});
	}

	for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            dp[i][j] = -1;
        }
    }
	cout<<func(0,n-1);

	

	return 0;
}
