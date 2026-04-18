#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int bt[20], p[20], wt[20], tat[20];
    float avgwt = 0, avgtat = 0;

    for (int i = 0; i < n; i++) {
        cout << "Enter Burst Time for Process " << i + 1 << ": ";
        cin >> bt[i];
        p[i] = i + 1;
    }

    // Sort by burst time
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (bt[i] > bt[j]) {
                swap(bt[i], bt[j]);
                swap(p[i], p[j]);
            }
        }
    }

    // Waiting time & turnaround time
    wt[0] = 0;
    for (int i = 1; i < n; i++)
        wt[i] = wt[i - 1] + bt[i - 1];

    for (int i = 0; i < n; i++)
        tat[i] = wt[i] + bt[i];

    // Display results
    cout << "\nProcess\tBT\tWT\tTAT";
    for (int i = 0; i < n; i++) {
        cout << "\nP" << p[i] << "\t" << bt[i] << "\t" << wt[i] << "\t" << tat[i];
        avgwt += wt[i];
        avgtat += tat[i];
    }

    cout << "\n\nAverage Waiting Time = " << avgwt / n;
    cout << "\nAverage Turnaround Time = " << avgtat / n;

    return 0;
}

