#include <iostream>
using namespace std;

// Recursive Fibonacci function
int fibRec(int n) {
    if (n <= 1)
        return n;
    return fibRec(n - 1) + fibRec(n - 2);
}

// Non-recursive Fibonacci function
void fibNonRec(int n) {
    int a = 0, b = 1, c;
    cout << a << " ";
    if (n > 1) cout << b << " ";
    for (int i = 2; i < n; i++) {
        c = a + b;
        cout << c << " ";
        a = b;
        b = c;
    }
}

// Main function
int main() {
    int n;
    cout << "Enter number of terms: ";
    cin >> n;

    cout << "\nFibonacci Series (Recursive): ";
    for (int i = 0; i < n; i++)
        cout << fibRec(i) << " ";

    cout << "\n\nFibonacci Series (Non-Recursive): ";
    fibNonRec(n);

    cout << "\n\nRecursive Time Complexity: O(2^n)";
    cout << "\nRecursive Space Complexity: O(n)";
    cout << "\nNon-Recursive Time Complexity: O(n)";
    cout << "\nNon-Recursive Space Complexity: O(1)\n";

    return 0;
}
