import java.util.*;

class Solution {
    public int solution(int[] A, int[] B) {
        int answer = 0;
        Queue<Integer> aq = new PriorityQueue<>();
        Queue<Integer> bq = new PriorityQueue<>();
        for (int a : A) {
            aq.add(a);
        }
        for (int b : B) {
            bq.add(b);
        }
        while (!aq.isEmpty() && !bq.isEmpty()) {
            int atop = aq.peek();
            int btop = bq.peek();
            if (atop < btop) {
                answer += 1;
                aq.poll();
                bq.poll();
            }
            else if (atop == btop) {
                bq.poll();
            }
            else {
                bq.poll();
            }
        }
        return answer;
    }
}