#include <bits/stdc++.h>
#define MAX 12
int main () {

    int coluna;
    float x, soma = 0;
    char operacao;

    scanf("%d", &coluna);
    scanf("\n%c", &operacao);

    for(int L=0; L < 12 ; L++){
        for(int C=0; C < 12; C++){
            scanf("%f",&x);
	        if(C == coluna) soma += x;
            }
        }

    if(operacao == 'S') printf("%.1f\n", soma);
    else printf("%.1f\n", soma/12.0);
   
}
