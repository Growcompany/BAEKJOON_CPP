#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	int N;

	cin>>N;

	vector<int> heights(N);
	vector<int> result(N,0);

	for(int i=0; i<N; i++)
	{
		cin>>heights[i];
	}

	for(int i=0; i<N; i++)
	{
		double max_angle = -1e9;
		for(int j=i+1; j<N; j++)
		{
			//cout<<"i:"<<i<<", j:"<<j<<endl;
			double angle = (double)(heights[j]-heights[i])/(j-i);
			if(angle > max_angle)
			{
				max_angle = angle;
				result[i]++;
				result[j]++;
			}
		}
		
	}

	int res = 0;
	for(const auto& num : result)
	{
		res = max(res, num);
	}

	cout<<res;

	return 0;
}
