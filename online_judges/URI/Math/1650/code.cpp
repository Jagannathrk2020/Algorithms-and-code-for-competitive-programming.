#include <stdio.h>
#include <math.h>
#define MAX 40000
#define ll long long int

using namespace std;

ll answer(ll a, ll b, int x){
	
	ll cont = 0;
	int i = (x == 1)? 0:1;
	ll c = b;

	while(a >= 8 && b >= 8){
		if( i % 2 == 1)
			c = b - 1;
		else
			c = b;
		cont = (a/2 - 3) * (c/2 - 3) ;
		a--;
		i++;
	}

	return cont;
}
int main(){

	ll n,m,c;
	while(1){

		scanf("%lld %lld %lld",&n,&m,&c);
		if (n == 0 && m == 0 && c == 0) break;
		printf("%lld\n",answer(n,m,c));				

	}
	return 0;
}
