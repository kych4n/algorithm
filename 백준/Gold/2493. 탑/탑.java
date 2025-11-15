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

        Stack<Tower> s = new Stack<>();
        for (int i=0; i<N; i++) {
            int height = tower[i];
            while (!s.isEmpty() && s.peek().height < height) {
                s.pop();
            }
            if (!s.isEmpty()) {
                int receivedTower = s.peek().id;
                bufferedWriter.write(receivedTower + " ");
            }
            else {
                bufferedWriter.write(0 + " ");
            }
            s.add(new Tower(i+1, height));
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