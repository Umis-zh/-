#include "search.h"
int main() {
    const char* files[] = {
        "D:\\Code\\C_CODE\\Sort_Search\\data\\b1.dat",
        "D:\\Code\\C_CODE\\Sort_Search\\data\\b2.dat"
    };

    const char* labels[] = {"b1.dat（第一组）", "b2.dat（第二组）"};
    int targets[][5] = {
        {30, 5, 100},      // 第一组待查找元素
        {80, 3, 13}        // 第二组待查找元素
    };

    for (int f = 0; f < 2; ++f) {
        cout << "==============================\n";
        cout << "处理文件：" << labels[f] << "\n";

        int data[100];
        int len = readData(files[f], data, 100);
        if (len <= 0) continue;

        for (int i = 0; i < 3; ++i)
            binarySearchTrace(data, 0, len - 1, targets[f][i]);
    }

    return 0;
}
