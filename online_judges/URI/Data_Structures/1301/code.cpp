#include <stdio.h>

#define MAX 1000000
#define ll long long int
using namespace std;

struct data {
	int  multi;
};

data t[4*MAX];

data make_data(int val){
	data result;
	if(val > 0) result.multi = 1;
	else if(val < 0) result.multi = -1;
	else result.multi = 0;
	return result;
};

data combine(data l, data r){
	data result;
	result.multi = l.multi*r.multi;
	return result;
}

void build(int id, int a[], int b, int e){

	if(b == e) {t[id] = make_data(a[b]); return;}

	int m = (b+e)/2;

	build(2*id, a, b,m);
	build(2*id + 1, a, m + 1, e);

	t[id] = combine(t[2*id],t[2*id + 1]);
};

void update(int id, int b, int e, int pos, int val){

	if(b == e) {t[id] = make_data(val); return; }

	int m = (b+e)/2;

	if(pos <= m)
		update(2*id,b,m,pos,val);
	else
		update(2*id + 1, m+1, e, pos,val);
	
	t[id] = combine(t[2*id],t[2*id + 1]);

}

data query(int id, int b, int e, int i, int j) {

	if(i == b && j == e) return t[id];

	int m = (b+e)/2;

	if(j <= m) return query(2*id,b,m,i,j);
	if(i > m) return query(2*id+1,m+1,e,i,j);
	return combine(query(2*id,b,m,i,m),query(2*id+1,m+1,e,m+1,j));
};

int n,k;
int a[MAX];
char c;
int x,y;

int main(){
	
	while(scanf("%d %d",&n,&k) != EOF){
		for(int i = 1 ; i <= n ; i++)
			scanf("%d",&a[i]);
		build(1,a,1,n+1);
		for(int i = 0 ; i < k ; i++){
			scanf("\n%c %d %d",&c ,&x,&y);
			if(c == 'C') update(1,1,n+1,x,y);
			else {
					data res = query(1,1,n+1,x,y);
					if(res.multi > 0) printf("+");
					else if(res.multi < 0) printf("-");
					else printf("0");
			}
		}
		printf("\n");
	}
	return 0;
}
