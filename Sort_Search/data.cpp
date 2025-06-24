#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    const int total = 1000;
    const int perLine = 10;  // 每行 10 个数
    const char *filename = "sort1000.dat";

    ofstream fout(filename);
    if (!fout) {
        cout << "无法创建文件" << endl;
        return 1;
    }

    srand(time(0));
    for (int i = 0; i < total; ++i) {
        fout << rand() % 10000;  // 0~99999 的随机整数
        if ((i + 1) % perLine == 0)
            fout << "\n";
        else
            fout << ",";
    }

    fout.close();
    cout << "已生成文件 " << filename << "，共 " << total << " 个随机整数。" << endl;
    return 0;
}
