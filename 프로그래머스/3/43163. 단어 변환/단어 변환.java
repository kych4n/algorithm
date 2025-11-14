import java.util.*;

class Solution {
    public int solution(String begin, String target, String[] words) {
        int[] answer = {100};
        Set<String> visited = new HashSet<>();        
        bt(begin, target, words, visited, answer);
        
        if (answer[0] == 100) {
            answer[0] = 0;
        }
        return answer[0];
    }
    
    public void bt(String current, String target, String[] words, Set<String> visited, int[] answer) {
        System.out.println(current + " " + target + " " + visited.size());
        if (current.compareTo(target) == 0) {
            answer[0] = Math.min(answer[0], visited.size());
            return;
        }
        for (String word : words) {
            if (!visited.contains(word)) {
                if (!isDifferenceOne(current, word)) {
                    continue;
                }
                visited.add(word);
                bt(word, target, words, visited, answer);
                visited.remove(word);
            }
        }
    }
    
    public boolean isDifferenceOne(String a, String b) {
        int len = a.length();
        int difference = 0;
        for (int i=0; i<len; i++) {
            if (a.charAt(i) != b.charAt(i)) {
                difference += 1;
            }
        }
        return difference == 1;
    }
}