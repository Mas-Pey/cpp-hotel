#include <iostream>
#include <fstream>
#include <cstring>
#include <windows.h>
#include <time.h>	
using namespace std;
struct data_pemesanan{
	string nama,nohp,email;
	int tipe,hari,kamar,in,out,bill;
	};
void pemesanan(int *harga);
void riwayat();
int robot(int n, int m);
string type[4][2]={{"SUPERIOR TWIN ROOM","Rp. 550.000/kamar/malam"},{"SUPERIOR KING ROOM","Rp 600.000/kamar/malam"},
				   {"DELUXE TWIN ROOM","Rp 650.000/kamar/malam"},{"DELUXE KING ROOM","Rp 700.000/kamar/malam"}};
int list[4][2]={{1,550000},{2,600000},{3,650000},{4,700000}};
int list1,jenis,i,j,x,sort,search,jumlah;
char menu,urut,cari,lagi;
string tp,hrg;
main(){
	int harga,n,m;
	srand(time(0));
	do{
	n=(rand()%3)+2;m=(rand()%3)+1;
	awal:system("cls");
	cout<<"PASTIKAN ANDA BUKAN ROBOT!\n";
	cout<<"Hitung jumlah dari : "<<m;
	for(j=2;j<=n;j++)cout<<" + "<<m*j;
	cout<<" = ";
	cout<<"\nJumlah = ";cin>>jumlah;
	if(jumlah==robot(n, m)){cout<<"BENAR!";Sleep(1000);}
	else {cout<<"SALAH!";Sleep(1000);goto awal;}
	
	system("cls");
	cout<<"\t\tSelamat datang di HOTEL LETOH\n\n";
	cout<<"Pilih jenis kamar untuk dipesan :\n\n";
	cout<<"1. SUPERIOR TWIN ROOM\n2. SUPERIOR KING ROOM\n3. DELUXE TWIN ROOM\n4. DELUXE KING ROOM\n0. Lainnya (Input Angka 0 Untuk Cetak Semua Riwayat Transaksi)\n";
	cout<<"Pilih : ";cin>>jenis;system("cls");
	if(jenis==1){
		cout<<"\tSUPERIOR TWIN ROOM (non-smoking)\n\n";
		cout<<"Facility :\nLuas 18.0 m2\n2 Single Bed\n2 Tamu\nSarapan Gratis\nFree Wi-fi\nBebas Rokok\n\n";
		harga=list[0][1];list1=list[0][0];
		cout<<"PRICE : "<<harga<<endl;
		pemesanan(&harga);
	}else if(jenis==2){
		cout<<"\tSUPERIOR KING ROOM (non-smoking)\n\n";
		cout<<"Facility :\nLuas 18.0 m2\n1 King Bed\n2 Tamu\nSarapan Gratis\nFree Wi-fi\nBebas Rokok\nAir Panas\n\n";
		harga=list[1][1];list1=list[1][0];
		cout<<"PRICE : "<<harga<<endl;
		pemesanan(&harga);
	}else if(jenis==3){
		cout<<"\tDELUXE TWIN ROOM (non-smoking)\n\n";
		cout<<"Facility :\nLuas 30.0 m2\n2 Single Bed\n2 Tamu\nSarapan Gratis\nFree Wi-fi\nBebas Rokok\nAir Panas\n\n";
		harga=list[2][1];list1=list[2][0];
		cout<<"PRICE : "<<harga<<endl;
		pemesanan(&harga);
	}else if(jenis==4){
		cout<<"\tDELUXE KING ROOM (non-smoking)\n\n";
		cout<<"Facility :\nLuas 30.0 m2\n1 King Bed+1 Single Bed\n2 Tamu\nSarapan Gratis\nFree Wi-fi\nBebas Rokok\nAir Panas\n\n";
		harga=list[3][1];list1=list[3][0];
		cout<<"PRICE : "<<harga<<endl;
		pemesanan(&harga);
	}else if(jenis==0){
		riwayat();
	}else{
		cout<<"Jenis Kamar/Input Tidak Sesuai!\n";
	}
	cout<<"\nKembali pilih jenis kamar(y/n)? ";cin>>menu;
	}while(menu=='y'||menu=='Y');
}

