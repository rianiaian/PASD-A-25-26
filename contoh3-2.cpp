#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

void BUAT_SIMPUL(int X);
void AWAL();
void CETAK();
void INSERTKANAN();
struct Node{
	int INFO;
	struct Node *LINK;
};
typedef struct Node Simpul;
Simpul *P, *FIRST, *LAST, *Q;
int X;

int main(){
	int A[7] = {22,28,7,11,66,63,10};
	int I;
	FIRST = NULL;
	I = 0;
	X = A[I];
	BUAT_SIMPUL(X);
	AWAL();
	for(I=1; I<=6; I++){
		X = A[I];
		BUAT_SIMPUL(X);
		INSERTKANAN();
	}
	cout<<"Nilai Sebelum Dilakukan Insert Kanan  : ";
	CETAK();
	X = 100;
	BUAT_SIMPUL(X);
	INSERTKANAN();
	cout<<endl;
	cout<<"Nilai Seteelah Dilakukan Insert Kanan : ";
	CETAK();
	cout<<endl;
	cin.get();
}

void BUAT_SIMPUL(int X){
	P = (Simpul*) malloc(sizeof(Simpul));
	if(P != NULL){
		P -> INFO = X;
	}else {
		cout<<"Pembuatan Simpul Tidak Berhasil"<<endl;
		cin.get();
		exit(1);
	}
}

void AWAL(){
	FIRST = P;
	LAST = P;
	P -> LINK = NULL;
}

void INSERTKANAN(){
	LAST -> LINK = P;
	LAST = P;
	P -> LINK = NULL;
}

void CETAK(){
	int X;
	Q = FIRST;
	while(Q != NULL){
		X = Q -> INFO;
		cout<<"  "<<X;
		Q = Q -> LINK;
	}
}