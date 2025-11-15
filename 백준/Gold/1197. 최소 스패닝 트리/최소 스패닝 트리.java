import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stringTokenizer = new StringTokenizer(bufferedReader.readLine());
        int V = Integer.parseInt(stringTokenizer.nextToken());
        int E = Integer.parseInt(stringTokenizer.nextToken());
        Queue<Edge> q = new PriorityQueue<>((e1, e2) -> e1.c - e2.c);
        for (int i=0; i<E; i++) {
            stringTokenizer = new StringTokenizer(bufferedReader.readLine());
            int a = Integer.parseInt(stringTokenizer.nextToken());
            int b = Integer.parseInt(stringTokenizer.nextToken());
            int c = Integer.parseInt(stringTokenizer.nextToken());
            q.add(new Edge(a, b, c));
        }

        int[] parent = new int[V+1];
        for (int i=1; i<=V; i++) {
            parent[i] = i;
        }

        int answer = 0;
        int connectCount = 0;
        while (!q.isEmpty()) {
            int a = q.peek().a;
            int b = q.peek().b;
            int c = q.peek().c;
            q.poll();

            if (find(parent, a) != find(parent, b)) {
                union(parent, a, b);
                answer += c;
                connectCount += 1;

                if (connectCount == V-1) {
                    break;
                }
            }
        }

        BufferedWriter bufferedWriter = new BufferedWriter(new OutputStreamWriter(System.out));
        bufferedWriter.write(String.valueOf(answer));
        bufferedWriter.newLine();
        bufferedWriter.close();
    }

    private static int find(int[] parent, int x) {
        if (x != parent[x]) {
            parent[x] = find(parent, parent[x]);
        }
        return parent[x];
    }

    private static void union(int[] parent, int x, int y) {
        x = find(parent, x);
        y = find(parent, y);

        if (x < y) {
            parent[y] = x;
        }
        else {
            parent[x] = y;
        }
    }

}

class Edge {
    int a;
    int b;
    int c;
    public Edge(int a, int b, int c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }
}