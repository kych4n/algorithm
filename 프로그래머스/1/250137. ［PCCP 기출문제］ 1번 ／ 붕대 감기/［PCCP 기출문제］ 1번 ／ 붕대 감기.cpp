#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    int currentHealth = health;
    int attackCount = attacks.size();
    for (int i=0; i<attackCount; i++) {
        int timeInterval;
        if (i == 0) {
            timeInterval = attacks[i][0] - 1;
        } else {
            timeInterval = attacks[i][0] - attacks[i-1][0] - 1;
        }
        currentHealth = min(health, currentHealth + timeInterval * bandage[1]);
        currentHealth = min(health, currentHealth + timeInterval / bandage[0] * bandage[2]);
        currentHealth = min(health, currentHealth - attacks[i][1]);
        if (currentHealth <= 0) {
            return -1;
        }
        cout << currentHealth << "\n";
    }
    return currentHealth;
}