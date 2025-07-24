#include <string>
#include <vector>

using namespace std;

int getHour(int time) {
    return time / 100;
}

int getMinutes(int time) {
    return time % 100;
}

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    int n = schedules.size();
    for (int i=0; i<n; i++) {
        int hour = getHour(schedules[i]);
        int minutes = getMinutes(schedules[i]);
        if (minutes + 10 >= 60) {
            hour += 1;
            minutes = (minutes + 10) % 60;
        } else {
            minutes += 10;
        }
        int hopeTime = hour*100+minutes;
        bool isPossible = true;
        for (int j=0; j<7; j++) {
            if ((j+startday)%7 == 6 || (j+startday)%7 == 0) {
                continue;
            }
            if (timelogs[i][j] > hopeTime) {
                isPossible = false;
                break;
            }
        }
        if (isPossible) {
            answer += 1;
        }
    }
    return answer;
}