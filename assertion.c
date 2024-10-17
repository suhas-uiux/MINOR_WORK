//debugging using assertion
#include <assert.h>
#include <stdio.h>

void process(int *arr, int size) {
    assert(size > 0);  // Array size should be positive(checking)
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}

int main() {
    int arr[] = {1, 2, 3};
    process(arr, 3);  // Works fine
    process(arr, -1); // Assertion fails here because size is invalid
    return 0;
}
-----------------------------------------------------------------------------------
//program correctness
#include <assert.h>
#include <stdio.h>

void sortArray(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    // Check if array is correctly sorted
    for (int i = 0; i < size - 1; i++) {
        assert(arr[i] <= arr[i + 1]);  // Array should be sorted
    }
}

int main() {
    int arr[] = {3, 1, 4, 1, 5, 9};
    sortArray(arr, 6);
    return 0;
}
------------------------------------------------------------------------------------------
// testing 
  #include <assert.h>
#include <stdio.h>

int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

void testFactorial() {
    assert(factorial(0) == 1);  // Testing for n = 0
    assert(factorial(5) == 120);  // Testing for n = 5
    assert(factorial(3) == 6);  // Testing for n = 3
}

int main() {
    testFactorial();
    printf("All tests passed!\n");
    return 0;
}
----------------------------------------------------------------------------------------
