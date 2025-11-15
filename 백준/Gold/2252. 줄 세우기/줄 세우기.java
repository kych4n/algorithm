import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stringTokenizer = new StringTokenizer(bufferedReader.readLine());
        int N = Integer.parseInt(stringTokenizer.nextToken());
        int M = Integer.parseInt(stringTokenizer.nextToken());

        Map<Integer, Integer> numberToShorterCount = new HashMap<>();
        Map<Integer, List<Integer>> numberToTaller = new HashMap<>();
        for (int i=1; i<=N; i++) {
            numberToShorterCount.put(i, 0);
            numberToTaller.put(i, new ArrayList<>());
        }
        for (int i=0; i<M; i++) {
            stringTokenizer = new StringTokenizer(bufferedReader.readLine());
            int front = Integer.parseInt(stringTokenizer.nextToken());
            int after = Integer.parseInt(stringTokenizer.nextToken());
            numberToShorterCount.put(after, numberToShorterCount.getOrDefault(after, 0)+1);
            numberToTaller.get(front).add(after);
        }

        BufferedWriter bufferedWriter = new BufferedWriter(new OutputStreamWriter(System.out));
        for (int i=0; i<N; i++) {
            for (Map.Entry<Integer, Integer> entry : numberToShorterCount.entrySet()) {
                int number = entry.getKey();
                int shortCount = entry.getValue();
                if (shortCount == 0) {
                    bufferedWriter.write(number + " ");
                    numberToShorterCount.put(number, shortCount - 1);
                    numberToTaller.get(number).forEach(taller -> numberToShorterCount.put(taller, numberToShorterCount.get(taller)-1));
                    break;
                }
            }
        }
        bufferedWriter.close();
    }
}