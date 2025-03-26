#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
	int N;

	cin>>N;

	vector<vector<int>> buildings(N+1);
	vector<int> basic_time(N+1);
	vector<int> result(N+1);
	vector <int> depth(N+1,0);
	queue<int> q;

	int inputs;
	for(int i=1; i<=N; i++)
	{
		cin>>inputs;

		basic_time[i] = inputs;
		result[i] = inputs;

		bool first_building = true;
		while(true)
		{
			cin>>inputs;
			if(inputs == -1)
			{
				if(first_building)
				{
					q.push(i);
				}
				break;
			}

			buildings[inputs].push_back(i);
			depth[i]++;
			first_building = false;
		}
	}

	while(!q.empty())
	{
		int NowBuildgNum = q.front();
		q.pop();

		for(const auto& NextNum : buildings[NowBuildgNum])
		{
			result[NextNum] = max(result[NextNum], result[NowBuildgNum] + basic_time[NextNum]);
			depth[NextNum]--;
			if(depth[NextNum] == 0)
			{
				q.push(NextNum);
			}
		}
	}


	for(int i=1; i<=N; i++)
	{
		cout<<result[i]<<endl;
	}

	return 0;
}
