import java.util.*;
import java.util.stream.*;

class Solution {
    public String alphabet = "abcdefghijklmnopqrstuvwxyz";

    public String solution(long n, String[] bans) {

        // 1. ban 정렬: 길이 먼저, 그 다음 사전순
        Arrays.sort(bans,
                Comparator.comparingInt(String::length)
                          .thenComparing(String::compareTo));

        long target = n - 1;

        // 2. ban들을 순서 위치로 환산해 target 조정
        for (String ban : bans) {
            long loc = getLocation(ban);
            if (loc <= target) target++;
        }

        // 3. target에 해당하는 문자열 생성
        return getString(target);
    }

    // -------------------------------------------------------------
    // 문자열의 절대 위치 계산
    // -------------------------------------------------------------
    public long getLocation(String s) {
        int len = s.length();
        long loc = 0;

        // 1) 자신보다 짧은 길이 문자열들의 개수 먼저 누적
        for (int l = 1; l < len; l++) {
            loc += pow26(l);
        }

        // 2) 같은 길이 내에서 base-26 값 계산
        for (int i = 0; i < len; i++) {
            int idx = s.charAt(i) - 'a';
            loc += idx * pow26(len - i - 1);
        }

        return loc;
    }

    // -------------------------------------------------------------
    // n번째 문자열 생성
    // -------------------------------------------------------------
    public String getString(long n) {

        // 1) 문자열 길이 결정
        int len = 1;
        long blockSize = 26;   // 길이가 len인 문자열 개수
        long sum = 26;         // 누적 수

        while (n >= sum) {
            len++;
            blockSize *= 26;
            sum += blockSize;
        }

        // 2) len 길이 블록에서 n의 위치 보정
        long offset = n - (sum - blockSize);

        // 3) offset을 base-26로 변환
        char[] chars = new char[len];
        for (int i = len - 1; i >= 0; i--) {
            int digit = (int)(offset % 26);
            chars[i] = (char)('a' + digit);
            offset /= 26;
        }

        return new String(chars);
    }

    // -------------------------------------------------------------
    public long pow26(int x) {
        long r = 1;
        while (x-- > 0) r *= 26;
        return r;
    }
}
