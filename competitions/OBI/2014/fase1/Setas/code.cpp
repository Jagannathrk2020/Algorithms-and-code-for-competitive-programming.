#include <bits/stdc++.h>
#define MAX 510

using namespace std;

char m[MAX][MAX];
int safe[MAX][MAX];

bool isSafe(int x, int y, int n){

	if(x <= 0 || y<= 0 || x > n || y > n) return false;

	if(safe[x][y] != -1) return safe[x][y] == 0;

	char c = m[x][y];
	int x1,y1;
	x1 = x;
	y1 = y;
	safe[x][y] = 0;
	if(c == '>') y1++;
	else if(c == 'A') x1--;
	else if(c == 'V') x1++;
	else y1--;

	bool b = isSafe(x1,y1,n);

	if (b) {safe[x][y] = 0; return true;}
	else {safe[x][y] = 1; return false;}
	
}

int main(){

	int n;
	scanf("%d",&n);

	for(int i = 1; i <= n; i++)
		for(int j = 1; j<=n; j++){
			scanf("\n%c",&m[i][j]);
			safe[i][j] = -1;
	}

	int answer = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(isSafe(i,j,n))
				answer++;	

	printf("%d\n",answer);
	return 0;
}
