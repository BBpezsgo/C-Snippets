#include <iostream>
#include <chrono>
#include <unordered_set>

using namespace std;

void printPairs(int arr[], int arr_size, int sum)
{
    unordered_set<int> s;
    for (int i = 0; i < arr_size; i++)
    {
        int temp = sum - arr[i];

        if (s.find(temp) != s.end())
            cout << "Pair with given sum " << sum << " is (" << arr[i] << "," << temp << ")" << "\n";

        s.insert(arr[i]);
    }
};

int main()
{
    // Record start time
    auto start = std::chrono::high_resolution_clock::now();

    int A[] = { 1, 4, 45, 6, 10, 8 };
    int n = 16;
    int arr_size = sizeof(A) / sizeof(A[0]);

    // Function calling
    printPairs(A, arr_size, n);

    // Record end time
    auto finish = chrono::high_resolution_clock::now();

    chrono::duration<double> elapsed = finish - start;
    cout << elapsed.count() << " ms";
};
