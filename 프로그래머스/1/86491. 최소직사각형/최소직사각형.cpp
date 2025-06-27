#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int greaterValue = 0;
    int lessValue = 0;
    for (int i=0; i<sizes.size(); i++) {
        greaterValue = max(greaterValue, max(sizes[i][0], sizes[i][1]));
        lessValue = max(lessValue, min(sizes[i][0], sizes[i][1]));
    }
    answer = greaterValue * lessValue;
    return answer;
}