void pemesanan(int *harga){
	data_pemesanan data;
	char pesan;
	cout<<"Pesan kamar(y/n)? ";cin>>pesan;cin.ignore();
	cout<<endl;
	if(pesan=='y'||pesan=='Y'){
		ofstream ofs("invoice.txt",ios::app);
		if(ofs.is_open()){
			cout<<"Nama Kontak\t: ";getline(cin,data.nama);
			for(j=0;data.nama[j];j++){
				if(data.nama[j]==' '){
					data.nama.replace(j,1,1,'_');
				}//MENGUBAH ' ' MENJADI '_' AGAR BISA DIBACA IFS
			}
			cout<<"No HP\t\t: ";cin>>data.nohp;
			cout<<"Email Kontak\t: ";cin>>data.email;
			data.tipe=list1;
			cout<<"Jenis Kamar\t: "<<data.tipe<<endl;
			cout<<"Jumlah Kamar\t: ";cin>>data.kamar;
			cout<<"Lama Hari\t: ";cin>>data.hari;
			cout<<"Waktu Check In (01-23)\t: ";cin>>data.in;
			cout<<"Waktu Check Out (01-13)\t: ";cin>>data.out;
			if(data.in>23)data.in=01;
			if(data.out>13)data.out=13;
			data.bill=*harga*data.kamar*data.hari;
			ofs<<data.nama<<endl<<data.nohp<<endl<<data.email<<endl<<data.tipe<<endl<<data.kamar<<endl<<data.hari<<endl<<data.in<<endl<<data.out<<endl<<data.bill<<endl;
			ofs.close();
		}
		cout<<"\n\n\t... Please wait a second ...\t";Sleep(2000);system("CLS");
		cout<<"\t\t----- INVOICE TRANSACTION -----\n\n";
		for(j=0;data.nama[j];j++){
				if(data.nama[j]=='_'){
					data.nama.replace(j,1,1,' ');
				}//MENGEMBALIKAN '_' MENJADI ' '
			}
		cout<<"NAMA\t: "<<data.nama;
		cout<<"\nNo. Hp\t: "<<data.nohp;
		cout<<"\nEmail\t: "<<data.email;
		cout<<"\n\tDetail Order : ";
		cout<<"\n\tJenis Kamar\t: "<<data.tipe;
		cout<<"\n\tJumlah Kamar\t: "<<data.kamar;
		cout<<"\n\tLama Menginap\t: "<<data.hari<<" hari";
		cout<<"\n\tCheck In : "<<data.in<<".00 WIB\tCheck Out : "<<data.out<<".00 WIB";
		cout<<"\nTOTAL TAGIHAN\t: Rp "<<data.bill<<endl;
	}
}

