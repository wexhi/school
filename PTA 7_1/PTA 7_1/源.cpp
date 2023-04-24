#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int start, end;
};

bool cmp(const Interval& a, const Interval& b) {
    return a.start < b.start;
}

int main() {
    int n;
    cin >> n;

    vector<Interval> intervals(n);
    for (int i = 0; i < n; i++) {
        cin >> intervals[i].start >> intervals[i].end;
    }

    sort(intervals.begin(), intervals.end(), cmp);

    int start = intervals[0].start;
    int end = intervals[0].end;
    int maxInterval1 = 0;
    int maxInterval2 = 0;

    for (int i = 0; i < n; i++) {
        if (intervals[i].start <= end) {
            end = max(end, intervals[i].end);
            maxInterval1 = max(maxInterval1, end - start);
        }
        else {
            maxInterval2 = max(maxInterval2, intervals[i].start - end);
            start = intervals[i].start;
            end = intervals[i].end;
        }
    }

    cout << maxInterval1 << " " << maxInterval2 << endl;

    return 0;
}
