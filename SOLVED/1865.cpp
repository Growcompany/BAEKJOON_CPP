#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#define MAX 501
#define INF 1e9
using namespace std;


vector<vector<int>> road;
vector<pair<int,int>> edges;
long long d[MAX];

bool bellmanford(int start, int n){
	d[start] = 0;

	for(int i=1; i<=n; i++){
		// cout<<"i:"<<i<<endl;
		for(auto edge: edges){
			int from = edge.first;
			int to = edge.second;
			int cost = road[from][to];

			// cout<<"from:"<<from<<", to:"<<to<<", cost:"<<cost<<endl;

			//if(d[from] == INF) continue; 
			
			// 현재 간선을 거쳐서 다른 노드로 이동하는 거리가 더 짧은 경우 
			if(d[to] > d[from] + cost){ 
				d[to] = d[from] + cost; // 최단 거리 테이블 갱신 
				
				// n번째에도 최단 거리가 갱신된다면 음수 사이클 존재!  
				if(i == n) return true; 
            }
		}
	}

	return false;
}



int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin>>T;

	for(int i=0; i<T; i++){
		int N, M, W;
		cin>>N>>M>>W;

		road.clear();
		road.assign(N + 1, vector<int>(N + 1, INF));
		edges.clear();	

		fill(d, d + N + 1, INF);

		int S, E, T;

		for(int j=0; j<M; j++){ //도로정보
			cin>>S>>E>>T;
			if(road[S][E] < T){
				continue;
			}
			road[S][E] = T;
			road[E][S] = T;
			edges.push_back({S, E});
			edges.push_back({E, S});
		}
		
		for(int k=0; k<W; k++){ //웜홀정보
			cin>>S>>E>>T; //S,E,T
			if(road[S][E] < -T){
				continue;
			}
			road[S][E] = -T;
			edges.push_back({S, E});
		}
		
		// for(auto s: road){
		// 	for(auto ss: s){
		// 		cout<<ss;
		// 	}
		// 	cout<<endl;
		// }

        cout << (bellmanford(1, N) ? "YES" : "NO") << endl;
	}

	return 0;
}
