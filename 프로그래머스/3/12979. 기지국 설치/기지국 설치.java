class Solution {
    public int solution(int n, int[] stations, int w) {
        int answer = 0;
        int needMinApartmentNumber = 1;
        int propagationRange = 2*w+1;

        for (int station : stations) {
            int propagatedLowerBound = station - w;
            int propagatedUpperBound = station + w;
            
            if (needMinApartmentNumber < propagatedLowerBound) {
                int unpropagatedApartmentCount = propagatedLowerBound - needMinApartmentNumber;
                answer += (unpropagatedApartmentCount / propagationRange);
                if (unpropagatedApartmentCount % propagationRange != 0) {
                    answer += 1;
                }
            }
            needMinApartmentNumber = propagatedUpperBound + 1;
        }
        
        if (needMinApartmentNumber <= n) {
            int unpropagatedApartmentCount = n - needMinApartmentNumber + 1;
            answer += (unpropagatedApartmentCount / propagationRange);
            if (unpropagatedApartmentCount % propagationRange != 0) {
                answer += 1;
            }
        }
        
        return answer;
    }
}