#include <iostream>
using namespace std;

void task1() {
    cout << "Task 1: " << endl;
    int a = 1, b = 100, n = 3;
    int *pB = &b;
    int *pA = &a;
    cout << "Multiples of " << n << " in the interval [" << *pA << ";" << *pB << "]: ";
    while (*pA <= *pB) {
        if (*pA % n == 0) {
            cout << *pA << " ";
        }
        (*pA)++;
    }
    cout << endl;
}

void task2() {
    cout << "Task 2: " << endl;
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *pA = a;
    cout << "Array: ";
    for (int i = 0; i < 10; i++) {
        cout << *pA << " ";
        (*pA)++;
    }
    cout << endl;
    pA = a;
    cout << "Array after incrementing by 1: ";
    for (int i = 0; i < 10; i++) {
        cout << *pA << " ";
        pA++;
    }
    cout << endl;
    pA = a;
    cout << "Array after reverse: ";
    for (int i = 9; i >= 0; i--) {
        cout << *(pA + i) << " ";
    }
    cout << endl;
}

void task3() {
    cout << "Task 3: " << endl;
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int b[5] = {3, 4, 5, 6, 7};
    int *pA = a;
    int *pB = b;
    int n = 10;
    int m = 5;
    for (int i = 0; i <= n - m; i++) {
        bool isSubset = true;
        for (int j = 0; j < m; j++) {
            if (*(pA + i + j) != *(pB + j)) {
                isSubset = false;
                break;
            }
        }
        if (isSubset) {
            cout << "Array B is a subset of array A starting at index " << i << endl;
            return;
        }
    }
    cout << "Array B is not a subset of array A" << endl;
}

void task4() {
    cout << "Task 4: " << endl;
    int n = 10;
    int *a = new int[n];
    for (int i = 0; i < n; i++) {
        a[i] = i - 5;
    }
    int *pA = a;
    cout << "Array: ";
    for (int i = 0; i < n; i++) {
        cout << *pA << " ";
        pA++;
    }
    cout << endl;
    pA = a;
    int m = 0;
    for (int i = 0; i < n; i++) {
        if (*(pA + i) >= 0) {
            m++;
        }
    }
    int *b = new int[m];
    int *pB = b;
    for (int i = 0; i < n; i++) {
        if (*(pA + i) >= 0) {
            *pB = *(pA + i);
            pB++;
        }
    }
    cout << "Array without negative numbers: ";
    pB = b;
    for (int i = 0; i < m; i++) {
        cout << *pB << " ";
        pB++;
    }
    cout << endl;
    delete[] a;
    delete[] b;
}

void task5() {
    cout << "Task 5: " << endl;
    int n = 10;
    int *a = new int[n];
    for (int i = 0; i < n; i++) {
        a[i] = i;
    }
    int *pA = a;
    cout << "Array: ";
    for (int i = 0; i < n; i++) {
        cout << *pA << " ";
        pA++;
    }
    cout << endl;
    pA = a;
    int m = 5;
    int *b = new int[m];
    for (int i = 0; i < m; i++) {
        b[i] = i + 10;
    }
    int *pB = b;
    int *c = new int[n + m];
    int *pC = c;
    for (int i = 0; i < n; i++) {
        *pC = *pA;
        pC++;
        pA++;
    }
    for (int i = 0; i < m; i++) {
        *pC = *pB;
        pC++;
        pB++;
    }
    cout << "Array after adding block of elements: ";
    pC = c;
    for (int i = 0; i < n + m; i++) {
        cout << *pC << " ";
        pC++;
    }
    cout << endl;
    delete[] a;
    delete[] b;
    delete[] c;
}

