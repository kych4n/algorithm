import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n, m;
        n = sc.nextInt();
        m = sc.nextInt();

        int[] arr = new int [n+1];
        for (int k=1; k<=n; k++){
            arr[k] = sc.nextInt();
        }

        int[] sum = new int [n+1];
        for (int k=1; k<=n; k++){
            sum[k] = sum[k-1] + arr[k];
        }

        int i, j;
        for (int k=0; k<m; k++){
            i = sc.nextInt();
            j = sc.nextInt();
            System.out.println(sum[j] - sum[i-1]);
        }
    }
}
