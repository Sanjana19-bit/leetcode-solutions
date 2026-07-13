#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];

    // Input array elements
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int index;
    cin >> index;

    if (index >= 0 && index < n) {
        cout << arr[index];
    } else {
        cout << "Invalid Index";
    }

    return 0;
}