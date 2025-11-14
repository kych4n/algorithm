import java.util.*;

class Solution {
    public long solution(int n, int[] works) {
        long answer = 0;
        Queue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());
        
        for (int work : works) {
            pq.add(work);
        }
        
        for (int i=0; i<n; i++) {
            pq.add(Math.max(pq.poll() - 1, 0));
        }
        
        while (!pq.isEmpty()) {
            int top = pq.poll();
            answer += top * top;
        }
        
        return answer;
    }
}