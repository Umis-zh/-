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

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) cout << arr[i] << " ";
    cout << endl;
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}


void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            int temp = arr[i], j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - i - 1; ++j)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

void partition(int arr[], int low, int high, int &mid) {
    int pivot = arr[low];  // 用第一个元素作为基准值
    while (low < high) {
        // 从右往左找第一个小于 pivot 的数
        while (low < high && arr[high] >= pivot)
            --high;
        arr[low] = arr[high]; 

        // 从左往右找第一个大于 pivot 的数
        while (low < high && arr[low] <= pivot)
            ++low;
        arr[high] = arr[low]; 
    }
    arr[low] = pivot; // 把 pivot 填到最终位置
    mid = low;        // 返回中间位置
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int mid;
        partition(arr, low, high, mid);
        quickSort(arr, low, mid - 1);
        quickSort(arr, mid + 1, high);
    }
}


void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j)
            if (arr[j] < arr[minIdx])
                minIdx = j;
        swap(arr[i], arr[minIdx]);
    }
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    while (true) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        largest = i;

        if (l < n && arr[l] > arr[largest]) largest = l;
        if (r < n && arr[r] > arr[largest]) largest = r;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            i = largest; // 继续向下调整
        } else {
            break; // 已满足堆性质，终止
        }
    }
}


void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; --i)
        heapify(arr, n, i);
    for (int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int *L = new int[n1];
    int *R = new int[n2];
    for (int i = 0; i < n1; ++i) L[i] = arr[l + i];
    for (int i = 0; i < n2; ++i) R[i] = arr[m + 1 + i];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
    delete[] L;
    delete[] R;
}


void mergeSortUp(int arr[], int n) {
    for (int len = 1; len < n; len *= 2) {
        int i = 0;
        for (; i <= n - 2 * len; i += 2 * len) {
            merge(arr, i, i + len - 1, i + 2 * len - 1);
        }
        if (i + len < n) {
            merge(arr, i, i + len - 1, n - 1);
        }
    }
}

void topKMin(int data[], int n, int k, int result[]) {
    for (int i = 0; i < k; ++i) result[i] = data[i];
    for (int i = k / 2 - 1; i >= 0; --i)
        heapify(result, k, i);
    for (int i = k; i < n; ++i) {
        if (data[i] < result[0]) {
            result[0] = data[i];
            heapify(result, k, 0);
        }
    }
}