import java.util.*;
import java.io.*;

public class Main {

    static final int MAXCOST = 100000;

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stringTokenizer = new StringTokenizer(bufferedReader.readLine());
        int N = Integer.parseInt(stringTokenizer.nextToken());
        stringTokenizer = new StringTokenizer(bufferedReader.readLine());
        int M = Integer.parseInt(stringTokenizer.nextToken());

        Map<Integer, Map<Integer, Integer>> edge = new HashMap<>();
        for (int i=1; i<=N; i++) {
            edge.put(i, new HashMap<>());
        }
        for (int i=0; i<M; i++) {
            stringTokenizer = new StringTokenizer(bufferedReader.readLine());
            int start = Integer.parseInt(stringTokenizer.nextToken());
            int end = Integer.parseInt(stringTokenizer.nextToken());
            int cost = Integer.parseInt(stringTokenizer.nextToken());
            edge.get(start).put(end, Math.min(edge.get(start).getOrDefault(end, MAXCOST), cost));
        }

        stringTokenizer = new StringTokenizer(bufferedReader.readLine());
        int start = Integer.parseInt(stringTokenizer.nextToken());
        int end = Integer.parseInt(stringTokenizer.nextToken());
        int[] minCost = new int[N+1];
        int[] parent = new int[N+1];
        Arrays.fill(minCost, 1000000007);
        dijkstra(start, edge, minCost, parent);

        System.out.println(minCost[end]);

        Deque<Integer> dq = new ArrayDeque<>();
        traceReverse(end, start, dq, parent);

        System.out.println(dq.size());

        StringBuilder stringBuilder = new StringBuilder();
        while (!dq.isEmpty()) {
            stringBuilder.append(dq.pollFirst()).append(" ");
        }
        System.out.println(stringBuilder);

    }

    public static void dijkstra(int start, Map<Integer, Map<Integer, Integer>> edge, int[] minCost, int[] parent) {
        minCost[start] = 0;
        parent[start] = start;
        Queue<Integer> q = new LinkedList<>();
        q.add(start);

        while (!q.isEmpty()) {
            int curEnd = q.peek();
            int curCost = minCost[curEnd];
            q.poll();

            for (Map.Entry<Integer, Integer> entry : edge.get(curEnd).entrySet()) {
                int nextEnd = entry.getKey();
                int alphaCost = entry.getValue();
                int nextCost = curCost + alphaCost;
                if (minCost[nextEnd] > nextCost) {
                    minCost[nextEnd] = nextCost;
                    parent[nextEnd] = curEnd;
                    q.add(nextEnd);
                }
            }
        }
    }

    public static void traceReverse(int current, int target, Deque<Integer> dq, int[] parent) {
        if (current == target) {
            dq.addFirst(current);
            return;
        }
        dq.addFirst(current);
        traceReverse(parent[current], target, dq, parent);
    }
}