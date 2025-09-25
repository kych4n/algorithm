#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> number_strings;
    for (int n : numbers) {
        string n_str = to_string(n);
        number_strings.push_back(n_str);
    }
    sort(number_strings.begin(), number_strings.end(), compare);
    for (int i=0; i<numbers.size(); i++) {
        answer += number_strings[i];
    }
    if (answer.length() >= 2 && answer[0] == '0' && answer[1] == '0') {
        answer = "0";
    }
    return answer;
}