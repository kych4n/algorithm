import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stringTokenizer = new StringTokenizer(bufferedReader.readLine());
        int N = Integer.parseInt(stringTokenizer.nextToken());
        int M = Integer.parseInt(stringTokenizer.nextToken());

        int[] needSolveCount = new int[N+1];
        Map<Integer, List<Integer>> beforeToAfter = new HashMap<>();
        for (int i=1; i<=N; i++) {
            beforeToAfter.put(i, new ArrayList<>());
        }

        for (int i=0; i<M; i++) {
            stringTokenizer = new StringTokenizer(bufferedReader.readLine());
            int a = Integer.parseInt(stringTokenizer.nextToken());
            int b = Integer.parseInt(stringTokenizer.nextToken());
            needSolveCount[b] += 1;
            beforeToAfter.get(a).add(b);
        }

        Queue<Integer> possible = new PriorityQueue<>();
        for (int i=1; i<=N; i++) {
            if (needSolveCount[i] == 0) {
                possible.add(i);
            }
        }

        BufferedWriter bufferedWriter = new BufferedWriter(new OutputStreamWriter(System.out));
        while (!possible.isEmpty()) {
            int number = possible.poll();
            bufferedWriter.write(number + " ");

            beforeToAfter.get(number).forEach(after -> {
                needSolveCount[after]--;
                if (needSolveCount[after] == 0) {
                    possible.add(after);
                }
            });
        }

        bufferedWriter.close();
    }
}