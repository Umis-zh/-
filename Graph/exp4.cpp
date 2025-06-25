#include <iostream>
#include "GrpAdjLinkedList.h"

int main() {
    Graph G;
    char filename[100];

    const char* files[] = {
        "D:\\Code\\C_CODE\\Graph\\grpData\\dg6.grp",
        "D:\\Code\\C_CODE\\Graph\\grpData\\udTree11.grp"
    };
    const elementType roots[] = {'a', 'a'};  // 假设根节点为 'a'，根据文件内容调整

    for (int i = 0; i < 2; ++i) {
        strcpy(filename, files[i]);

        std::cout << "读取图文件：" << filename << std::endl;

        if (!CreateGraphFromFile(filename, G)) {
            std::cout << "读取图失败。\n";
            continue;
        }

        if (isDirectedTree(&G, roots[i])) {
            std::cout << "✅ 是以 " << roots[i] << " 为根的有向树。\n";
        } else {
            std::cout << "❌ 不是以 " << roots[i] << " 为根的有向树。\n";
        }

        DestroyGraph(G);
        std::cout << "-----------------------------\n";
    }

    return 0;
}
