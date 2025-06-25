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

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) cout << arr[i] << " ";
    cout << endl;
}

int binarySearchTrace(int arr[], int low, int high, int key) {
    cout << "查找 " << key << "：比较值序列 ";

    while (low <= high) {
        int mid = (low + high) / 2;
        cout << arr[mid] << " ";

        if (arr[mid] == key) {
            cout << "✅ 找到\n";
            return mid;
        } else if (arr[mid] > key) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << "❌ 未找到\n";
    return -1;
}




typedef struct biNode{
    int data;
    biNode *lchild,*rchild;
} btNode,*btTree;

btTree insert(btTree root, int val) {
    if (!root) {
        root = new btNode;
        root->data = val;
        root->lchild = root->rchild = NULL;
        return root;
    }
    if (val < root->data) root->lchild = insert(root->lchild, val);
    else if (val > root->data) root->rchild = insert(root->rchild, val);
    return root;
}

btTree buildBST(int data[], int size) {
    btTree root = NULL;
    for (int i = 0; i < size; ++i) root = insert(root, data[i]);
    return root;
}

void computeASL(btTree root, int depth, int &totalDepth, int &count) {
    if (!root) return;
    totalDepth += depth;
    ++count;
    computeASL(root->lchild, depth + 1, totalDepth, count);
    computeASL(root->rchild, depth + 1, totalDepth, count);
}

bool searchWithTrace(btTree root, int key) {
    cout << " 查找 " << key << " 比较序列：";
    while (root) {
        cout << root->data << " ";
        if (key == root->data) {
            cout << "找到\n";
            return true;
        }
        root = (key < root->data) ? root->lchild : root->rchild;
    }
    cout << "未找到\n";
    return false;
}


btTree findMin(btTree node) {
    while (node && node->lchild) node = node->lchild;
    return node;
}

btTree deleteNode(btTree root, int key) {
    if (!root) return NULL;
    if (key < root->data) root->lchild = deleteNode(root->lchild, key);
    else if (key > root->data) root->rchild = deleteNode(root->rchild, key);
    else {
        if (!root->lchild) {
            btTree right = root->rchild;
            delete root;
            return right;
        } else if (!root->rchild) {
            btTree left = root->lchild;
            delete root;
            return left;
        }
        btTree successor = findMin(root->rchild);
        root->data = successor->data;
        root->rchild = deleteNode(root->rchild, successor->data);
    }
    return root;
}