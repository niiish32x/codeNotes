#include<iostream>
using namespace std;

const int N = 1010;

int v[N],w[N];
int n,m;

int dp[N][N];

int main(){
    cin>>n>>m;
    
    for(int i=1;i<=n;i++)
        cin>>v[i]>>w[i];
        
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j] = dp[i-1][j];
            if(j>=v[i])
                dp[i][j] = max(dp[i][j],dp[i][j-v[i]]+w[i]);
        }
    }
    
    cout<<dp[n][m]<<endl;
    
    return 0;
}