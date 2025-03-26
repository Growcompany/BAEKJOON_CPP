#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    vector<int> nums;
    vector<int> LIS;
    vector<int> backtrace;
    vector<int> result;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m;
        nums.push_back(m);
    }

    for (int i = 0; i < nums.size(); i++) {
        if (LIS.empty() || LIS.back() < nums[i]) {
            LIS.push_back(nums[i]);
            backtrace.push_back(LIS.size()-1);
        } else {
            int idx = lower_bound(LIS.begin(), LIS.end(), nums[i]) - LIS.begin();
            LIS[idx] = nums[i];
            backtrace.push_back(idx);
        }
    }

	int temp = LIS.size() - 1;
	for (int i = backtrace.size() - 1; i >= 0; i--) {
		if (backtrace[i] == temp) { 
			result.push_back(nums[i]);
			temp--; 
		}
	}
	reverse(result.begin(), result.end());
	

    cout << result.size() << "\n";
	for(const auto& num : result)
	{
		cout<<num<<" ";
	}

    return 0;
}
