import java.util.*;

class Solution {
    public int solution(int sticker[]) {
        int length = sticker.length;
        if (length <= 3) {
            int result = 0;
            for (int number : sticker) {
                result = Math.max(result, number);
            }
            return result;
        }
        
        int[] dpIncludeFirst = new int[length+1];
        int[] dpNotIncludeFirst = new int[length+1];
        for (int i=1; i<length; i++) {
            dpIncludeFirst[i] = sticker[i-1];
            dpNotIncludeFirst[i] = sticker[i];
        }
        
        
        for (int i=2; i<length; i++) {
            dpIncludeFirst[i] = Math.max(dpIncludeFirst[i-2] + dpIncludeFirst[i], dpIncludeFirst[i-1]);
            dpNotIncludeFirst[i] = Math.max(dpNotIncludeFirst[i-2] + dpNotIncludeFirst[i], dpNotIncludeFirst[i-1]);
        }
        
        return Math.max(dpIncludeFirst[length-1], dpNotIncludeFirst[length-1]);
    }
}