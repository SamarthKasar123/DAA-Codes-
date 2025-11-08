#include <iostream>
#include <algorithm>
using namespace std;

// Structure to store item details
struct Item {
    float value, weight;
};

// Compare function to sort items by value/weight ratio (in descending order)
bool cmp(Item a, Item b) {
    return (a.value / a.weight) > (b.value / b.weight);
}

// Function to calculate maximum value for fractional knapsack
float fractionalKnapsack(int W, Item arr[], int n) {
    // Step 1: Sort items by ratio
    sort(arr, arr + n, cmp);

    float finalValue = 0.0; // To store final result

    // Step 2: Iterate through items
    for (int i = 0; i < n; i++) {
        if (arr[i].weight <= W) {
            // If the item can fit completely
            W -= arr[i].weight;
            finalValue += arr[i].value;
        } else {
            // If only a fraction can be taken
            finalValue += (arr[i].value / arr[i].weight) * W;
            break; // Knapsack is full
        }
    }

    return finalValue;
}

int main() {
    int n;         // Number of items
    int W;         // Knapsack capacity

    cout << "Enter the number of items: ";
    cin >> n;

    Item arr[n];

    cout << "Enter value and weight of each item:\n";
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << ":\n";
        cout << "Value: ";
        cin >> arr[i].value;
        cout << "Weight: ";
        cin >> arr[i].weight;
    }

    cout << "Enter the capacity of knapsack: ";
    cin >> W;

    float maxValue = fractionalKnapsack(W, arr, n);

    cout << "\nMaximum value we can obtain = " << maxValue << endl;

    return 0;
}