void task6() {
    cout << "Task 6: " << endl;
    int n = 10;
    int *a = new int[n];
    for (int i = 0; i < n; i++) {
        a[i] = i;
    }
    int *pA = a;
    cout << "Array: ";
    for (int i = 0; i < n; i++) {
        cout << *pA << " ";
        pA++;
    }
    cout << endl;
    pA = a;
    int m = 5;
    int *b = new int[m];
    for (int i = 0; i < m; i++) {
        b[i] = i + 10;
    }
    int *pB = b;
    int *c = new int[n + m];
    int *pC = c;
    int k = 3;
    for (int i = 0; i < k; i++) {
        *pC = *pA;
        pC++;
        pA++;
    }
    for (int i = 0; i < m; i++) {
        *pC = *pB;
        pC++;
        pB++;
    }
    for (int i = k; i < n; i++) {
        *pC = *pA;
        pC++;
        pA++;
    }
    cout << "Array after inserting block of elements: ";
    pC = c;
    for (int i = 0; i < n + m; i++) {
        cout << *pC << " ";
        pC++;
    }
    cout << endl;
    delete[] a;
    delete[] b;
    delete[] c;
}

void task7() {
    cout << "Task 7: " << endl;
    int n = 10;
    int *a = new int[n];
    for (int i = 0; i < n; i++) {
        a[i] = i;
    }
    int *pA = a;
    cout << "Array: ";
    for (int i = 0; i < n; i++) {
        cout << *pA << " ";
        pA++;
    }
    cout << endl;
    pA = a;
    int m = 5;
    int k = 3;
    int *c = new int[n - m];
    int *pC = c;
    for (int i = 0; i < k; i++) {
        *pC = *pA;
        pC++;
        pA++;
    }
    pA += m;
    for (int i = k; i < n - m; i++) {
        *pC = *pA;
        pC++;
        pA++;
    }
    cout << "Array after deleting block of elements: ";
    pC = c;
    for (int i = 0; i < n - m; i++) {
        cout << *pC << " ";
        pC++;
    }
    cout << endl;
    delete[] a;
    delete[] c;
}

void task2_1() {
    cout << "Task 2_1: " << endl;
    int a[8] = {-9, 8, 0, 9, 4, -3, 0, 7};
    int *pA = a;
    int n = 8;
    int *pB = pA + n - 1;
    while (pA < pB) {
        if (*pA < 0) {
            pA++;
        } else if (*pB >= 0) {
            pB--;
        } else {
            int temp = *pA;
            *pA = *pB;
            *pB = temp;
            pA++;
            pB--;
        }
    }
    cout << "Array: ";
    pA = a;
    for (int i = 0; i < n; i++) {
        cout << *pA << " ";
        pA++;
    }
    cout << endl;
}

void task2_2() {
    cout << "Task 2_2: " << endl;
    int a[5] = {1, 3, 5, 7, 9};
    int b[5] = {2, 4, 6, 8, 10};
    int *pA = a;
    int *pB = b;
    int n = 5;
    int m = 5;
    int *c = new int[n + m];
    int *pC = c;
    while (pA < a + n && pB < b + m) {
        if (*pA < *pB) {
            *pC = *pA;
            pA++;
        } else {
            *pC = *pB;
            pB++;
        }
        pC++;
    }
    while (pA < a + n) {
        *pC = *pA;
        pA++;
        pC++;
    }
    while (pB < b + m) {
        *pC = *pB;
        pB++;
        pC++;
    }
    cout << "Array C: ";
    pC = c;
    for (int i = 0; i < n + m; i++) {
        cout << *pC << " ";
        pC++;
    }
    cout << endl;
    delete[] c;
}

void task2_3() {
    cout << "Task 2_3: " << endl;
    int a[5] = {1, 3, 5, 7, 9};
    int b[3] = {2, 4, 6};
    int *pA = a;
    int *pB = b;
    int n = 5;
    int m = 3;
    int *c = new int[n];
    int *pC = c;
    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < m; j++) {
            if (*(pA + i) == *(pB + j)) {
                found = true;
                break;
            }
        }
        if (!found) {
            *pC = *(pA + i);
            pC++;
        }
    }
    cout << "Array C: ";
    pC = c;
    for (int i = 0; i < n - m; i++) {
        cout << *pC << " ";
        pC++;
    }
    cout << endl;
    delete[] c;
}

