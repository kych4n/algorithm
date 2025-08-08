#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    unordered_map<string, int> name_to_yearning;
    int count = name.size();
    for (int i=0; i<count; i++) {
        name_to_yearning[name[i]] = yearning[i];
    }
    for (vector<string> picture: photo) {
        int temp_result = 0;
        for (string person: picture) {
            temp_result += name_to_yearning[person];
        }
        answer.push_back(temp_result);
    }
    return answer;
}