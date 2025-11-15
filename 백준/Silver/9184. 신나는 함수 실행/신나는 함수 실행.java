import java.util.*;
import java.io.*;

public class Main {
    static int[][][] memo = new int[21][21][21];

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new OutputStreamWriter(System.out));
        while (true) {
            StringTokenizer stringTokenizer = new StringTokenizer(bufferedReader.readLine());
            int a = Integer.parseInt(stringTokenizer.nextToken());
            int b = Integer.parseInt(stringTokenizer.nextToken());
            int c = Integer.parseInt(stringTokenizer.nextToken());
            if (a == -1 && b == -1 && c == -1) {
                break;
            }
            bufferedWriter.write("w(" + a + ", " + b + ", " + c + ") = " + w(a, b, c));
            bufferedWriter.newLine();
        }

        bufferedWriter.close();
    }

    static int w(int a, int b, int c) {
        if (isIn(a, b, c) && memo[a][b][c] != 0) {
            return memo[a][b][c];
        }
        if (a <= 0 || b <= 0 || c <= 0) {
            return 1;
        }
        else if (a > 20 || b > 20 || c > 20) {
            return memo[20][20][20] = w(20, 20, 20);
        }
        else if (a < b && b < c) {
            return memo[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
        }
        else {
            return memo[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
        }
    }

    static boolean isIn(int a, int b, int c) {
        return a > 0 && a <= 20 && b > 0 && b <= 20 && c > 0 && c <= 20;
    }
}