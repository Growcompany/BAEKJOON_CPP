#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

struct dot{
	long double x,y;
};

long double ex_result(dot first, dot second, dot thrid){
	long double result= 0;
	result = (second.x - first.x)*(thrid.y - first.y) - (second.y - first.y)*(thrid.x - first.x);
	return result / 2.0;
}

int main(){
	int n;
	cin>>n;
	vector<dot> dots;

	long double x,y;
	long double result = 0;
	for(int i=0; i<n; i++){
		cin>>x>>y;
		dots.push_back({x,y});
	}

	for(int i=1; i<dots.size()-1; i++){
		result += ex_result(dots[0], dots[i], dots[i+1]);
	}

	cout << fixed;
	cout.precision(1); 
	cout<< fabs(result);

	return 0;
}
