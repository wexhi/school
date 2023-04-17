#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> names(n);
    map<string, int> m;
    for (int i = 0; i < n; i++) {
        cin >> names[i];
        m[names[i]] = 0; // ³õÊ¼»¯Îª0
    }

    for (int i = 0; i < n; i++) {
        string giver;
        cin >> giver;
        int money, ng;
        cin >> money >> ng;
        if (ng == 0) continue;
        int avg = money / ng;
        m[giver] -= avg * ng;
        for (int j = 0; j < ng; j++) {
            string receiver;
            cin >> receiver;
            m[receiver] += avg;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << names[i] << " " << m[names[i]] << endl;
    }

    system("pause");

    return 0;
}
