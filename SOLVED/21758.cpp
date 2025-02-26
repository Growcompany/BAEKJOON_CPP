#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	int n;

	cin>>n;

	vector<int> honey(n);
	int all_sum = 0;
	for(int i=0; i<n; i++){
		cin>>honey[i];
		all_sum += honey[i];
	}

	int left_prefix_sum = 0;
	int right_prefix_sum = all_sum - honey[n-1];
	int result = 0;

	for(int i=1; i<n; i++){ // //꿀벌이 좌좌
		left_prefix_sum += honey[i];
		right_prefix_sum -= honey[i];
		int temp = 0;
		//cout<<"i:"<<i<<", left_prefix_sum:"<<left_prefix_sum<<endl;
		if(i>1){
			temp += left_prefix_sum*2;
			int second_temp = left_prefix_sum - honey[1];
			int min_sum_minus = -1e9;
			int max_minus = -honey[1]*2;
			int first_minus = 0;
			int second_minus = 0;
			for(int j=1; j<i; j++){
				first_minus = -honey[j]*2;
				if(j==1){
					second_minus = 0;
				}
				else{
					second_minus -= honey[j-1];}
				if(second_minus < max_minus){
					break;
				}
				//cout<<"i:"<<i<<", j:"<<j<<", first_minus:"<< first_minus<<", second_minus:"<< second_minus<<endl;
				min_sum_minus = max(min_sum_minus, first_minus+second_minus);
			}
			temp = temp+min_sum_minus;
			//cout<<"temp:"<<temp<<endl;
		}
		if(i<n-2){ //꿀벌 오오

		}
		result = max(result, temp);
	}

	//꿀벌이 왼좌
	int left_right_bee = left_prefix_sum - honey[n-1] + *max_element(honey.begin()+1, honey.end()-1);
	// cout<<"honey[n-1]:"<<honey[n-1]<<endl;
	// cout<<"left_prefix_sum:"<<left_prefix_sum<<endl;
	// cout<<"left_right_bee:"<<left_right_bee<<endl;
	result = max(left_right_bee, result);

	reverse(honey.begin(),honey.end());
	left_prefix_sum = 0;
	right_prefix_sum = all_sum - honey[n-1];

	for(int i=1; i<n; i++){ // //꿀벌이 오오
		left_prefix_sum += honey[i];
		right_prefix_sum -= honey[i];
		int temp = 0;
		//cout<<"i:"<<i<<", left_prefix_sum:"<<left_prefix_sum<<endl;
		if(i>1){
			temp += left_prefix_sum*2;
			int second_temp = left_prefix_sum - honey[1];
			int min_sum_minus = -1e9;
			int max_minus = -honey[1]*2;
			int first_minus = 0;
			int second_minus = 0;
			for(int j=1; j<i; j++){
				first_minus = -honey[j]*2;
				if(j==1){
					second_minus = 0;
				}
				else{
					second_minus -= honey[j-1];}
				if(second_minus < max_minus){
					break;
				}
				//cout<<"i:"<<i<<", j:"<<j<<", first_minus:"<< first_minus<<", second_minus:"<< second_minus<<endl;
				min_sum_minus = max(min_sum_minus, first_minus+second_minus);
			}
			temp = temp+min_sum_minus;
			//cout<<"temp:"<<temp<<endl;
		}
		result = max(result, temp);
	}


	cout<<result;

	return 0;
}
