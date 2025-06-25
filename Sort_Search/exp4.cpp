#include "sort.h"

int main() {
    const int sizes[] = {100, 1000, 10000};
    const char* files[] = {
        "D:\\Code\\C_CODE\\Sort_Search\\data\\sort100.dat",
        "D:\\Code\\C_CODE\\Sort_Search\\data\\sort1000.dat",
        "D:\\Code\\C_CODE\\Sort_Search\\data\\sort10000.dat"
    };

    const int k = 7;
    for (int i = 0; i < 3; ++i) {
        int n = sizes[i];
        int* data = new int[n];
        int len = readData(files[i], data, n);
        if (len < 0) continue;

        int result[k];
        topKMin(data, len, k, result);

        cout << "==== Top-" << k << " 最小值（数据规模 " << n << "） ====\n";
        printArray(result, k);

        delete[] data;
    }

    return 0;
}
