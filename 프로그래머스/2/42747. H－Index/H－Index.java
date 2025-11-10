import java.util.*;

class Solution {
    public int solution(int[] citations) {
        Arrays.sort(citations);
        int length = citations.length;
        int start = 0;
        int end = citations[length - 1];
        int result = 0;
        for (int h = end; h >= start; h--) {
            int idx = Arrays.binarySearch(citations, h);
            if (idx < 0) {
                idx *= -1;
                idx -= 1;
            }
            int ge = length - idx;
            if (ge >= h) {
                result = h;
                break;
            }
        }
        return result;
    }
}