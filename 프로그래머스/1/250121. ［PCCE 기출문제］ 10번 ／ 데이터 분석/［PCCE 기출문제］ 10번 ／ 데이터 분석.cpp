#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<string, int> mapping = {{"code", 0}, {"date", 1}, {"maximum", 2}, {"remain", 3}};

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    vector<vector<int>> filtered;
    int extIndex = mapping[ext];
    int sortIndex = mapping[sort_by];
    for (vector<int> datum: data) {
        if (datum[extIndex] < val_ext) {
            filtered.push_back(datum);
        }
    }
    sort(filtered.begin(), filtered.end(), [sortIndex](const vector<int>& a, const vector<int>& b) { return a[sortIndex] < b[sortIndex]; });
    return filtered;
}