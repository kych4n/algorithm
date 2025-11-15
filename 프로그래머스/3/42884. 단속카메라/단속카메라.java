import java.util.*;

class Solution {
    public int solution(int[][] routes) {
        int carCount = routes.length;
        Arrays.sort(routes, (a, b) -> {
            if (a[1] == b[1]) {
                return a[0] - b[0];
            }
            return a[1] - b[1];
        });
        // for (int[] route : routes) {
        //     System.out.println(route[0] + " " + route[1]);
        // }
        int currentEnd = routes[0][1];
        int cameraCount = 1;
        for (int i=1; i<carCount; i++) {
            int start = routes[i][0];
            int end = routes[i][1];
            if (start <= currentEnd) {
                continue;
            }
            currentEnd = end;
            cameraCount += 1;
        }
        return cameraCount;
    }
}