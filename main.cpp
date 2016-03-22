/*
 * algo_tp_3/main.cpp
 *
 *   Created on: Mar 22, 2016
 *       Author: Dmitry Ermachenkov
 *      License: free-to-use if you refernce me
 *  Description: ​Дан массив целых чисел А[0..n­1]. Известно, что на интервале [0, m] значения массива
 *  строго возрастают, а на интервале [m, n­1] строго убывают. Найти m за O(log m). n ≤ 10000.
 */

#include <iostream>

using std::cout;
using std::cin;

int* arrayFill(int size);
int groupSearch(int* array, int size);
int binarySearchUnimodal(int* array, int size);

int main(void) {
  int n;
  int* array = NULL;
  cin >> n;
  if (n > 0) {
      array = arrayFill(n);
      cout << groupSearch(array, n);
  }
  else cout << 0;
  delete[] array;
  return 0;
}

int* arrayFill(int size) {
  int* array = new int[size];
  for (int i = 0; i < size; ++i) {
    cin >> array[i];
  }
  return array;
}

int groupSearch(int* array, int size) {
  int posFound = -1;
  int posCurrent = 0;

  for (int i = 1; i < size; i *= 2) {
    if (array[i] <= array[posCurrent]) {
      posFound = posCurrent
          + binarySearchUnimodal(array + posCurrent, i - posCurrent);
      return posFound;
    }
    posCurrent = i;
  }

  if (posCurrent < size && array[size - 1] <= array[posCurrent]
      && posFound == -1) {
    posFound = posCurrent
        + binarySearchUnimodal(array + posCurrent, size - 1 - posCurrent);
    return posFound;
  }
//    cout << "after cycle position found between: [" << posCurrent << ", "
//         << size - 1 << "]" << endl;
  return 0;
}

int binarySearchUnimodal(int* array, int size) {
  int first = 0;
  int last = size;
  int mid;
  while (first < last) {
    mid = (first + last) / 2;
    if (array[mid] > array[mid - 1] && array[mid] > array[mid + 1]) {
      return mid;
    } else if (array[mid] < array[mid + 1] && size >= mid + 1) {
      first = mid+1;
    } else if (array[mid] > array[mid + 1] && size >= mid + 1) {
      last = mid-1;
    }
  }
  return mid;
}
