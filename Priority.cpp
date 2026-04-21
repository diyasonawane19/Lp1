#include <iostream>
using namespace std;

int main() {
    int n, p[10], bt[10], pr[10], wt[10], tat[10];
    float avgwt = 0, avgtat = 0;

    cout << "Enter number of processes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\nProcess ID: ";
        cin >> p[i];
        cout << "Burst Time: ";
        cin >> bt[i];
        cout << "Priority (lower = higher): ";
        cin >> pr[i];
    }

    // Sort by priority
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (pr[j] < pr[i]) {
                swap(pr[i], pr[j]);
                swap(bt[i], bt[j]);
                swap(p[i], p[j]);
            }

    wt[0] = 0;
    for (int i = 1; i < n; i++)
        wt[i] = wt[i - 1] + bt[i - 1];

    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        avgwt += wt[i];
        avgtat += tat[i];
    }

    cout << "\nPID\tPR\tBT\tWT\tTAT\n";
    for (int i = 0; i < n; i++)
        cout << "P" << p[i] << "\t" << pr[i] << "\t" << bt[i]
             << "\t" << wt[i] << "\t" << tat[i] << endl;

    cout << "\nAvg WT = " << avgwt / n;
    cout << "\nAvg TAT = " << avgtat / n;
    return 0;
}

