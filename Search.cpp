#include <iostream>
using namespace std;

int sequentialSearch(int arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
            return i;
    }
    return -1;
}
int recursiveSequentialSearch(int arr[], int size, int target, int index = 0)
{
    if (index == size)
        return -1;

    if (arr[index] == target)
        return index;

    return recursiveSequentialSearch(arr, size, target, index + 1);
}

int binarySearchIterative(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target){
            return mid;
        }
        else if (target < arr[mid]){
            right = mid - 1;
        }            
        else{
            left = mid + 1;
        }
    }

    return -1;
}

int binarySearchRecursive(int arr[], int left, int right, int target) {
    if (left > right) {
        return -1;
    }

    int mid = left + (right - left) / 2;

    if (arr[mid] == target) {
        return mid;
    }
    else if (target < arr[mid]) {
        return binarySearchRecursive(arr, left, mid - 1, target);
    }
    else {
        return binarySearchRecursive(arr, mid + 1, right, target);
    }
}


int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 3;

    cout << "Sequential Search (Iterative): " << sequentialSearch(arr, size, target) << endl;
    cout << "Sequential Search (Recursive): " << recursiveSequentialSearch(arr, size, target) << endl;

    cout << "Binary Search (Iterative): " << binarySearchIterative(arr, size, target) << endl;
    cout << "Binary Search (Recursive): " << binarySearchRecursive(arr, 0, size - 1, target) << endl;

    return 0;
}
