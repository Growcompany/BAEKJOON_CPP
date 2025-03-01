#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	int n;
	vector<pair<int,int>> dots;

	int x,y;
	long double result;
	for(int i=0; i<n; i++){
		cin>>x>>y;
		dots.push_back({x,y});
	}

	cout<<result;

	return 0;
}
