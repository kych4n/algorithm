import java.util.*;
import java.util.stream.*;

class Solution {
    public int solution(int[][] triangle) {
        int height = triangle.length;
        int[][] triangleSum = new int[height][height];
        //System.out.println(height);
        triangleSum[0][0] = triangle[0][0];
        //System.out.println(triangleSum.get(0).get(0));
        for (int h=0; h<height-1; h++) {
            for (int w=0; w<=h; w++) {
                triangleSum[h+1][w] = Math.max(triangleSum[h+1][w], triangleSum[h][w] + triangle[h+1][w]);
                triangleSum[h+1][w+1] = Math.max(triangleSum[h+1][w+1], triangleSum[h][w] + triangle[h+1][w+1]);
            }
        }
        
        int answer = 0;
        for (int s : triangleSum[height-1]) {
            answer = Math.max(answer, s);
        }
        return answer;
    }
}