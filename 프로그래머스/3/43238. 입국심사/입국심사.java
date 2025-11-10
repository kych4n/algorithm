import java.util.*;
import java.util.stream.*;

class Solution {
    public long solution(int n, int[] times) {
        long result = 1_000_000_000_000_000_000L;
        long start = 1;
        long end = 1_000_000_000_000_000_000L;
        Arrays.sort(times);
        while (start <= end) {
            long mid = (start+end)/2;
            long count = 0;
            for (int time : times) {
                count += (mid / time);
            }
            if (count >= n) {
                result = Math.min(result, mid);
                end = mid - 1;
            }
            // else if (count > n) {
            //     end = mid - 1;
            // }
            else if (count < n) {
                start = mid + 1;
            }
        }
        return result;
    }
}