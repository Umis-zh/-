#include <iostream>
#include "GrpAdjMatrix.h"  
using namespace std;

int main() {
    const char* filenames[] = {
        "D:\\Code\\C_CODE\\Graph\\grpData\\udg8.grp",
        "D:\\Code\\C_CODE\\Graph\\grpData\\udg115.grp",
        "D:\\Code\\C_CODE\\Graph\\grpData\\dg6.grp",
        "D:\\Code\\C_CODE\\Graph\\grpData\\f14.grp"
    };

    Graph G;
    for (int i = 0; i < 4; ++i) {
        cout << "\n=== 正在处理文件：" << filenames[i] << " ===\n";
        if (CreateGrpFromFile((char*)filenames[i], G)) {
            for (int v = 1; v <= G.VerNum; ++v) {
                for (int w = 1; w <= G.VerNum; ++w) {
                    if (v == w) continue;
                    bool res = HasPath(G, v, w);
                    cout << G.Data[v] << " → " << G.Data[w] << " : "
                         << (res ? "存在路径 ✅" : "不存在路径 ❌") << endl;
                }
            }
        } else {
            cout << "图读取失败！\n";
        }
    }
    return 0;
}
