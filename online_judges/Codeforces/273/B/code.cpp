#include <bits/stdc++.h>

using namespace std;

#define ll long long int

int main() {
    
	ll people, teams, ans_max, ans_min;

    scanf("%lld %lld",&people,&teams);

    ll y = people - teams + 1;
    ans_max = (y*(y-1))/2;

    if(people % teams == 0) ans_min = (((people/teams)*(people/teams-1))/2)*teams;
    else {

        ll rest = people % teams, k = ceil(people/(teams*1.0));
        
		ll i = (k-1);
        i = (i*(i-1))/2;
        k = (k*(k-1))/2;
        ans_min = k*(rest) + i*(teams-rest);
    }

    printf("%lld %lld",ans_min,ans_max);
    return 0;
}
