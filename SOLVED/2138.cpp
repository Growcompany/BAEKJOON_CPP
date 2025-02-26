#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	int n;
	string input;
	string result;
	
	cin>>n;
	cin>>input;
	cin>>result;

	// 첫번째 ON
	string result1(input);
	int cnt1 = 1;

	result1[0] = (result1[0] == '0') ? '1' : '0';
	result1[1] = (result1[1] == '0') ? '1' : '0';

	for(int i=1; i<n; i++){
		if( result[i-1] == result1[i-1])
			continue;
		else
			result1[i-1] = result[i-1];
			result1[i] = (result1[i] == '0') ? '1' : '0';
			if(i != n-1){
				result1[i+1] = (result1[i+1] == '0') ? '1' : '0';
			}
		cnt1++;
	}

	// 첫번쨰 OFF
	string result2(input);
	int cnt2 = 0;

	for(int i=1; i<n; i++){
		if( result[i-1] == result2[i-1])
			continue;
		else
			result2[i-1] = result[i-1];
			result2[i] = (result2[i] == '0') ? '1' : '0';
			if(i != n-1){
				result2[i+1] = (result2[i+1] == '0') ? '1' : '0';
			}
		cnt2++;
	}
	// cout<<"result1:"<<result1<<endl;
	// cout<<"cnt1:"<<cnt1<<endl;
	// cout<<"result2:"<<result2<<endl;
	// cout<<"cnt2:"<<cnt2<<endl;

	if (result != result1)
		cnt1 = -1;
	if (result != result2)
		cnt2 = -1;

	if(min(cnt1,cnt2) == -1 && max(cnt1,cnt2) != -1){
		cout<<max(cnt1,cnt2);
	}
	else if(min(cnt1,cnt2) != -1){
		cout<<min(cnt1, cnt2);
	}
	else {cout<<-1;}
	
	return 0;
}
