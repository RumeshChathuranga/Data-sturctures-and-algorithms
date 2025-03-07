#include <iostream>
#include <vector>

using namespace std;

vector<int> quickSort(vector<int>& arr) {
    int p = arr[0];  // The pivot element
    vector<int> left, right, equal;

    // Partition the array into left, right, and equal
    for (int num : arr) {
        if (num < p) {
            left.push_back(num);
        } else if (num > p) {
            right.push_back(num);
        } else {
            equal.push_back(num);
        }
    }

    // Combine the three arrays
    left.insert(left.end(), equal.begin(), equal.end());
    left.insert(left.end(), right.begin(), right.end());
    return left;
}

int main() {
    int n;
    cin >> n;  // size of array
    vector<int> arr(n);

    // Input array elements
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    
    vector<int> result = quickSort(arr);

    // Output the result
    int length = result.size();
    for (int i = 0; i < length; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
