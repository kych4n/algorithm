import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stringTokenizer = new StringTokenizer(bufferedReader.readLine());
        int N = Integer.parseInt(stringTokenizer.nextToken());
        stringTokenizer = new StringTokenizer(bufferedReader.readLine());

        int[] arr = new int[N];
        for (int i=0; i<N; i++) {
            arr[i] = Integer.parseInt(stringTokenizer.nextToken());
        }
        Arrays.sort(arr);

        int answer = 0;
        for (int targetIdx=0; targetIdx<N; targetIdx++) {
            int left = 0, right = N-1;
            while (true) {
                if (left == targetIdx) left++;
                if (right == targetIdx) right--;

                if (left >= right) break;

                int target = arr[targetIdx];
                int sum = arr[left] + arr[right];

                if (target > sum) {
                    left++;
                }
                else if (target < sum) {
                    right--;
                }
                else {
                    answer++;
                    break;
                }
            }
        }

        System.out.println(answer);
    }
}