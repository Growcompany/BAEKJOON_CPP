#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#include <queue>


int main(){
	int N;

	cin>>N;

	int start, end;
	vector<pair<int, int>> meetings;

	for (int i = 0; i < N; i++) {
        cin >> start >> end;
        meetings.push_back({start, end});
    }

	sort(meetings.begin(), meetings.end());

	int result = 1;
	priority_queue<int> max_class_time;
	max_class_time.push(-meetings[0].second);

	for (int i = 1; i < N; i++) {
        start = meetings[i].first;
        end = meetings[i].second;

        if (-max_class_time.top() <= start) {
            max_class_time.pop();
        } else {
            result++;
        }

        max_class_time.push(-end);
    }

	cout<<result;

	return 0;
}
