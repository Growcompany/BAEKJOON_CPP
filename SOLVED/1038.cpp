#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
	int N;

	cin>>N;

	queue<long long> nums;
	vector<long long> dp;

	for(int i=0; i<=9; i++)
	{
		dp.push_back(i);
		nums.push(i);
	}

	while(!nums.empty())
	{
		long long num = nums.front();

		long long last_num = num%10;
		nums.pop();

		for(int i=0; i<last_num; i++){
			long long new_last_num = num*10 + i;
			nums.push(new_last_num);
			dp.push_back(new_last_num);
		}
	}

	(N>=dp.size()) ? cout<<-1 : cout<<dp[N];

	return 0;
}


// 100

// 18

// 0, 1 ... 9  10개개
// 10
// 20, 21
// 30, 31, 32
// 40, 41, 42, 43

// 10, 20, 21, 30, 31, 32, .... 98, 210,

// 9876543210
