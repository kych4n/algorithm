import java.util.*;
import java.util.stream.*;

class Solution {
    public int[] solution(int n, int s) {
        
        int avg = s/n;
        int plus = s%n;
        
        if (avg == 0) {
            int[] temp = {-1};
            return temp;
        }
        else {
            int[] temp = new int[n];
            for (int i=0; i<n; i++) {
                temp[i] = avg;
            }
            for (int i=n-1; i>n-1-plus; i--) {
                temp[i] += 1;
            }
            return temp;
        }
    }
}