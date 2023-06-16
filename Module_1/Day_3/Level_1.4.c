#include<stdio.h>

int largestandsmallest(int n);
int lenofnum(int n);

int main(){
    int a;
    scanf("%d",&a);
    largestandsmallest(a);
    return 0;
}

int largestandsmallest(int n){
    int len = lenofnum(n);
    int a[len];
    for(int i=len-1;i>=0;--i){
        a[i] = n%10;
        n = n/10;
    }
    int lar = a[0], small = a[0];
    for(int i=0;i<len;i++){
        if(lar<a[i]){
            lar = a[i];
        }
        if(small>a[i]){
            small = a[i];
        }
    }
    if(len==1){
        printf("Not Valid");
    }
    else{
        printf("%d and %d", small, lar);
    }

}

int lenofnum(int n){
    int len = 0;
    if(n<10){
        return 1;
    }
    if(n<0){
        n = -n;
    }
    while (n>0){
        len+=1;
        n = n/10;
    }
    return len;

}

