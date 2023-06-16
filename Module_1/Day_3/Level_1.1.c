#include<stdio.h>

int increase(int n);
int space(int n);
int decrease(int n);

int main(){
	int n;
	scanf("%d",&n);
	for(int i=n;i>=1;i--){
		increase(i);
		space(2*(n-i));
		decrease(i);
		printf("\n");
	}
	return 0;
}

int increase(int n){
	for(int i=1;i<=n;i++){
		printf("%d",i);
	}
}

int space(int n){
	for(int i=1;i<=n;i++){
		printf(" ");
	}
}

int decrease(int n){
	for(int i =n;i>=1;i--){
		printf("%d",i);
	}
}