void riwayat(){system("CLS");
	i=0;
	cout<<"\t\t----- INVOICE TRANSACTION -----\n\n";
	data_pemesanan data[100],temp[100];
	ifstream ifs("invoice.txt",ios::app);
	if(ifs.is_open()){
		while(ifs>>data[i].nama>>data[i].nohp>>data[i].email>>data[i].tipe>>data[i].kamar>>data[i].hari>>data[i].in>>data[i].out>>data[i].bill){
			for(j=0;data[i].nama[j];j++){
				if(data[i].nama[j]=='_'){
					data[i].nama.replace(j,1,1,' ');
				}//MENGEMBALIKAN '_' MENJADI ' '
			}
			cout<<"NAMA\t: "<<data[i].nama;
			cout<<"\nNo. Hp\t: "<<data[i].nohp;
			cout<<"\nEmail\t: "<<data[i].email;
			cout<<"\n\tDetail Order : ";
			if(data[i].tipe==1){tp=type[0][0];hrg=type[0][1];}
			if(data[i].tipe==2){tp=type[1][0];hrg=type[1][1];}
			if(data[i].tipe==3){tp=type[2][0];hrg=type[2][1];}
			if(data[i].tipe==4){tp=type[3][0];hrg=type[3][1];}
			cout<<"\n\tJenis Kamar\t: "<<tp;
			cout<<"\n\tHarga Kamar\t: "<<hrg;
			cout<<"\n\tJumlah Kamar\t: "<<data[i].kamar;
			cout<<"\n\tLama Menginap\t: "<<data[i].hari<<" hari";
			cout<<"\n\tCheck In : "<<data[i].in<<".00 WIB\tCheck Out : "<<data[i].out<<".00 WIB";
			cout<<"\nTOTAL TAGIHAN\t: Rp "<<data[i].bill<<endl<<endl;
			i++;
		}
		ifs.close();
	}
	cout<<"Urutkan Data(y/n)? ";cin>>urut;
	if(urut=='y'||urut=='Y'){
		back:system("cls");
		cout<<"Urutkan berdasarkan : \n1. Total Tagihan Terkecil\n2. Total Tagihan Terbesar\nPilih : ";cin>>sort;
		switch(sort){
			case 1:
			cout<<"Urutan Tagihan Terkecil\n\n";
			for(x=0;x<i-1;x++){//SORTING METODE BUBBLESORT
				for(j=0;j<i-1-x;j++){
					if(data[j].bill>data[j+1].bill){
						temp[j]=data[j];
						data[j]=data[j+1];
						data[j+1]=temp[j];
					}
				}
			}
			for(x=0;x<i;x++){
				cout<<"TOTAL TAGIHAN\t: Rp "<<data[x].bill;
				cout<<"\nNAMA\t: "<<data[x].nama;
				cout<<"\nEmail\t: "<<data[x].email;
				cout<<"\n\tDetail Order : ";
				if(data[x].tipe==1){tp=type[0][0];hrg=type[0][1];}
				if(data[x].tipe==2){tp=type[1][0];hrg=type[1][1];}
				if(data[x].tipe==3){tp=type[2][0];hrg=type[2][1];}
				if(data[x].tipe==4){tp=type[3][0];hrg=type[3][1];}
				cout<<"\n\tJenis Kamar\t: "<<tp;
				cout<<"\n\tHarga Kamar\t: "<<hrg;
				cout<<"\n\tJumlah Kamar\t: "<<data[x].kamar;
				cout<<"\n\tLama Menginap\t: "<<data[x].hari<<" hari"<<endl<<endl;
			}
			break;
			case 2:
			cout<<"Urutan Tagihan Terbesar\n\n";
			for(x=0;x<i;x++){//SORTING METODE SELECTION
				for(j=x+1;j<i;j++){
					if(data[x].bill<data[j].bill){
						temp[j]=data[x];
						data[x]=data[j];
						data[j]=temp[j];
					}
				}
			}
			for(x=0;x<i;x++){
				cout<<"TOTAL TAGIHAN\t: Rp "<<data[x].bill;
				cout<<"\nNAMA\t: "<<data[x].nama;
				cout<<"\nEmail\t: "<<data[x].email;
				cout<<"\n\tDetail Order : ";
				if(data[x].tipe==1){tp=type[0][0];hrg=type[0][1];}
				if(data[x].tipe==2){tp=type[1][0];hrg=type[1][1];}
				if(data[x].tipe==3){tp=type[2][0];hrg=type[2][1];}
				if(data[x].tipe==4){tp=type[3][0];hrg=type[3][1];}
				cout<<"\n\tJenis Kamar\t: "<<tp;
				cout<<"\n\tHarga Kamar\t: "<<hrg;
				cout<<"\n\tJumlah Kamar\t: "<<data[x].kamar;
				cout<<"\n\tLama Menginap\t: "<<data[x].hari<<" hari"<<endl<<endl;
			}
			break;
			default:cout<<"Pilihan Tidak Tersedia!\n";Sleep(1000);goto back;
			break;
		}
	}
	cout<<"\nCari Data(y/n)? ";cin>>cari;
	if(cari=='y'||cari=='Y'){
		back2:
		do{system("cls");
			cout<<"Cari berdasarkan : \n1. Nama\n2. No. HP\nPilih : ";cin>>search;cin.ignore();
			bool found=0;x=0;
			string nama,no;
			switch(search){
				case 1:
				cout<<"Cari data berdasarkan nama kontak\n";
				cout<<"Masukkan nama yang ingin dicari : ";getline(cin,nama);
				cout<<endl;
				while(x<i){
					if(nama==data[x].nama){//SEARCHING BERDASARKAN NAMA
						found=1;
						cout<<"NAMA\t: "<<data[x].nama;
						cout<<"\nEmail\t: "<<data[x].email;
						cout<<"\n\tDetail Order : ";
						if(data[x].tipe==1){tp=type[0][0];hrg=type[0][1];}
						if(data[x].tipe==2){tp=type[1][0];hrg=type[1][1];}
						if(data[x].tipe==3){tp=type[2][0];hrg=type[2][1];}
						if(data[x].tipe==4){tp=type[3][0];hrg=type[3][1];}
						cout<<"\n\tJenis Kamar\t: "<<tp;
						cout<<"\n\tHarga Kamar\t: "<<hrg;
						cout<<"\n\tJumlah Kamar\t: "<<data[x].kamar;
						cout<<"\n\tLama Menginap\t: "<<data[x].hari<<" hari";
						cout<<"\nTOTAL TAGIHAN\t: Rp "<<data[x].bill<<endl<<endl;
					}
					x+=1;
				}
				if(!found) cout<<"Data yang anda cari tidak ditemukan\n\n";
				break;
				case 2:
				cout<<"Cari data berdasarkan no hp kontak\n";
				cout<<"Masukkan no hp kontak : ";cin>>no;
				cout<<endl;
				while(x<i){
					if(no==data[x].nohp){//SEARCHING BERDASARKAN NO HP
						found=1;
						cout<<"NAMA\t: "<<data[x].nama;
						cout<<"\nEmail\t: "<<data[x].email;
						cout<<"\n\tDetail Order : ";
						if(data[x].tipe==1){tp=type[0][0];hrg=type[0][1];}
						if(data[x].tipe==2){tp=type[1][0];hrg=type[1][1];}
						if(data[x].tipe==3){tp=type[2][0];hrg=type[2][1];}
						if(data[x].tipe==4){tp=type[3][0];hrg=type[3][1];}
						cout<<"\n\tJenis Kamar\t: "<<tp;
						cout<<"\n\tHarga Kamar\t: "<<hrg;
						cout<<"\n\tJumlah Kamar\t: "<<data[x].kamar;
						cout<<"\n\tLama Menginap\t: "<<data[x].hari<<" hari";
						cout<<"\nTOTAL TAGIHAN\t: Rp "<<data[x].bill<<endl<<endl;
					}
					x+=1;
				}
				if(!found) cout<<"Data yang anda cari tidak ditemukan\n\n";
				break;
				default:cout<<"Pilihan Tidak Tersedia!\n";Sleep(1000);goto back2;
				break;
			}
			cout<<"Cari data lagi(y/n)? ";cin>>lagi;
		}while(lagi=='y'||lagi=='Y');
	}
}

int robot(int n, int m){//REKURSIF UNTUK MEMASTIKAN BUKAN ROBOT
	if(n==1){
		return m;
	}else{
		return m*n+robot(n-1,m);	
	}
}
