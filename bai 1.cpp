#include<iostream>
using namespace std;
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}
int partition (int *arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(int *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void merge(int *arr1, int n1, int *arr2, int n2, int *arr3) {
  int i = 0, j = 0, k = 0;
  while (i < n1 && j < n2) {
    if (arr1[i] <= arr2[j]) {
      arr3[k++] = arr1[i++];
    } else {
      arr3[k++] = arr2[j++];
    }
  }
  while (i < n1) {
    arr3[k++] = arr1[i++];
  }
  while (j < n2) {
    arr3[k++] = arr2[j++];
  }
}
void output(int* p, int n) {
    cout<<n<<" cac phan tu da sap xep: ";
    for(int i = 0; i < n; i++){
        cout<<p[i]<<" ";
    }
    cout<<endl;
}
int main() {
    int n,m,k;
    int i =0, j = 0;
    cout<<"nhap so phan tu mang 1: ";
    cin>>n;
    cout<<"nhap so phan tu mang 2: ";
    cin>>m;
    k = m + n;
    int *p = new int[n];
    int *q = new int[m];
    int *a = new int[k];
    cout<<"nhap cac phan tu mang 1: ";
    for(int t = 0; t < n; t++) {
        cin>>p[t];
    }
    cout<<"nhap cac phan tu mang 2: ";
    for(int t = 0; t < m; t++) {
        cin>>q[t];
    }
    quickSort(p, 0, n-1);
    output(p,n);
    quickSort(q, 0, m-1);
    output(q,m);
    merge(p,n,q,m,a);
    output(a,k);
    delete[] p;
    delete[] q;
    return 0;
}