#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    set<int> s;
    for (int n : nums) {
        s.insert(n);
    }
    int s_size = s.size();
    int nums_size = nums.size();
    int answer = min(s_size, nums_size/2);
    return answer;
}