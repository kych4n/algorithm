import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer stringTokenizer = new StringTokenizer(bufferedReader.readLine());
        int N = Integer.parseInt(stringTokenizer.nextToken());
        int[] tower = new int[N];
        stringTokenizer = new StringTokenizer(bufferedReader.readLine());
        for (int i=0; i<N; i++) {
            tower[i] = Integer.parseInt(stringTokenizer.nextToken());
        }

        Queue<Tower> pq = new PriorityQueue<>((t1, t2) -> t2.id - t1.id);
        for (int i=0; i<N; i++) {
            int height = tower[i];
            while (!pq.isEmpty() && pq.peek().height < height) {
                pq.poll();
            }
            if (!pq.isEmpty()) {
                int receivedTower = pq.peek().id;
                bufferedWriter.write(receivedTower + " ");
            }
            else {
                bufferedWriter.write(0 + " ");
            }
            pq.add(new Tower(i+1, height));
        }

        bufferedWriter.close();
    }

}

class Tower {
    int id;
    int height;
    public Tower(int id, int height) {
        this.id = id;
        this.height = height;
    }
}