import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stringTokenizer = new StringTokenizer(bufferedReader.readLine());
        int N = Integer.parseInt(stringTokenizer.nextToken());
        int K = Integer.parseInt(stringTokenizer.nextToken());

        int[] W = new int[N + 1];
        int[] V = new int[N + 1];
        int[] dp = new int[K + 1];
        for (int i=1; i<=N; i++) {
            stringTokenizer = new StringTokenizer(bufferedReader.readLine());
            W[i] = Integer.parseInt(stringTokenizer.nextToken());;
            V[i] = Integer.parseInt(stringTokenizer.nextToken());;
        }

        for (int i=1; i<=N; i++) {
            for (int j=K; j-W[i]>=0; j--) {
                dp[j] = Math.max(dp[j], dp[j - W[i]] + V[i]);
            }
        }

        System.out.println(dp[K]);
    }
}