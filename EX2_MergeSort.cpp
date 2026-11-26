#include<stdio.h>
#include<stdlib.h>
void merge(int a[],int left,int mid,int right);
void mergeSort(int a[],int left,int right){
    if(left>=right) return;
    int mid=left+(right-left)/2;
    mergeSort(a,left,mid);
    mergeSort(a,mid+1,right);
    merge(a,left,mid,right);

}
void merge(int a[],int left,int mid,int right){
    int n1=mid-left+1;
    int n2=right-mid;
    int *L=(int*)malloc(n1*sizeof(int));
    int *R=(int*)malloc(n2*sizeof(int));
    for(int i=0;i<n1;i++) L[i]=a[left+i];
    for(int j=0;j<n2;j++) R[j]=a[mid+j+1];
    int i=0;int j=0;int k=left;
    while(i<n1&&j<n2){
        if(L[i]<=R[j]) {
            a[k]=L[i];
            i++;
        }
        else{
            a[k]=R[j];
            j++;
        }
        k++;
    }
    while (i<n1) a[k++]=L[i++];
    while (j<n2) a[k++]=R[j++];
    
    free(L);free(R);
    
    

}
int main() {
    int a[] = {38, 27, 43, 3, 9, 82, 10, 15, 2, 19};
    int n = sizeof(a) / sizeof(a[0]);

    mergeSort(a, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
