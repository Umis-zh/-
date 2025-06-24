#include <iostream>
#include <cstring>
using namespace std;

int readData(const char *filename,int *data,int maxlen){
    FILE *fp=fopen(filename,"r");
    if (!fp) {
        cout<<"打开文件失败";
        return -1;
    }
    char line[1000];
    int count = 0;
    while (fgets(line,1000, fp)&& count < maxlen) {
        char *token = strtok(line, ",");
        while (token != NULL) {
            data[count++] = atoi(token); 
            token = strtok(NULL, ",");
        }
    }
    fclose(fp);
    return count;
}