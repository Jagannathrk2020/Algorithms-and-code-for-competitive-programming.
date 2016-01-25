#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#define MAX 1001
using namespace std;

int n, m;
int pinos[MAX], quant, cont, x;

int main(){

	scanf("%d %d",&n, &m);
	for(int i = 0 ; i < n ; i++){
		scanf("%d",&x);
		pinos[i] = x;
	}
		
	quant = 0;
	cont = 0;

	for(int i = 0; i < n; i++){
		pinos[i] += quant;
		quant = m - pinos[i]; 
		cont += abs(quant);
	}

	printf("%d\n",cont);
	return 0;
}
