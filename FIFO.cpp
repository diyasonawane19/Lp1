#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, f;
    cout << "Enter number of pages: ";
    cin >> n;

    vector<int> pages(n);
    cout << "Enter page reference string: ";
    for (int i = 0; i < n; i++)
        cin >> pages[i];

    cout << "Enter number of frames: ";
    cin >> f;

    vector<int> frame(f, -1);
    int pageFaults = 0, front = 0;

    cout << "\nPage\t";
    for (int i = 0; i < f; i++)
        cout << "F" << i + 1 << "\t";
    cout << endl;

    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < f; j++) {
            if (frame[j] == pages[i]) {
                found = true;
                break;
            }
        }

        if (!found) {
            frame[front] = pages[i];
            front = (front + 1) % f;
            pageFaults++;
        }

        cout << pages[i] << "\t";
        for (int j = 0; j < f; j++) {
            if (frame[j] == -1)
                cout << "-\t";
            else
                cout << frame[j] << "\t";
        }
        cout << endl;
    }

    cout << "\nTotal Page Faults: " << pageFaults << endl;
    return 0;
}
