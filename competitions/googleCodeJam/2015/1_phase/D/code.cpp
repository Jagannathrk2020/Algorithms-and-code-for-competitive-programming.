#include <stdio.h>

using namespace std;
int x,r,c;
int n;
int matriz[4][4][4] = {0};

int main(){

	for(int i = 0 ; i < 4 ; i++)
		for(int j= 0 ; j < 4 ; j++){
			matriz[0][i][j] = 1;
			if( ((i+1)*(j+1)) % 2==0)
				matriz[1][i][j] = 1;
	}

	matriz[2][2][1] = 1;
	matriz[2][1][2] = 1;
	matriz[2][2][3] = 1;
	matriz[2][3][2] = 1;
	matriz[2][2][2] = 1;

	matriz[3][3][3] = 1;

	scanf("%d",&n);
	for(int i = 0 ; i < n ;i++){
		scanf("%d %d %d",&x,&r,&c);
		printf("Case #%d: %s\n",i+1,matriz[x-1][r-1][c-1]==1?"GABRIEL":"RICHARD");

	}


	return 0;
}
