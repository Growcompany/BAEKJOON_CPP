#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	int N;
	cin>>N;

	string nums;
	for(int i=0; i<N; i++)
	{
		cin>>nums;

		bool correct = true;
		int type = 0;
		int type1_1_num = 0;
		int type1_2_num = 0;
		bool type1_num = true;
		bool type3_num = true;

		for(int j=0; j<nums.length(); j++)
		{
			cout<<"type:"<<type<<", now_num:"<<nums[j]<<", type1_1_num:"<<type1_1_num<<", type1_2_num:"<<type1_2_num<<", type1_num:"<<type1_num<<", type3_num:"<< type3_num<<endl;
			
			if(type == 1)
			{
				if(nums[j] == '0')
				{
					type1_1_num += 1;
					continue;
				}
				else if(nums[j] == '1')
				{
					if(type1_1_num < 2)
					{
						correct = false;
						break;
					}
					else{
						type = 2;
						type1_1_num = 0;
						type1_2_num = 1;
						type1_num = true;
						continue;
					}
				}
			}

			if(type == 2)
			{
				if(nums[j] == '0' && type1_2_num == 1)
				{
					type = 3;
					type1_2_num = 0;
					type3_num = false;
					continue;
				}

				if(nums[j] == '0' && type1_2_num>1)
				{
					if(j+1 < nums.length())
					{
						if(nums[j+1] == '0')
						{
							type = 1;
							type1_num = false;
							type1_1_num = 1;
							type1_2_num = 0;
							continue;
						}
						else
						{
							type = 3;
							type1_1_num = 0;
							type1_2_num = 0;
							type3_num = false;
							continue;
						}
					}
					else
					{
						correct = false;
						break;
					}
				}
				
				if(nums[j] == '1')
				{
					type1_2_num++;
					continue;
				}
			}

			if(type == 3)
			{
				if(nums[j] == '1')
				{
					type = 0;
					type3_num = true;
					continue;
				}
				else{
					correct = false;
					break;
				}
			}
			


			if(type == 0)
			{
				if(nums[j] == '1')
				{
					type = 1;
					type1_num = false;
				}
				else if(nums[j] == '0')
				{
					type = 3;
					type3_num = false;
				}
			}
		}

		if(!type1_num || !type3_num)
		{
			correct = false;
		}

		correct ? cout<<"YES"<<endl : cout<<"NO"<<endl;
	}

	return 0;
}
