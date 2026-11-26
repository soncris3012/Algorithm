#include<stdio.h>
#include<limits.h>
int max2(int a,int b){
    return (a>b)?a:b;
}
int max3(int a,int b,int c){
    return (max2(a,b)>c)?max2(a,b):c;
}
int maxcrossingSum(int a[],int left,int mid,int right){
    int sum=0;
    //mid=left+(right-left)/2;
    int leftmax=INT_MIN;
    for(int i=mid;i>=left;i--){
        sum+=a[i];
        if(sum>leftmax) leftmax=sum;
    }
    sum=0;
    int rightmax=INT_MIN;
    for(int j=mid+1;j<=right;j++){
         sum+=a[j];
        if(sum>rightmax) rightmax=sum;

    }
    return leftmax+rightmax;
}
int maxsubarray(int a[],int left,int right){
    int mid=left+(right-left)/2;
    if(left==right) return a[left];
    int maxleft=maxsubarray(a,left,mid);
    int maxright=maxsubarray(a,mid+1,right);
    int maxcross=maxcrossingSum(a,left,mid,right);
    return max3(maxleft,maxright,maxcross);
}
int main(){
    int a[10]={1,4,-6,1,4,7,3,6,-2,5};
    int left=0;
    int right=9;
    int sum=maxsubarray(a,left,right);
    
    printf("Tổng dãy con lớn nhất là:%d",sum);

    return 0;

}