import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stringTokenizer = new StringTokenizer(bufferedReader.readLine());
        int N = Integer.parseInt(stringTokenizer.nextToken());
        int M = Integer.parseInt(stringTokenizer.nextToken());
        int[] shorterCount = new int[N+1];

        Map<Integer, List<Integer>> numberToTaller = new HashMap<>();
        for (int i=1; i<=N; i++) {
            numberToTaller.put(i, new ArrayList<>());
        }

        for (int i=0; i<M; i++) {
            stringTokenizer = new StringTokenizer(bufferedReader.readLine());
            int front = Integer.parseInt(stringTokenizer.nextToken());
            int after = Integer.parseInt(stringTokenizer.nextToken());
            shorterCount[after] += 1;
            numberToTaller.get(front).add(after);
        }

        BufferedWriter bufferedWriter = new BufferedWriter(new OutputStreamWriter(System.out));
        Queue<Integer> q = new LinkedList<>();
        for (int i=1; i<=N; i++) {
            if (shorterCount[i] == 0) {
                q.add(i);
            }
        }

        while (!q.isEmpty()) {
            int number = q.poll();
            bufferedWriter.write(number + " ");
            numberToTaller.get(number).forEach(taller -> {
                shorterCount[taller] -= 1;
                if (shorterCount[taller] == 0) {
                    q.add(taller);
                }
            });
        }

        bufferedWriter.close();
    }
}