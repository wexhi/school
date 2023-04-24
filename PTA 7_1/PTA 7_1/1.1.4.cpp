#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class WorkTime
{
public:
	WorkTime(int start_time, int end_time)
	{
		this->start_time = start_time;
		this->end_time = end_time;
	}

	int start_time;
	int end_time;
};

int cmp(WorkTime a, WorkTime b)
{
	return a.start_time < b.start_time;
}


int main()
{
	int n;
	cin >> n;

	vector<WorkTime> work_time;
	for (int i = 0; i < n; i++)
	{
		int start_time, end_time;
		cin >> start_time >> end_time;
		work_time.push_back(WorkTime(start_time, end_time));
	}

	sort(work_time.begin(), work_time.end(), cmp);

	int start = work_time[0].start_time;
	int end = work_time[0].end_time;
	int work = 0;
	int rest = 0;

	for (int i = 0; i < n; i++)
	{
		if (work_time[i].start_time <= end)
		{
			end = max(end, work_time[i].end_time);
			work = max(work, end - start);
		}
		else
		{
			rest = max(rest, work_time[i].start_time - end);
			start = work_time[i].start_time;
			end = work_time[i].end_time;
		}
	}

	cout << work << " " << rest << endl;

	system("pause");
	return 0;
}