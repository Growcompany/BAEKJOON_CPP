#include <iostream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

struct state {
	int distance;
	int Left_K;
	int x;
	int y;
};

int main(){
	int N, M, K;

	cin>>N>>M>>K;

	vector<string> map(N);

	for(int i=0; i<N; i++)
	{
		cin>>map[i];
	}

	int dx[4] = {-1,1,0,0};
	int dy[4] = {0,0,-1,1};

	queue<state> next_pos;
	vector<vector<vector<bool>>> visited(K+1, vector<vector<bool>>(N, vector<bool>(M, 0)));

	next_pos.push({1, K, 0, 0});
	visited[K][0][0] = true;
	int result = 1e9;

	bool arrived = false;

	while(!next_pos.empty())
	{
		auto pos = next_pos.front();
		int distance = pos.distance;
		int Left_K = pos.Left_K;
		int x = pos.x;
		int y = pos.y;
		
		next_pos.pop();

		// arrived check
		if( x == N-1 && y == M-1)
		{
			result = min(result, distance);
			arrived = true;
			break;
		}


		for(int j=0; j<4; j++)
		{
			int next_x = x + dx[j];
			int next_y = y + dy[j];

			// for(int i=0; i<N; i++)
			// {
			// 	for(int j=0; j<M; j++)
			// 	{
			// 		cout<<visited[i][j];
			// 	}
			// 	cout<<endl;
			// }

			//cout<<"now_x:"<<x<<", now_y:"<<y<<", next_x:"<<next_x<<", next_y:"<<next_y<<endl;
			
			// region check
			if(!(next_x>=0 && next_x<N && next_y>=0 && next_y<M)){ continue; }

			if(map[next_x][next_y] == '1')
			{
				if(Left_K>0)
				{
					if(!visited[Left_K-1][next_x][next_y])
					{
						next_pos.push({distance+1, Left_K-1, next_x, next_y});
						visited[Left_K-1][next_x][next_y] = true;
					}
				}
			}
			else if(map[next_x][next_y] == '0')
			{
				if(!visited[Left_K][next_x][next_y])
				{
					next_pos.push({distance+1, Left_K, next_x, next_y});
					visited[Left_K][next_x][next_y] = true;
				}
			}
		}
	}

	if(!arrived){result = -1;}

	cout<<result;

	return 0;
}
