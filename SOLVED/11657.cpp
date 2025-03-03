#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define INF 1e9
typedef long long int lli;
using namespace std;

vector<pair<int,pair<int,int>>> citys;
vector<lli> dist(501);


bool bellmanford(int start, int citys_num, int line_num){
    dist[start] = 0;

    for(int i=1; i<=citys_num; i++){
        
        for(auto city: citys){
            if(dist[city.first] != INF){
                if( dist[city.first] + city.second.second < dist[city.second.first]){
                    dist[city.second.first] = dist[city.first] + city.second.second;

                    if(i == citys_num){return false;}
                }
                
            }
        }
    }

    return true;
}


int main(){
	int n,m;
	cin>>n>>m;

    dist.assign(n+1, INF);

    int A, B, C;
    for(int i=0; i<m; i++){
        cin>>A>>B>>C;
        citys.push_back({A,{B,C}});
    }

    if(bellmanford(1, n, m)){
        for(int i=2; i<=n; i++){
            int result = (dist[i] == INF) ? -1 : dist[i];
            cout<<result<<endl;
        }
    }
    else
        cout<<-1;


	return 0;
}
