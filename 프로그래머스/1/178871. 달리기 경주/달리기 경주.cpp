#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <queue>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    map<string, int> name_to_rank;
    map<int, string> rank_to_name;
    int count = players.size();
    for (int i=0; i<count; i++) {
        name_to_rank.insert({players[i], i});
        rank_to_name.insert({i, players[i]});
    }
    for (string calling: callings) {
        int current_rank = name_to_rank[calling];
        string loser = rank_to_name[current_rank-1];
        rank_to_name[current_rank] = loser;
        rank_to_name[current_rank-1] = calling;
        name_to_rank[calling] = current_rank-1;
        name_to_rank[loser] = current_rank;
    }
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
    for (int i=0; i<count; i++) {
        pq.push({i, rank_to_name[i]});
    }
    while (!pq.empty()) {
        string name = pq.top().second;
        pq.pop();
        answer.push_back(name);
    }
    return answer;
}