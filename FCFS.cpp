#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int bt[20], wt[20], tat[20];
    float total_wt = 0, total_tat = 0;

    for (int i = 0; i < n; i++) {
        cout << "Enter Burst Time for Process P" << i + 1 << ": ";
        cin >> bt[i];
    }

    wt[0] = 0;

    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        total_wt += wt[i];
        total_tat += tat[i];
    }

    cout << "\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << i + 1 << "\t\t\t" << bt[i] << "\t\t\t" << wt[i] << "\t\t\t" << tat[i] << endl;
    }

    cout << "\nAverage Waiting Time: " << total_wt / n;
    cout << "\nAverage Turnaround Time: " << total_tat / n << endl;

    return 0;
}
