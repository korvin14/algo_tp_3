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
using std::endl;

int* arrayFill(int size);
void arrayPrint(int* array, int size);
int groupSearch(int* array, int size);
int binarySearch(int* posBegin, int posEnd);

int main(void) {
  int n;
  int* array = NULL;
  cin >> n;
  // array = new int[n];
  array = arrayFill(n);
  cout << groupSearch(array, n) << " just testing" << endl;
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

void arrayPrint(int* array, int size) {
  for (int i = 0; i < size; ++i) {
    cout << array[i];
  }
}

int groupSearch(int* array, int size) {
  int posFound = -1;
  int posCurrent = 0;

  for (int i = 1; i < size; i *= 2) {
    if (array[i] <= array[posCurrent]) {
      cout << "position found between: [" << posCurrent << ", " << i << "]"
           << endl;
      break;
    }
    posCurrent = i;
  }

  if (posCurrent < size && array[size - 1] <= array[posCurrent] && posFound == -1)
    cout << "after cycle position found between: [" << posCurrent << ", "
         << size - 1 << "]" << endl;
  return posFound;
}
