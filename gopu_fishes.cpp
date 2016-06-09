#include<bits/stdc++.h>
#define test(t) while(t--)
#define s(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define p(n) printf("%lld\n",n)
#define rep(i,a,n) for(i=a;i<=n;i++)
#define vi vector<int>
#define vii vector< vector<int> >
#define vpii vector< pair<int,int> >
#define mii map<int,int>
#define pb push_back
#define inf 1000000000LL
#define mp make_pair
#define MOD 1000000007LL
#define lim 1e18
#define ll  long long
#define gc getchar_unlocked
#define N 32769
using namespace std;
int main(void){
    int power[16];
	double dp[N];
    double C[17][17];
    double ans;
	int t,n,i,j;
	power[0]=1;
	for(i=1;i<=15;++i)
        power[i]=power[i-1]*2;
	s(t);
	while(t--){
		ans=0.0;
		s(n);
		for(i=0;i<=N;++i)
            dp[i]=0.0;
		for(i=1;i<=n;++i){
			for(j=1;j<=n;++j){
				scanf("%lf",&C[i][j]);
			}
		}

        vector<int>v;
	    for(i=1;i<(1<<n);++i){
            v.clear();
	    	int sum=0;
	    	int bit;
	    	for(j=0;j<n;++j){
	    		if(i&(1<<j)){
                    v.pb(j+1);
                    sum=sum+power[j];
	    	    }
	    	}
	        bit=v.size();
	    	if(bit==1)
                dp[sum]=C[1][v[0]];
	    	else
                for(j=bit-1;j>=0;--j)
                    dp[sum]=dp[sum]+dp[sum-power[v[j]-1]]*C[bit][v[j]];
	    }
		printf("%.6lf\n",dp[power[n]-1]);
	}
	return 0;
}
