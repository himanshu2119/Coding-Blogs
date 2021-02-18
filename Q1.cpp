#include<bits/stdc++.h>
using namespace std;

string s;
int dp2[1010][1010];
int rec2(int l,int r){
	if(l>=r)return 1;
	if(dp2[l][r]!=-1){
		return dp2[l][r];
	}
	if(s[l]==s[r]){
		dp2[l][r] = rec2(l+1,r-1);
	}else{
		dp2[l][r] = 0;
	}
	return dp2[l][r];
}

int dp[1010];
int rec(int i){
	if(i<0)return 0;
	if(dp[i]!=-1){
		return dp[i];
	}
	int ans = 1e9;
	for(int j=i;j>=0;j--){
		if(rec2(j,i)){
			ans = min(ans,1+rec(j-1));
		}
	}
	return dp[i]=ans;
}

void solve(){
	cin>>s;
	memset(dp,-1,sizeof(dp));
	memset(dp2,-1,sizeof(dp2));
	for(int i=0;i<s.length();i++){
		for(int j=i;j<s.length();j++){
			rec2(i,j);
		}
	}
	cout<<rec(s.length()-1)<<endl;
}	

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//int _t;cin>>_t;while(_t--)
	solve();
}
