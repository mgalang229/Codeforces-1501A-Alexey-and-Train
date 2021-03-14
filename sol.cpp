#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<int> a(n), b(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i] >> b[i];
		}
		vector<int> tm(n);
		for (int i = 0; i < n; i++) {
			cin >> tm[i];
		}
		// view the image in this repository for better understanding
		// also, read the problem statement because the needed formula
		// were provided in there
		// create a 'prev' variable to store the previous departure time
		int prev = 0;
		// create a 'total_time' variable to calculate the total time traveled
		int total_time = 0;
		for (int i = 0; i < n; i++) {
			// add the formula to get the exact time travel 
			// station i - 1 to station i to the total time
			total_time += (a[i] - prev + tm[i]);
			// this is the formula to get the staying time in a certain station
			int staying_time = (b[i] - a[i] + 1) / 2;
			if (i < n - 1) {
				// if Alexey hasn't arrived in the n-th station,
				// then add the staying time to the total time
				total_time += staying_time;
			}
			if (total_time < b[i] && i < n - 1) {
				// more importantly, if the total time is less than the
				// departure time and Alexey hasn't arrived in the n-th station yet,
				// then set the total time to the departure time
				total_time = b[i];
			}
			// store the departure time in our 'prev' variable
			// to be used in the next iteration
			prev = b[i];
		}
		cout << total_time << '\n';
	}
	return 0;
}
