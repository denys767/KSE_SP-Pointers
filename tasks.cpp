
/*
Усе через ПОІНТЕРи!!!  якщо "не пішло", тоді через індекси, а потім спробуйте замінити індекси на ПОІНТЕРи

pt = (int*)realloc( void* ps, size_t sz);
переросподіл памяті з адреси ps і копіює sz Байт - повертає нову адресу to pt

Завдання 1
Інтервал [a;b] - надрукувати числа кратні N

Завдання 2
збільшити єлементи масива на 1
2.а - реверс масива в цей же масив

Завдання 3
Написати функцію, яка отримує як аргумент покажчики на два масиви (А і В) і розміри масивів. Функція перевіряє, чи є масив В підмножиною масиву А, і повертає покажчик на початок знайденого фрагмента або повертає 0 у протилежному випадку.

Завдання 4
Написати функцію, яка отримує покажчик на динамічний масив і його розмір. Функція повинна видалити з масиву всі від'ємні числа і повернути покажчик на новий динамічний масив.

Завдання 5
Створити функцію, що дозволяє додавати блок елементів у кінець масиву. (перевиклик №6?)

Завдання 6
Створити функцію, що дозволяє вставляти блок елементів, починаючи з довільного індексу масиву.

Завдання 7
Створити функцію, що дозволяє видаляти блок елементів, починаючи з довільного індексу масиву.
---
1. Негативні значення переставити назад масива, позитивні - уперед, нулі посередині. - в цьому ж масиві! службовий не використовувати.
{-9 8 0 9 4 -3 0 7 }  наприклад { 894700 -9 -3} або як вийшло
гарно б знати допоки у мене позитивні, зкуда починаються негативні

2. Дано два масиви, упорядковані за зростанням: А[n] та B[m]. Сформуйте масив C[n+m], що складається
з елементів масивів А і В, упорядкований за зростанням. Використовуйте синтаксис покажчиків.

3. Дано два масиви: А[n] і B[m]. Необхідно створити масиви, у яких зібрати:
3.1 Елементи обох масивів;
3.2 Загальні елементи двох масивів;
3.3 Елементи масиву A, які не включаються до B;
3.4 Елементи масиву B, які не включаються до A;
3.5 Елементи масивів A і B, які не є загальними для них

може тут вдастся скористатися простішими завданнями для складніших

4. переробити стару задачу в поінтерах - знайти в масиві перший позитивний та останній негативний єлементи, відсортувати єлементи між ними.*/

#include <iostream>
using namespace std;

void task1() {
    cout << "Task 1: " << endl;
    int a = 1, b = 100, n = 3;
    int *pB = &b;
    int *pA = &a;
    // Виводимо числа кратні n в інтервалі [a; b]
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
    // Виводимо масив
    cout << "Array: ";
    for (int i = 0; i < 10; i++) {
        cout << *pA << " ";
        (*pA)++;
    }
    cout << endl;
    pA = a;
    // Виводимо масив після збільшення кожного елемента на 1
    cout << "Array after incrementing by 1: ";
    for (int i = 0; i < 10; i++) {
        cout << *pA << " ";
        pA++;
    }
    cout << endl;
    pA = a;
    // Виводимо масив у зворотному порядку
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
    // Перевіряємо, чи є масив B підмножиною масиву A
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
    // Виводимо масив
    cout << "Array: ";
    for (int i = 0; i < n; i++) {
        cout << *pA << " ";
        pA++;
    }
    cout << endl;
    pA = a;
    int m = 0;
    // Рахуємо кількість невід'ємних елементів
    for (int i = 0; i < n; i++) {
        if (*(pA + i) >= 0) {
            m++;
        }
    }
    int *b = new int[m];
    int *pB = b;
    // Копіюємо невід'ємні елементи в новий масив
    for (int i = 0; i < n; i++) {
        if (*(pA + i) >= 0) {
            *pB = *(pA + i);
            pB++;
        }
    }
    // Виводимо масив без від'ємних чисел
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
    // Виводимо масив
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
    // Додаємо елементи масиву a до нового масиву c
    for (int i = 0; i < n; i++) {
        *pC = *pA;
        pC++;
        pA++;
    }
    // Додаємо елементи масиву b до нового масиву c
    for (int i = 0; i < m; i++) {
        *pC = *pB;
        pC++;
        pB++;
    }
    // Виводимо масив після додавання блоку елементів
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
    // Виводимо масив
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
    // Вставляємо елементи масиву a до індексу k в новий масив c
    for (int i = 0; i < k; i++) {
        *pC = *pA;
        pC++;
        pA++;
    }
    // Вставляємо елементи масиву b в новий масив c
    for (int i = 0; i < m; i++) {
        *pC = *pB;
        pC++;
        pB++;
    }
    // Вставляємо залишок елементів масиву a в новий масив c
    for (int i = k; i < n; i++) {
        *pC = *pA;
        pC++;
        pA++;
    }
    // Виводимо масив після вставки блоку елементів
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
    // Виводимо масив
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
    // Копіюємо елементи масиву a до індексу k в новий масив c
    for (int i = 0; i < k; i++) {
        *pC = *pA;
        pC++;
        pA++;
    }
    pA += m;
    // Копіюємо залишок елементів масиву a в новий масив c
    for (int i = k; i < n - m; i++) {
        *pC = *pA;
        pC++;
        pA++;
    }
    // Виводимо масив після видалення блоку елементів
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
    // Переставляємо негативні значення назад масиву, позитивні - вперед, нулі - посередині
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
    // Виводимо масив
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
    // Об'єднуємо два масиви в один, зберігаючи порядок зростання
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
    // Виводимо об'єднаний масив
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
    // Копіюємо елементи масиву A, які не включаються до B
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
    // Виводимо масив C
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
    // Копіюємо елементи обох масивів в новий масив
    for (int i = 0; i < n; i++) {
        *pC = *(pA + i);
        pC++;
    }
    for (int i = 0; i < m; i++) {
        *pC = *(pB + i);
        pC++;
    }
    // Виводимо масив C
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
    // Копіюємо загальні елементи двох масивів в новий масив
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (*(pA + i) == *(pB + j)) {
                *pC = *(pA + i);
                pC++;
            }
        }
    }
    // Виводимо масив C
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
    // Копіюємо елементи масиву A, які не включаються до B
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
    // Виводимо масив C
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
    // Перевірка елементів масиву b, які не включаються до масиву a
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
    // Виведення масиву c
    for (int i = 0; i < m; i++) {
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
    // Перевірка елементів масиву a, які не включаються до масиву b
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
    // Перевірка елементів масиву b, які не включаються до масиву a
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
    // Виведення масиву c
    for (int i = 0; i < n + m; i++) {
        cout << *pC << " ";
        pC++;
    }
    cout << endl;
    delete[] c;
}