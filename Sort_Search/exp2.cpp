#include "search.h"
int main() {
    const char* files[] = {
        "D:\\Code\\C_CODE\\Sort_Search\\data\\bst1.dat",
        "D:\\Code\\C_CODE\\Sort_Search\\data\\bst2.dat"
    };

    const char* labels[] = {"bst1.dat（第一组）", "bst2.dat（第二组）"};
    int searchKeys[] = {30, 55, 175};
    int deleteKeys[] = {30, 150, 100};

    for (int f = 0; f < 2; ++f) {
        cout << "==============================\n";
        cout << "处理文件：" << labels[f] << "\n";

        int data[100];
        int len = readData(files[f], data, 100);
        if (len <= 0) continue;

        btTree root = buildBST(data, len);

        cout << "\n== 查找元素 ==\n";
        for (int i = 0; i < 3; ++i)
            searchWithTrace(root, searchKeys[i]);

        cout << "\n== 删除元素 ==\n";
        for (int i = 0; i < 3; ++i) {
            cout << "删除 " << deleteKeys[i] << "\n";
            root = deleteNode(root, deleteKeys[i]);
        }

        cout << "\n== 计算 ASL ==\n";
        int totalDepth = 0, nodeCount = 0;
        computeASL(root, 1, totalDepth, nodeCount);
        double asl = (nodeCount == 0) ? 0 : (double)totalDepth / nodeCount;
        cout << "ASL（成功查找平均长度）: " << asl << "\n";
    }

    return 0;
}
