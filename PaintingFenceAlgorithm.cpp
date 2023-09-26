#include <bits/stdc++.h> 

#define MOD 1000000007

int add(int a, int b){
    return (a%MOD + b%MOD)%MOD;
}

int mul(int a, int b){
    return ((a%MOD) * 1LL * (b%MOD))%MOD;
}

int solve(int n, int k, vector<int> &dp) {
    //base case
    if(n == 1){
        return k;
    }

    if(n == 2){
        return mul(k,k);
    }

    if(dp[n] != -1)
        return dp[n];

    dp[n] = add(mul(solve(n-2, k, dp), k-1) , mul(solve(n-1, k, dp), k-1));

    return dp[n];
}

int solveTab(int n, int k) {
    vector<int> dp(n+1, -1);
    dp[1] = k;
    dp[2] = mul(k, k);

    for(int i = 3; i <= n; i++) {
        dp[i] = add(mul(dp[i-2], k-1), mul(dp[i-1], k-1));
    }

    return dp[n];
}

int solveFast(int n, int k){
    int prev2 = k;
    int prev1 = mul(k,k);

    int curr = 0;

    for(int i = 3; i <= n; i++) {
        curr = add(mul(prev2, k-1), mul(prev1, k-1));
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int numberOfWays(int n, int k) {
    //vector<int> dp(n+1, -1);
    return solveFast(n, k);
}