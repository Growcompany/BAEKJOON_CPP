#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long int lli;

vector<pair<int,pair<int,lli>>> dots;

int n,m;
vector<int> parents(10001);

int find_parents(int a){
	int new_a = parents[a];
	if(new_a == a) return a;
	else {return parents[a] = find_parents(new_a);}
}

void union_parents(int a, int b){
	a = find_parents(a);
    b = find_parents(b);
	a > b ? parents[a] = parents[b] : parents[b] = parents[a];
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>m;

	parents.assign(n+1, 0);

	for(int i=1; i<=n; i++){
		parents[i] = i;
	}

	int a,b,c;
	for(int i=0; i<m; i++){
		cin>>a>>b>>c;
		dots.push_back({a,{b,c}});
	}

	sort(dots.begin(), dots.end(), [](const auto& a, const auto& b) 
	{return a.second.second < b.second.second;});

	int res = 0;

	for(const auto& dot : dots){
		if(find_parents(dot.first) == find_parents(dot.second.first))
		{
			continue;
		}
		else{ union_parents(dot.first, dot.second.first);}
		res += dot.second.second;
	}

	cout<<res;

	return 0;
}
