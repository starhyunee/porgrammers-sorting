#include <string>
#include <vector>
#include<iostream>
#include<algorithm>

using namespace std;

/* 프로그래머스 고득점 kit - 정렬 - k번째 수 */
vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> original = array;
    for (int i = 0; i < commands.size(); i++) {
        sort(array.begin() + commands[i][0] - 1, array.begin() + commands[i][1]);
        answer.push_back(array[commands[i][2] + commands[i][0] - 2]);
        array = original;
    }
    return answer;
}