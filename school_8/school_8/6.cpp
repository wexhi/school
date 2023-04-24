#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int nums[5];
    for (int i = 0; i < 5; i++) {
        cin >> nums[i];
    }

    int max_val = nums[0];
    int min_val = nums[0];

    for (int i = 1; i < 5; i++) {
        if (nums[i] > max_val) {
            max_val = nums[i];
        }
        if (nums[i] < min_val) {
            min_val = nums[i];
        }
    }

    for (int i = 0; i < 5; i++) {
        double normalized_val = (nums[i] - min_val) / (double)(max_val - min_val);
        cout << fixed << setprecision(6) << normalized_val;
        if (i != 4) {
            cout << "-";
        }
    }
    cout << endl;

    return 0;
}
