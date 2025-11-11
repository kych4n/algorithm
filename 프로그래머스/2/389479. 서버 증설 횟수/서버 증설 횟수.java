import java.util.*;
import java.util.stream.*;

class Pair {
    public int endTime;
    public int serverCount;
    public Pair(int endTime, int serverCount) {
        this.endTime = endTime;
        this.serverCount = serverCount;
    }
}

class Solution {
    public int solution(int[] players, int m, int k) {
        int result = 0;
        Queue<Pair> q = new LinkedList<>();
        int currentServerCount = 0;
        
        for (int time=0; time<=23; time++) {
            while (!q.isEmpty() && q.peek().endTime < time) {
                currentServerCount -= q.peek().serverCount;
                q.poll();
            }
            int playerCount = players[time];
            int needServerCount = playerCount / m;
            if (needServerCount > currentServerCount) {
                //System.out.println(needServerCount - currentServerCount);
                result += needServerCount - currentServerCount;
                q.offer(new Pair(time + k - 1, needServerCount - currentServerCount));
                currentServerCount += (needServerCount - currentServerCount);
            }
        }
        
        return result;
    }
}