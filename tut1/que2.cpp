#include<iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 5, 6, 3, 2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int index = 0; 

    for (int i = 0; i < n; i++) {
        bool pos = false; 

        // Compare with already stored unique elements
        for (int j = 0; j < index; j++) {
            if (arr[i] == arr[j]) {
                pos = true; 
                break;
            }
        }

        // If not duplicate, store it in unique position
        if (!pos) {
            arr[index] = arr[i];
            index++;
        }
    }

    // Print unique elements
    for (int k = 0; k < index; k++) {
        cout << arr[k] << endl;
    }

    return 0;
}
