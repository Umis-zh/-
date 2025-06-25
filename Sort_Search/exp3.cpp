#include "sort.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

#include <chrono>
using namespace std::chrono;

void testSort(const char* name, void (*sortFunc)(int[], int), int data[], int n, int repeat = 20) {
    double totalTime = 0;
    int* copy = new int[n];

    for (int i = 0; i < repeat; ++i) {
        memcpy(copy, data, sizeof(int) * n);

        auto start = high_resolution_clock::now();
        sortFunc(copy, n);
        auto end = high_resolution_clock::now();

        totalTime += duration<double, micro>(end - start).count();
    }

    printf("%-10s: %8.3f 微秒（%d 次平均）\n", name, totalTime / repeat, repeat);
    delete[] copy;
}


// quickSort 需要另外一个适配器函数（带 low, high 参数）
void quickSortWrapper(int arr[], int n) {
    quickSort(arr, 0, n - 1);
}

int main() {
    const int sizes[] = {100, 1000, 10000};
    const char* files[] = {
        "D:\\Code\\C_CODE\\Sort_Search\\data\\sort100.dat",
        "D:\\Code\\C_CODE\\Sort_Search\\data\\sort1000.dat",
        "D:\\Code\\C_CODE\\Sort_Search\\data\\sort10000.dat"
    };

    for (int i = 0; i < 3; ++i) {
        int n = sizes[i];
        int* data = new int[n];
        int len = readData(files[i], data, n);
        if (len < 0) {
            delete[] data;
            continue;
        }

        cout << "==== 测试数据规模：" << n << " ====\n";
        testSort("插入排序", insertionSort, data, len);
        testSort("希尔排序", shellSort, data, len);
        testSort("冒泡排序", bubbleSort, data, len);
        testSort("快速排序", quickSortWrapper, data, len);
        testSort("选择排序", selectionSort, data, len);
        testSort("堆排序", heapSort, data, len);
        testSort("归并排序", mergeSortUp, data, len);
        cout << endl;

        delete[] data;
    }

    return 0;
}