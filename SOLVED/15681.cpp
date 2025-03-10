#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<vector<int>> Vertexs;
vector<int> dp;

int find_next(int start, int before){
	//cout<<"start:"<<start<<", before:"<<before<<endl;
	int cnt = 1;
	if(Vertexs[start].size() == 1 && before != 0)
	{
		return 1;
	} 
	for(const auto& next_vertex: Vertexs[start])
	{
		if(next_vertex == before)
			continue;

		//cout<<"next_vertex:"<<next_vertex<<endl;
		cnt += find_next(next_vertex, start);
		//cout<<"now:"<<start<<", dp:"<<dp[start]<<endl;
	}

	return dp[start] = cnt;
}

int main(){
	ios_base::sync_with_stdio( false );

	cin.tie( NULL );
	cout.tie( NULL );

	int N, R, Q;

	cin>>N>>R>>Q;

	Vertexs.resize(N+1);
	dp.assign(N+1, 1);

	int U,V;
	for(int i=0; i<N-1; i++)
	{
		cin>>U>>V;
		Vertexs[U].push_back(V);
		Vertexs[V].push_back(U);
	}

	int temp = find_next(R,0);

	for(int i=0; i<Q; i++){
		cin>>U;
		cout<<dp[U]<<"\n";
	}


	return 0;
}