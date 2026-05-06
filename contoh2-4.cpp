#include <iostream>
#include <string.h>
using namespace std;

typedef struct{
	string npm;
	string nama_mhs;
	double nilai;
} NilaiMK;

typedef struct{
	int top;
	NilaiMK Dat[10];
} stack;

void buatSTkosong (stack *s){
	(*s).top = -1;
}

bool isKosong(stack s){
	bool hasil = false;
	
	if(s.top == -1){
		hasil = true;
	}
	return hasil;
}

bool isPenuh(stack s){
	bool hasil = false;
	
	if(s.top == 9){
		hasil = true;
	}
	return hasil;
}

void push(string npm, string nama_mhs, double nilai, stack *s){
	if(isPenuh(*s) == 1){
		cout <<"stack penuh"<<endl;
	}
	else{
	if(isKosong(*s) == 1){
		(*s).top = 0;
		(*s).Dat[0].npm = npm;
		(*s).Dat[0].nama_mhs = nama_mhs;
		(*s).Dat[0].nilai = nilai;
	}
	else{
		(*s).top = (*s).top + 1;
		(*s).Dat[(*s).top].npm = npm;
		(*s).Dat[(*s).top].nama_mhs = nama_mhs;
		(*s).Dat[(*s).top].nilai = nilai;
		}
	}
}

void Pop(stack *s){
	if((*s).top == 0){
		(*s).top = -1;
	}
	else {
		if((*s).top != -1){
			(*s).top = (*s).top - 1;
		}
	}
}

void CetakStack(stack s){
	if (s.top != -1){
		cout<<"MENAMPILKAN STACK"<<endl;
		int i;
		for(i=s.top; i>=0; i--){
			cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
			cout<<"Elemen ke				: "<< i << endl;
			cout<<"Nomor Pokok Mahasigma	: "<<s.Dat[i].npm<<endl;
			cout<<"Nama Mahasigma			: "<<s.Dat[i].nama_mhs<<endl;
			cout<<"Nilai Mahasigma			: "<<s.Dat[i].nilai<<endl;
			cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
		}
	}
	else{
		cout<<"stack kosong"<<endl;
	}
}
int main(){
	stack s;
	buatSTkosong(&s);
	CetakStack(s);
	cout<<endl;
	cout<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	push("4525210033", "Kevin", 88.75, &s);
	push("4525210035", "Adam", 78.85, &s);
	push("4525210031", "Karel", 58.65, &s);
	push("4525210019", "Daffa", 68.55, &s);
	CetakStack(s);
	cout<<"=================================="<<endl;
	cout<<endl;
	cout<<endl;
	Pop(&s);
	CetakStack(s);
	cout<<endl;
	cout<<endl;
	Pop(&s);
	CetakStack(s);
	cout<<endl;
	cout<<endl;
	Pop(&s);
	CetakStack(s);
	cout<<"=================================="<<endl;
	cin.get();
}
