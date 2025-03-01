#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

long long int divv(int a, int b, int c){

    if (b == 0) return 1;
    if(b == 1){ return a%c;}
    if(b%2 == 1){
        return divv(a,b/2,c)%c*divv(a,b/2,c)%c*a%c;
    }
    else return divv(a,b/2,c)%c*divv(a,b/2,c)%c;
}

int main(){
	int a, b, c;

	cin>>a>>b>>c;

    cout<<divv(a,b,c);


	return 0;
}
