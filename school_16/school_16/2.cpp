#include<iostream>
#include<vector>
using namespace std;


bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main()
{
	int min, max;
	cin >> min >> max;
	int count = 0;
    
    vector<int> arr;

    for (int i = min; i <= max; i++)
    {
        if (isPrime(i)) 
        {
			count++;
            arr.push_back(i);
            
		}
	}

    cout << count << endl;

    int sum = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
    }

    cout << sum << endl;

	system("pause");
	return 0;
}