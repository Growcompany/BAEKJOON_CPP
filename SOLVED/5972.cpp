#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

#define INF 1e9

vector<vector<pair<int,int>>> vertexs(50001);
vector<int> dist;

void Dijkstra(int start)
{
	priority_queue<pair<int,int>> q;
	dist[start] = 0;
	q.push({0, start});

	while(!q.empty())
	{
		int cost = -q.top().first;
		int next_vertex = q.top().second;
		q.pop();

		if(dist[next_vertex] < cost) continue;

		for(const auto& a: vertexs[next_vertex])
		{
			int next_vertex = a.first;
			int next_cost = a.second;
			if(next_cost + cost < dist[next_vertex])
			{
				dist[next_vertex] = next_cost + cost;
				q.push({-dist[next_vertex], next_vertex});
			}
			
		}
	}
}

int main(){
	int N, M;

	cin>>N>>M;

	dist.assign(N+1, INF);

	int A, B, C;

	for(int i=0; i<M; i++)
	{
		cin>>A>>B>>C;
		vertexs[A].push_back({B,C});
		vertexs[B].push_back({A,C});
	}

	Dijkstra(1);

	cout<<dist[N]<<endl;
	
	return 0;
}