void task2_3_1() {
    cout << "Task 2_3_1: " << endl;
    int a[5] = {1, 3, 5, 7, 9};
    int b[3] = {2, 4, 6};
    int *pA = a;
    int *pB = b;
    int n = 5;
    int m = 3;
    int *c = new int[n + m];
    int *pC = c;
    for (int i = 0; i < n; i++) {
        *pC = *(pA + i);
        pC++;
    }
    for (int i = 0; i < m; i++) {
        *pC = *(pB + i);
        pC++;
    }
    cout << "Array C: ";
    pC = c;
    for (int i = 0; i < n + m; i++) {
        cout << *pC << " ";
        pC++;
    }
    cout << endl;
    delete[] c;
}

void task2_3_2() {
    cout << "Task 2_3_2: " << endl;
    int a[5] = {1, 3, 5, 7, 9};
    int b[3] = {2, 4, 6};
    int *pA = a;
    int *pB = b;
    int n = 5;
    int m = 3;
    int *c = new int[n + m];
    int *pC = c;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (*(pA + i) == *(pB + j)) {
                *pC = *(pA + i);
                pC++;
            }
        }
    }
    cout << "Array C: ";
    pC = c;
    for (int i = 0; i < n + m; i++) {
        cout << *pC << " ";
        pC++;
    }
    cout << endl;
    delete[] c;
}

void task2_3_3() {
    cout << "Task 2_3_3: " << endl;
    int a[5] = {1, 3, 5, 7, 9};
    int b[3] = {2, 4, 6};
    int *pA = a;
    int *pB = b;
    int n = 5;
    int m = 3;
    int *c = new int[n];
    int *pC = c;
    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < m; j++) {
            if (*(pA + i) == *(pB + j)) {
                found = true;
                break;
            }
        }
        if (!found) {
            *pC = *(pA + i);
            pC++;
        }
    }
    cout << "Array C: ";
    pC = c;
    for (int i = 0; i < n - m; i++) {
        cout << *pC << " ";
        pC++;
    }
    cout << endl;
    delete[] c;
}

void task2_3_4() {
    cout << "Task 2_3_4: " << endl;
    int a[5] = {1, 3, 5, 7, 9};
    int b[3] = {2, 4, 6};
    int *pA = a;
    int *pB = b;
    int n = 5;
    int m = 3;
    int *c = new int[m];
    int *pC = c;
    for (int i = 0; i < m; i++) {
        bool found = false;
        for (int j = 0; j < n; j++) {
            if (*(pB + i) == *(pA + j)) {
                found = true;
                break;
            }
        }
        if (!found) {
            *pC = *(pB + i);
            pC++;
        }
    }
    cout << "Array C: ";
    pC = c;
    for (int i = 0; i < m - n; i++) {
        cout << *pC << " ";
        pC++;
    }
    cout << endl;
    delete[] c;
}

void task2_3_5() {
    cout << "Task 2_3_5: " << endl;
    int a[5] = {1, 3, 5, 7, 9};
    int b[3] = {2, 4, 6};
    int *pA = a;
    int *pB = b;
    int n = 5;
    int m = 3;
    int *c = new int[n + m];
    int *pC = c;
    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < m; j++) {
            if (*(pA + i) == *(pB + j)) {
                found = true;
                break;
            }
        }
        if (!found) {
            *pC = *(pA + i);
            pC++;
        }
    }
    for (int i = 0; i < m; i++) {
        bool found = false;
        for (int j = 0; j < n; j++) {
            if (*(pB + i) == *(pA + j)) {
                found = true;
                break;
            }
        }
        if (!found) {
            *pC = *(pB + i);
            pC++;
        }
    }
    cout << "Array C: ";
    pC = c;
    for (int i = 0; i < n + m; i++) {
        cout << *pC << " ";
        pC++;
    }
    cout << endl;
    delete[] c;
}