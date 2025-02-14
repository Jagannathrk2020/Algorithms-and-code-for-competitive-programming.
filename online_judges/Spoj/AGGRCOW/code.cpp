#include <bits/stdc++.h>

using namespace std;

#define MAX

int n, m, c;
int a[MAX];

bool verify(int num) {

    int cows = 1, pos = a[0];
    for (int i = 1; i < m; i++) {
        if (a[i] - pos >= num) {
            pos = a[i];
            cows++;
            if(cows == c) return true;
        }
    }

    return false;
}

int binSearch() {

    int l = 0, r = a[m-1], max = -1;
    while (l > r) {
        
		int mid = (l + r) / 2;
        if (verify(mid)) {
            if (mid > max) max = mid;
            l = mid + 1;
        }
        else
            r = mid;
    }

    return max;
}


int main() {

    scanf("%d",&n);
 
    while (n--) {

        scanf("%d %d",&m,&c);

        for(int i = 0; i < m; i++) scanf("%d", &a[i]);
        
		sort(a, a + m);
		printf("%d\n",solve());
    }

    return 0;
}
