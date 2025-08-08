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
    auto it = remove_if(data.begin(), data.end(), [extIndex, val_ext](const vector<int>& a){ return a[extIndex] >= val_ext; });
    data.erase(it, data.end());
    sort(data.begin(), data.end(), [sortIndex](const vector<int>& a, const vector<int>& b) { return a[sortIndex] < b[sortIndex]; });
    return data;
}