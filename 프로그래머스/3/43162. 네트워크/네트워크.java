import java.util.*;

class Solution {
    int[] parent = new int[200];
    
    public int solution(int n, int[][] computers) {
        int answer = 0;
        
        for (int i=0; i<n; i++) {
            parent[i] = i;
        }
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (computers[i][j] == 1) {
                    union(i, j);
                }
            }
        }
        
        Set<Integer> s = new HashSet<>();
        for (int i=0; i<n; i++) {
            //System.out.println(parent[i]);
            s.add(find(parent[i]));
        }
        
        answer = s.size();
        return answer;
    }
    
    public void union(int x, int y) {
        x = find(x);
        y = find(y);
        
        if (x <= y) {
            parent[y] = x;
        }
        else {
            parent[x] = y;
        }
    }
    
    public int find(int x) {
        if (x == parent[x]) {
            return x;    
        }
        return find(parent[x]);
    }

}