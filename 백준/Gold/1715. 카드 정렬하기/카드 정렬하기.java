import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder stringBuilder = new StringBuilder();
        StringTokenizer stringTokenizer = new StringTokenizer(bufferedReader.readLine());
        int N = Integer.parseInt(stringTokenizer.nextToken());

        Queue<Integer> pq = new PriorityQueue<>();
        for (int i=0; i<N; i++) {
            stringTokenizer = new StringTokenizer(bufferedReader.readLine());
            pq.add(Integer.parseInt(stringTokenizer.nextToken()));
        }

        int answer = 0;
        while (pq.size() > 1) {
            int first = pq.poll();
            int second = pq.poll();
            int sum = first + second;
            answer += sum;
            pq.add(sum);
        }

        System.out.println(answer);
    }
}