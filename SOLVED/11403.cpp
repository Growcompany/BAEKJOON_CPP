#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int inputs[101][101];


int main(){
	int n;

	cin>>n;

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cin>>inputs[i][j];
		}
	}

	for (int k = 0; k < n; k++)
	{
        for (int i = 0; i < n; i++)
		{
            for (int j = 0; j < n; j++)
			{
                if (inputs[i][k] == 1 && inputs[k][j] == 1)
                    inputs[i][j] = 1;
            }
        }
    }

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cout<<inputs[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}
