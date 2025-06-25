#include <iostream>
using namespace std;
#include "GrpAdjLinkedList.h"
int main() {
    Graph G;
    const char* files[] = {
        "D:\\Code\\C_CODE\\Graph\\grpData\\udg8.grp",
        "D:\\Code\\C_CODE\\Graph\\grpData\\udg115.grp",
        "D:\\Code\\C_CODE\\Graph\\grpData\\dg6.grp",
        "D:\\Code\\C_CODE\\Graph\\grpData\\f14.grp"
    };

    for (int f = 0; f < 4; ++f) {
        cout << "========= 文件：" << files[f] << " =========" << endl;
        if (!CreateGraphFromFile((char*)files[f], G)) {
            cout << "图读取失败" << endl;
            continue;
        }

        for (int i = 1; i <= G.VerNum; ++i) {
            elementType v = G.VerList[i].data;
            cout << "顶点 " << v << " 的邻接点：";

            int wIndex = firstAdj(&G, v);
            while (wIndex != -1) {
                elementType w = G.VerList[wIndex].data;
                cout << w << " ";
                wIndex = nextAdj(&G, v, w);
            }
            cout << endl;
        }

        cout << endl;
        DestroyGraph(G);
    }

    return 0;
}
