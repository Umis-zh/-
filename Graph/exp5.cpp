#include <iostream>
#include <cstring>
#include "GrpAdjLinkedList.h"
using namespace std;

void printDFSTreeMatrix(int B[MaxLen][MaxLen], int n, Graph &G) {
    cout << "\nDFS 生成树邻接矩阵：" << endl;

    // 打印顶点行标题
    cout << "   ";
    for (int i = 1; i <= n; ++i)
        cout << G.VerList[i].data << " ";
    cout << endl;

    for (int i = 1; i <= n; ++i) {
        cout << G.VerList[i].data << ": ";
        for (int j = 1; j <= n; ++j) {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    const char* files[] = {
        "D:\\Code\\C_CODE\\Graph\\grpData\\udg10.grp",
        "D:\\Code\\C_CODE\\Graph\\grpData\\udTree11.grp",
        "D:\\Code\\C_CODE\\Graph\\grpData\\udn6.grp",
        "D:\\Code\\C_CODE\\Graph\\grpData\\udg8.grp"
    };

    for (int i = 0; i < 4; ++i) {
        Graph G;
        int B[MaxLen][MaxLen] = {0};

        cout << "===== 正在处理文件：" << files[i] << " =====" << endl;

        if (!CreateGraphFromFile((char*)files[i], G)) {
            cout << "❌ 创建图失败。" << endl;
            continue;
        }

        GenerateDFSTree(&G, B);
        printDFSTreeMatrix(B, G.VerNum, G);

        DestroyGraph(G);
    }

    return 0;
}
