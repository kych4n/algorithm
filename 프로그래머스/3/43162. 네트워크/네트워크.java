class Solution {
    public int solution(int n, int[][] computers) {
        int answer = 0;
        
        boolean[] visited = new boolean[n];
        
        for (int i=0; i<n; i++) {
            if (!visited[i]) {
                answer += 1;
                dfs(i, n, computers, visited);
            }
        }
        
        return answer;
    }
    
    public void dfs(int x, int n, int[][] computers, boolean[] visited) {
        visited[x] = true;
        for (int to=0; to<n; to++) {
            if (!visited[to] && computers[x][to] == 1) {
                dfs(to, n, computers, visited);
            }
        }
    }
    
//     int[] parent = new int[200];
    
//     public int solution(int n, int[][] computers) {
//         int answer = 0;
        
//         for (int i=0; i<n; i++) {
//             parent[i] = i;
//         }
        
//         for (int i=0; i<n-1; i++) {
//             for (int j=i+1; j<n; j++) {
//                 if (computers[i][j] == 1) {
//                     union(i, j);
//                 }
//             }
//         }
        
//         Set<Integer> s = new HashSet<>();
//         for (int i=0; i<n; i++) {
//             //System.out.println(parent[i]);
//             s.add(find(parent[i]));
//         }
        
//         answer = s.size();
//         return answer;
//     }
    
//     public void union(int x, int y) {
//         x = find(x);
//         y = find(y);
        
//         if (x <= y) {
//             parent[y] = x;
//         }
//         else {
//             parent[x] = y;
//         }
//     }
    
//     public int find(int x) {
//         if (x == parent[x]) {
//             return x;    
//         }
//         return find(parent[x]);
//     }
}