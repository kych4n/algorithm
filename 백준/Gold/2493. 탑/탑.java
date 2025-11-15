import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder stringBuilder = new StringBuilder();
        StringTokenizer stringTokenizer = new StringTokenizer(bufferedReader.readLine());
        int N = Integer.parseInt(stringTokenizer.nextToken());
        int[] tower = new int[N];
        stringTokenizer = new StringTokenizer(bufferedReader.readLine());
        for (int i=0; i<N; i++) {
            tower[i] = Integer.parseInt(stringTokenizer.nextToken());
        }

        Deque<Tower> s = new ArrayDeque<>();
        for (int i=0; i<N; i++) {
            int height = tower[i];
            while (!s.isEmpty() && s.peek().height < height) {
                s.pop();
            }
            if (!s.isEmpty()) {
                int receivedTower = s.peek().id;
                stringBuilder.append(receivedTower);
            }
            else {
                stringBuilder.append(0);
            }
            stringBuilder.append(" ");
            s.push(new Tower(i+1, height));
        }
        System.out.println(stringBuilder);
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