import java.util.*;
import java.util.stream.*;

class Pair {
    public int i;
    public int j;
    public Pair(int i, int j) {
        this.i = i;
        this.j = j;
    }
}

/*
    지게차를 사용하면 접면에 있는 것만, 크레인을 사용하면 상관없음
*/
class Solution {
    public int solution(String[] storage, String[] requests) {
        int answer = 0;
        int n = storage.length;
        int m = storage[0].length();
        
        char[][] storageArray = new char[n][m];
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                storageArray[i][j] = storage[i].charAt(j);
            }
        }
        
        for (String request : requests) {
            if (request.length() == 1) {
                zige(n, m, storageArray, request.charAt(0));
            }
            else if (request.length() == 2) {
                crane(n, m, storageArray, request.charAt(0));
            }
        }
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                System.out.println(storageArray[i][j]);
                if (storageArray[i][j] != '-') {
                    answer += 1;
                }
            }
        }
        
        return answer;
    }
    
    public void zige(int n, int m, char[][] storage, char request) {
        int[] di = {-1,1,0,0};
        int[] dj = {0,0,-1,1};
        boolean result = false;
        Queue<Pair> q = new LinkedList<>();
        boolean[][] visited = new boolean[n][m];
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (i == 0 || i == n-1 || j ==0 || j == m-1) {
                    if (storage[i][j] == '-') {
                        visited[i][j] = true;
                        storage[i][j] = '-';
                        q.offer(new Pair(i, j));
                    }
                    if (storage[i][j] == request) {
                        visited[i][j] = true;
                        storage[i][j] = '-';
                    }
                }
            }
        }
        
        while (!q.isEmpty()) {
            int cur_i = q.peek().i;
            int cur_j = q.peek().j;
            q.poll();
            for (int idx=0; idx<4; idx++) {
                int new_i = cur_i + di[idx];
                int new_j = cur_j + dj[idx];
                if (isIn(new_i, new_j, n, m) && !visited[new_i][new_j]) {
                    if (storage[new_i][new_j] == '-') {
                        visited[new_i][new_j] = true;
                        q.offer(new Pair(new_i, new_j));
                    }
                    if (storage[new_i][new_j] == request) {
                        visited[new_i][new_j] = true;
                        storage[new_i][new_j] = '-';
                    }
                }
            }
        }
        
    }
    
    public void crane(int n, int m, char[][] storage, char request) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (storage[i][j] == request) {
                    storage[i][j] = '-';
                }
            }
        }
    }
    
    private boolean isIn(int i, int j, int n, int m) {
        return i >= 0 && i < n && j >=0 && j < m;
    }
    
}