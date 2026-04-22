#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, tq;
    cout << "Enter number of processes: ";
    cin >> n;

    int at[n], bt[n], rt[n], wt[n] = {0}, tat[n] = {0};

    for (int i = 0; i < n; i++) {
        cout << "Enter Arrival Time and Burst Time for P" << i + 1 << ": ";
        cin >> at[i] >> bt[i];
        rt[i] = bt[i];
    }

    cout << "Enter Time Quantum: ";
    cin >> tq;

    int t = 0;
    bool done;

    do {
        done = true;
        for (int i = 0; i < n; i++) {
            if (rt[i] > 0 && at[i] <= t) {
                done = false;
                int run = min(rt[i], tq);
                t += run;
                rt[i] -= run;

                if (rt[i] == 0) {
                    tat[i] = t - at[i];
                    wt[i] = tat[i] - bt[i];
                }
            }
        }
    } while (!done);

    float total_wt = 0, total_tat = 0;
    cout << "\nProcess\tWT\tTAT\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << i + 1 << "\t" << wt[i] << "\t" << tat[i] << endl;
        total_wt += wt[i];
        total_tat += tat[i];
    }

    cout << "\nAverage Waiting Time: " << total_wt / n;
    cout << "\nAverage Turnaround Time: " << total_tat / n << endl;

    return 0;
}

