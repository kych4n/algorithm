import java.util.*;

class Pair {
    int x;
    int y;
    public Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

class Solution {
    static final int MAX = 1000000007;
    static final int UNACCESSIBLE = -1;
    static final int[] dn = {1, 0};
    static final int[] dm = {0, 1};
    
    public int solution(int m, int n, int[][] puddles) {
        int[][] dp = new int[n][m];
        dp[0][0] = 1;
        
        for (int[] puddle : puddles) {
            dp[puddle[1]-1][puddle[0]-1] = UNACCESSIBLE;   
        }
        
        for (int sum=1; sum<=(n-1)+(m+1); sum++) {
            for (int i=0; i<=sum && i<n; i++) {
                int j=sum-i;
                if (isIn(i, j, n, m) && dp[i][j] != UNACCESSIBLE) {
                    if (isIn(i-1, j, n, m) && dp[i-1][j] != UNACCESSIBLE) {
                        dp[i][j] += dp[i-1][j];
                    }
                    if (isIn(i, j-1, n, m) && dp[i][j-1] != UNACCESSIBLE) {
                        dp[i][j] += dp[i][j-1];
                    }
                    dp[i][j] %= MAX;
                }
            }
        }
        
        return dp[n-1][m-1];
    }
    
    private boolean isIn(int x, int y, int n, int m) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }
}