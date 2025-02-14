#include <bits/stdc++.h>
#define MAX 100010

using namespace std;

int a[MAX];
bool used[MAX];
int n;

int bin_search(int x, int aux) {

	int i = 0, j = n-1, m = j/2;

	while(i < j) {
		if(a[m] - a[x] < aux) i = m + 1;
		else if(a[m] - a[x] > aux) j = m - 1;
		else return m;
		m = (i+j)/2;
	}
	return i;
}

int main() {

	while(scanf("%d",&n) != EOF){
		a[0] = 0;
		for(int i = 1; i <= n; i++){
			scanf("%d",&a[i]);
			a[i] += a[i-1];
		}
		
		if(a[n] % 3 != 0) {printf("%d\n",0); continue; }
		int aux = a[n] / 3;
		int ans = 0;
		memset(used,false,sizeof used);
		for(int i = 0; i <= n; i++){
			if(!used[i]){
				int x = bin_search(i,aux);
				int y = bin_search(x,aux);
//				printf("%d %d %d\n",a[i],a[x],a[y]);
				if(a[x] - a[i] == aux && a[y] - a[x] == aux){
					ans++; used[i] = used[x] = used[y] = true;
				}
			}
		}
	
		printf("%d\n",ans);
	}

	return 0;
}
