#include <iostream>
#include "GrpAdjLinkedList.h"  // 包含你提供的所有图操作接口
using namespace std;

int main() {
    const char* files[] = {
        "D:\\Code\\C_CODE\\Graph\\grpData\\udg8.grp",
        "D:\\Code\\C_CODE\\Graph\\grpData\\udg115.grp",
        "D:\\Code\\C_CODE\\Graph\\grpData\\dg6.grp",
        "D:\\Code\\C_CODE\\Graph\\grpData\\f14.grp"
    };
    const char* labels[] = {
        "第一组（udg8.grp）",
        "第二组（udg115.grp）",
        "第三组（dg6.grp）",
        "第四组（f14.grp）"
    };

    for (int i = 0; i < 4; ++i) {
        Graph G;
        cout << labels[i] << "：";
        if (CreateGraphFromFile((char*)files[i], G)) {
            int edgeCount = countEdges(G);
            cout << "边（或弧）数量为：" << edgeCount << endl;
        } else {
            cout << "读取失败。\n";
        }
        DestroyGraph(G);
    }

    return 0;
}
