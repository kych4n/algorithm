#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int greaterValue = 0;
    int lessValue = 0;
    for (int i=0; i<sizes.size(); i++) {
        if (sizes[i][0] > sizes[i][1]) {
            greaterValue = max(greaterValue, sizes[i][0]);
            lessValue = max(lessValue, sizes[i][1]);
        } else {
            greaterValue = max(greaterValue, sizes[i][1]);
            lessValue = max(lessValue, sizes[i][0]);
        }
        
    }
    answer = greaterValue * lessValue;
    return answer;
}