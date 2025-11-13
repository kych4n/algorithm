import java.util.*;

class Solution {
    public int[] solution(String[] operations) {
        int[] answer = {0,0};
        
        PriorityQueue<Integer> min_pq = new PriorityQueue<>();
        PriorityQueue<Integer> max_pq = new PriorityQueue<>(Comparator.reverseOrder());
        
        for (String operation : operations) {
            char op = operation.charAt(0);
            int number = Integer.valueOf(operation.substring(2));
            if (op == 'I') {
                min_pq.offer(number);
                max_pq.offer(number);
            }
            else {
                if (number == -1) {
                    max_pq.remove(min_pq.poll());
                }
                else {
                    min_pq.remove(max_pq.poll());
                }
            }
        }
        
        if (!(min_pq.isEmpty() || max_pq.isEmpty())) {
            answer[0] = max_pq.peek();
            answer[1] = min_pq.peek();
        }
        return answer;
    }
}


// class Solution {
//     public int[] solution(String[] operations) {
//         int[] answer = {0, 0};
        
//         PriorityQueue<Integer> min_pq = new PriorityQueue<>();
//         PriorityQueue<Integer> max_pq = new PriorityQueue<>(Comparator.reverseOrder());
//         Map<Integer, Integer> m = new HashMap<>();
        
//         for (String operation : operations) {
//             char op = operation.charAt(0);
//             int number = Integer.valueOf(operation.substring(2));
//             if (op == 'I') {
//                 min_pq.offer(number);
//                 max_pq.offer(number);
//                 m.put(number, m.getOrDefault(number, 0) + 1);
//             }
//             else {
//                 if (number == -1) {
//                     while (!min_pq.isEmpty() && m.getOrDefault(min_pq.peek(), 0) == 0) {
//                         min_pq.poll();
//                     }
//                     if (!min_pq.isEmpty()) {
//                         int target = min_pq.peek();
//                         min_pq.poll();
//                         m.put(target, m.getOrDefault(target, 0) - 1);
//                     }
//                 }
//                 else {
//                     while (!max_pq.isEmpty() && m.getOrDefault(max_pq.peek(), 0) == 0) {
//                         max_pq.poll();
//                     }
//                     if (!max_pq.isEmpty()) {
//                         int target = max_pq.peek();
//                         max_pq.poll();
//                         m.put(target, m.getOrDefault(target, 0) - 1);
//                     }
//                 }
//                 if (min_pq.isEmpty() || max_pq.isEmpty()) {
//                     min_pq.clear();
//                     max_pq.clear();
//                 }
//             }
//         }
//         while (!max_pq.isEmpty() && m.getOrDefault(max_pq.peek(), 0) == 0) {
//             max_pq.poll();
//         }
//         while (!min_pq.isEmpty() && m.getOrDefault(min_pq.peek(), 0) == 0) {
//             min_pq.poll();
//         }
//         if (!min_pq.isEmpty() && !max_pq.isEmpty()) {
//             answer[0] = max_pq.peek();
//             answer[1] = min_pq.peek();
//         }
//         else if (!min_pq.isEmpty()) {
//             answer[0] = min_pq.peek();
//             answer[1] = min_pq.peek();
//         }
//         else if (!max_pq.isEmpty()) {
//             answer[0] = max_pq.peek();
//             answer[1] = max_pq.peek();
//         }
//         return answer;
//     }
// }