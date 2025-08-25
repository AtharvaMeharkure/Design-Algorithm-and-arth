#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int N, int W, int val[], int wt[]) {
    int dp[N+1][W+1];

    // Initialize base cases
    for (int i = 0; i <= N; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i-1] <= w)
                dp[i][w] = max(dp[i-1][w], val[i-1] + dp[i-1][w - wt[i-1]]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }

    return dp[N][W]; // maximum value
}

int main() {
    int N;
    scanf("%d", &N);

    int val[N], wt[N];
    
    // Read values
    for (int i = 0; i < N; i++)
        scanf("%d", &val[i]);
    
    // Read weights
    for (int i = 0; i < N; i++)
        scanf("%d", &wt[i]);
    
    int W;
    scanf("%d", &W);

    printf("%d\n", knapsack(N, W, val, wt));
    return 0;
}
