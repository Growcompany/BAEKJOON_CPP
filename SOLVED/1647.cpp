#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<pair<int,pair<int,int>>> roads;

vector<int> parents(10001);

int find_parents(int a){
	if(parents[a] == a) 
		return a;
	else
		return parents[a] = find_parents(parents[a]);
}

void union_parents(int a, int b){
    a = find_parents(a);
    b = find_parents(b);
    a > b ? (parents[a] = parents[b]) : (parents[b] = parents[a]);

}


int main(){

	int n, m;

	cin>>n>>m;

	parents.assign(n+1,0);
	
	for(int i=1; i<n+1; i++)
		parents[i] = i;

	int a,b,c;
	for(int i=0; i<m; i++){
		cin>>a>>b>>c;
		roads.push_back({a,{b,c}});
	}

	sort(roads.begin(), roads.end(), [](const auto& a, const auto& b) {return a.second.second < b.second.second;});
	
	int res = 0;
	int max_road = 0;
	for(const auto& road : roads){
		if(find_parents(road.first) != find_parents(road.second.first)){
			union_parents(road.first, road.second.first);
			
			res += road.second.second;
			max_road = max(max_road, road.second.second);
			
		}

	}
	

	cout<<res-max_road<<endl;
	

	return 0;
}
