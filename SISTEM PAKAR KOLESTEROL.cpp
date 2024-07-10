#include<iostream>
#include<windows.h>
#include<iomanip>
#include<sstream>
#include<string.h>
#include<conio.h>
using namespace std;
void textcolor(int ForgC)
{
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
    	wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}
string tengah1(int width, char* s)
{
	stringstream ss;
	int pos = width / 2 + int(strlen(s) / 2);
	ss << setw(pos) << s;
	return ss.str();
}
void header()
{
		textcolor(6);
	cout<<""<<endl;
	cout<<":=================================================================================================:"<<endl;
	cout<<"|>>>>>>> SISTEM PAKAR DIAGNOSA PENYAKIT KOLESTEROL MENGGUNAKAN METODE CERTAINLY FACTOR <<<<<<<<<<<|"<<endl;
	cout<<"|                                                                                                 |"<<endl;
	cout<<"|                                       FAISHAL FITRA RAMADHAN                                    |"<<endl;
	cout<<"|                            KECERDASAN BUATAN (ARTIFICIAL INTELLIGENCE)                          |"<<endl;
	cout<<"|                                                                                                 |"<<endl;
	cout<<":=================================================================================================:"<<endl;
	cout<<"|                 - SELAMAT DATANG DI SISTEM PAKAR DIAGNOSA PENYAKIT KOLESTEROL -                 |"<<endl;
	cout<<"|_________________________________________________________________________________________________|"<<endl;
	cout<<"|                                     - METODE CERTAINLY FACTOR -                                 |"<<endl;
	cout<<":=================================================================================================:"<<endl;
	cout<<endl;
}
void awal()
{
	system("cls");
	header();
	textcolor(0);
}

void salah()
{
	system("cls");
	textcolor(4);
	cout<<"ANDA MEMASUKKAN ANGKA YANG SALAH, SILAHKAN DIULANG !!"<<endl;
}
int main()
{
	string nama, julukan,
	g01="Nyeri pada kaki dan kram di malam hari",
	g02="Kesemutan",
	g03="Sakit kepala",
	g04="Gampang mengantuk",
	g05="Pegal-pegal sampai ke pundak",
	g06="Mudah kelelahan",
	g07="Daerah tengkuk belakang sakit sampai kepala",
	g08="Kelebihan berat badan",
	p01="Kolesterol Baik",
	p02="Kolesterol Jahat",
	opt1="Tidak Benar",
	opt2="Kurang Yakin",
	opt3="Kemungkinan Kecil",
	opt4="Kemungkinan Besar",
	opt5="Sangat Yakin";
	int pilihan1,pilihan2,pilihan3,pilihan4,pilihan5,pilihan6,pilihan7,pilihan8,pilihan9,pilihan10,pilihan11;
	char gender, ulang;
	float a=0, b=0.2, c=0.5, d=0.8, e=1;
	float pil1, pil2, pil3, pil4, pil5, pil6, pil7, pil8, pil9, pil10, pil11;
	float ada1,ada2,ada3,ada4,ada5,adi1,adi2,adi3,adi4,adi5,adi6,adi7,adi8,adi9,adu1,adu2,adu3,adu4;
	mulai:
	system("cls");
	header();
	textcolor(7);
	cout<<" Masukkan Nama Lengkap Anda  = ";
	getline(cin>>ws,nama);
	cout<<endl;
	cout<<" Masukkan Gender Anda [L/P]  = ";
	cin>>gender;
	if(gender=='l' || gender=='L')
	{
		julukan = "Saudara";
	}
	else if (gender=='p' || gender=='P')
	{
		julukan = "Saudari";
	}
	else
	{
		cout<<" ANDA MEMASUKKAN HURUF YANG SALAH, COBA KEMBALI DAN LEBIH DIPERHATIKAN."<<endl;
		goto mulai;
	}
	awal();
	textcolor(3);
	cout<<" Hallo "<<julukan<<" "<<nama<<" , Selamat Datang Di Sistem Pakar Diagnosa Penyakit Kolesterol. "<<endl;
	textcolor(1);
	cout<<"__________________________________________________________________________________________________"<<endl<<endl;
	textcolor(7);
	cout<<"[ FOR YOUR INFORMATION ]"<<endl;
	cout<<endl;
	cout<<" Sekarang mohon dipilih [1/2/3/4/5] Skala Berdasarkan tingkat gelaja yang Ditanyakan !."<<endl;
	cout<<" [1] = "<<opt1<<endl;
	cout<<" [2] = "<<opt2<<endl;
	cout<<" [3] = "<<opt3<<endl;
	cout<<" [4] = "<<opt4<<endl;
	cout<<" [5] = "<<opt5<<endl;
	cout<<endl;
	textcolor(2);
	cout<<" Untuk Melanjutkan, Silahkan Tekan [ENTER] Untuk Masuk ke Bagian Diagnosa Penyakit"<<endl<<endl;
	system("pause");
	p1:
	awal();
	textcolor(2);
	cout<<" ========================================================:"<<endl;
	cout<<" Nama Ter-Diagnosa = "<<nama<<endl;
	cout<<" ========================================================:"<<endl;
	cout<<endl;
	textcolor(7);
	cout<<" Apakah "<<julukan<<" "<<nama<<" merasakan "<<g01<<" ? "<<endl;
	cout<<endl;
	cout<<" [1] = "<<opt1<<endl;
	cout<<" [2] = "<<opt2<<endl;
	cout<<" [3] = "<<opt3<<endl;
	cout<<" [4] = "<<opt4<<endl;
	cout<<" [5] = "<<opt5<<endl;
	cout<<endl;
	cout<<" Masukkan Pilihan Anda : "<<endl;
	cin>>pilihan1;
	if(pilihan1>5||pilihan1<=0)
	{
		salah();
		goto p1;
	}
	p2:
	awal();
	textcolor(2);
	cout<<" ========================================================:"<<endl;
	cout<<" Nama Ter-Diagnosa = "<<nama<<endl;
	cout<<" ========================================================:"<<endl;
	cout<<endl;
	textcolor(7);
	cout<<" Apakah "<<julukan<<" "<<nama<<" merasa bahwa "<<g02<<" ? "<<endl;
	cout<<endl;
	cout<<" [1] = "<<opt1<<endl;
	cout<<" [2] = "<<opt2<<endl;
	cout<<" [3] = "<<opt3<<endl;
	cout<<" [4] = "<<opt4<<endl;
	cout<<" [5] = "<<opt5<<endl;
	cout<<endl;
	cout<<" Masukkan Pilihan Anda : "<<endl;
	cin>>pilihan2;
	if(pilihan2>5||pilihan2<=0)
	{
		salah();
		goto p2;
	}
	p3:
	awal();
	textcolor(2);
	cout<<" ========================================================:"<<endl;
	cout<<" Nama Ter-Diagnosa = "<<nama<<endl;
	cout<<" ========================================================:"<<endl;
	cout<<endl;
	textcolor(7);
	cout<<" Apakah "<<julukan<<" "<<nama<<" Mengalami "<<g03<<"  ?  "<<endl;
	cout<<endl;
	cout<<" [1] = "<<opt1<<endl;
	cout<<" [2] = "<<opt2<<endl;
	cout<<" [3] = "<<opt3<<endl;
	cout<<" [4] = "<<opt4<<endl;
	cout<<" [5] = "<<opt5<<endl;
	cout<<endl;
	cout<<" Masukkan Pilihan Anda : "<<endl;
	cin>>pilihan3;
	if(pilihan3>5||pilihan3<=0)
	{
		salah();
		goto p3;
	}
	p4:
	awal();
	textcolor(2);
	cout<<" ========================================================:"<<endl;
	cout<<" Nama Ter-Diagnosa = "<<nama<<endl;
	cout<<" ========================================================:"<<endl;
	cout<<endl;
	textcolor(7);
	cout<<" Apakah "<<julukan<<" "<<nama<<" Mengalami "<<g04<<" ? "<<endl;
	cout<<endl;
	cout<<" [1] = "<<opt1<<endl;
	cout<<" [2] = "<<opt2<<endl;
	cout<<" [3] = "<<opt3<<endl;
	cout<<" [4] = "<<opt4<<endl;
	cout<<" [5] = "<<opt5<<endl;
	cout<<endl;
	cout<<" Masukkan Pilihan Anda : "<<endl;
	cin>>pilihan4;
	if(pilihan4>5||pilihan4<=0)
	{
		salah();
		goto p4;
	}
	p5:
	awal();
	textcolor(2);
	cout<<" ========================================================:"<<endl;
	cout<<" Nama Ter-Diagnosa = "<<nama<<endl;
	cout<<" ========================================================:"<<endl;
	cout<<endl;
	textcolor(7);
	cout<<" Apakah "<<julukan<<" "<<nama<<" merasa "<<g05<<" ? "<<endl;
	cout<<endl;
	cout<<" [1] = "<<opt1<<endl;
	cout<<" [2] = "<<opt2<<endl;
	cout<<" [3] = "<<opt3<<endl;
	cout<<" [4] = "<<opt4<<endl;
	cout<<" [5] = "<<opt5<<endl;
	cout<<endl;
	cout<<" Masukkan Pilihan Anda : "<<endl;
	cin>>pilihan5;
	if(pilihan5>5||pilihan5<=0)
	{
		salah();
		goto p5;
	}
	p6:
	awal();
	textcolor(2);
	cout<<" ========================================================:"<<endl;
	cout<<" Nama Ter-Diagnosa = "<<nama<<endl;
	cout<<" ========================================================:"<<endl;
	cout<<endl;
	textcolor(7);
	cout<<" Apakah "<<julukan<<" "<<nama<<" Mengalami "<<g06<<" ? "<<endl;
	cout<<endl;
	cout<<" [1] = "<<opt1<<endl;
	cout<<" [2] = "<<opt2<<endl;
	cout<<" [3] = "<<opt3<<endl;
	cout<<" [4] = "<<opt4<<endl;
	cout<<" [5] = "<<opt5<<endl;
	cout<<endl;
	cout<<" Masukkan Pilihan Anda : "<<endl;
	cin>>pilihan6;
	if(pilihan6>5||pilihan6<=0)
	{
		salah();
		goto p6;
	}
	p7:
	awal();
	textcolor(2);
	cout<<" ========================================================:"<<endl;
	cout<<" Nama Ter-Diagnosa = "<<nama<<endl;
	cout<<" ========================================================:"<<endl;
	cout<<endl;
	textcolor(7);
	cout<<" Apakah "<<julukan<<" "<<nama<<" Mengalami "<<g07<<" ? "<<endl;
	cout<<endl;
	cout<<" [1] = "<<opt1<<endl;
	cout<<" [2] = "<<opt2<<endl;
	cout<<" [3] = "<<opt3<<endl;
	cout<<" [4] = "<<opt4<<endl;
	cout<<" [5] = "<<opt5<<endl;
	cout<<endl;
	cout<<" Masukkan Pilihan Anda : "<<endl;
	cin>>pilihan7;
	if(pilihan7>5||pilihan7<=0)
	{
		salah();
		goto p7;
	}
	p8:
	awal();
	textcolor(2);
	cout<<" ========================================================:"<<endl;
	cout<<" Nama Ter-Diagnosa = "<<nama<<endl;
	cout<<" ========================================================:"<<endl;
	cout<<endl;
	textcolor(7);
	cout<<" Apakah "<<julukan<<" "<<nama<<" Mengalami "<<g08<<" ? "<<endl;
	cout<<endl;
	cout<<" [1] = "<<opt1<<endl;
	cout<<" [2] = "<<opt2<<endl;
	cout<<" [3] = "<<opt3<<endl;
	cout<<" [4] = "<<opt4<<endl;
	cout<<" [5] = "<<opt5<<endl;
	cout<<endl;
	cout<<" Masukkan Pilihan Anda : "<<endl;
	cin>>pilihan8;
	if(pilihan8>5||pilihan8<=0)
	{
		salah();
		goto p8;
	}

	awal();
	textcolor(2);
	cout<<":=================================================================================================:"<<endl;
	cout<<" DIAGNOSA PENYAKIT ATAS NAMA : "<<nama<<" SEDANG DIPROSES, MOHON DITUNGGU [enter]"<<endl;
	cout<<":=================================================================================================:"<<endl;
	cout<<endl;
	textcolor(4);
	system("pause");
	awal();
	textcolor(2);
	cout<<" :==========================================================:"<<endl;
	cout<<" DIAGNOSA PENYAKIT ATAS NAMA : "<<nama<<endl;
	cout<<" :==========================================================:"<<endl;
	cout<<endl;
	cout<<" HASIL DIAGNOSA YANG DIDAPATKAN : "<<endl;
	cout<<endl;
	textcolor(7);
	if(pilihan1==1)
	{
		pil1=a;
		cout<<"-> "<<g01<<" ("<<opt1<<")";
	}
	else if(pilihan1==2)
	{
		pil1=b;
		cout<<"->  "<<g01<<" ("<<opt2<<")";
	}
	else if(pilihan1==3)
	{
		pil1=c;
		cout<<"->  "<<g01<<" ("<<opt3<<")";
	}
	else if(pilihan1==4)
	{
		pil1=d;
		cout<<"->  "<<g01<<" ("<<opt4<<")";
	}
	else if(pilihan1==5)
	{
		pil1=e;
		cout<<"->  "<<g01<<" ("<<opt5<<")";
	}
	ada1=pil1*0.6;
	cout<<endl;
	if(pilihan2==1)
	{
		pil2=a;
		cout<<"-> "<<g02<<" ("<<opt1<<")";
	}
	else if(pilihan2==2)
	{
		pil2=b;
		cout<<"->  "<<g02<<" ("<<opt2<<")";
	}
	else if(pilihan2==3)
	{
		pil2=c;
		cout<<"->  "<<g02<<" ("<<opt3<<")";
	}
	else if(pilihan2==4)
	{
		pil2=d;
		cout<<"->  "<<g02<<" ("<<opt4<<")";
	}
	else if(pilihan2==5)
	{
		pil2=e;
		cout<<"->  "<<g02<<" ("<<opt5<<")";
	}
	ada2=pil2*0.05;
	cout<<endl;
	if(pilihan3==1)
	{
		pil3=a;
		cout<<"-> "<<g03<<" ("<<opt1<<")";
	}
	else if(pilihan3==2)
	{
		pil3=b;
		cout<<"->  "<<g03<<" ("<<opt2<<")";
	}
	else if(pilihan3==3)
	{
		pil3=c;
		cout<<"->  "<<g03<<" ("<<opt3<<")";
	}
	else if(pilihan3==4)
	{
		pil3=d;
		cout<<"->  "<<g03<<" ("<<opt4<<")";
	}
	else if(pilihan3==5)
	{
		pil3=e;
		cout<<"->  "<<g03<<" ("<<opt5<<")";
	}
	ada3=pil3*0.25;
	cout<<endl;
	if(pilihan4==1)
	{
		pil4=a;
		cout<<"-> "<<g04<<" ("<<opt1<<")";
	}
	else if(pilihan4==2)
	{
		pil4=b;
		cout<<"->  "<<g04<<" ("<<opt2<<")";
	}
	else if(pilihan4==3)
	{
		pil4=c;
		cout<<"->  "<<g04<<" ("<<opt3<<")";
	}
	else if(pilihan4==4)
	{
		pil4=d;
		cout<<"->  "<<g04<<" ("<<opt4<<")";
	}
	else if(pilihan4==5)
	{
		pil4=e;
		cout<<"->  "<<g04<<" ("<<opt5<<")";
	}
	ada4=pil4*0.05;
	cout<<endl;
	if(pilihan5==1)
	{
		pil5=a;
		cout<<"-> "<<g05<<" ("<<opt1<<")";
	}
	else if(pilihan5==2)
	{
		pil5=b;
		cout<<"->  "<<g05<<" ("<<opt2<<")";
	}
	else if(pilihan5==3)
	{
		pil5=c;
		cout<<"->  "<<g05<<" ("<<opt3<<")";
	}
	else if(pilihan5==4)
	{
		pil5=d;
		cout<<"->  "<<g05<<" ("<<opt4<<")";
	}
	else if(pilihan5==5)
	{
		pil5=e;
		cout<<"->  "<<g05<<" ("<<opt5<<")";
	}
	ada5=pil5*0.25;
	cout<<endl;
	if(pilihan6==1)
	{
		pil6=a;
		cout<<"-> "<<g06<<" ("<<opt1<<")";
	}
	else if(pilihan6==2)
	{
		pil6=b;
		cout<<"->  "<<g06<<" ("<<opt2<<")";
	}
	else if(pilihan6==3)
	{
		pil6=c;
		cout<<"->  "<<g06<<" ("<<opt3<<")";
	}
	else if(pilihan6==4)
	{
		pil6=d;
		cout<<"->  "<<g06<<" ("<<opt4<<")";
	}
	else if(pilihan6==5)
	{
		pil6=e;
		cout<<"->  "<<g06<<" ("<<opt5<<")";
	}
	float ada6=pil6*0.1;
	cout<<endl;
	if(pilihan7==1)
	{
		pil7=a;
		cout<<"-> "<<g07<<" ("<<opt1<<")";
	}
	else if(pilihan7==2)
	{
		pil7=b;
		cout<<"->  "<<g07<<" ("<<opt2<<")";
	}
	else if(pilihan7==3)
	{
		pil7=c;
		cout<<"->  "<<g07<<" ("<<opt3<<")";
	}
	else if(pilihan7==4)
	{
		pil7=d;
		cout<<"->  "<<g07<<" ("<<opt4<<")";
	}
	else if(pilihan7==5)
	{
		pil7=e;
		cout<<"->  "<<g07<<" ("<<opt5<<")";
	}
	adi1=pil7*0.6;
	cout<<endl;
	if(pilihan8==1)
	{
		pil8=a;
		cout<<"-> "<<g08<<" ("<<opt1<<")";
	}
	else if(pilihan8==2)
	{
		pil8=b;
		cout<<"->  "<<g08<<" ("<<opt2<<")";
	}
	else if(pilihan8==3)
	{
		pil8=c;
		cout<<"->  "<<g08<<" ("<<opt3<<")";
	}
	else if(pilihan8==4)
	{
		pil8=d;
		cout<<"->  "<<g08<<" ("<<opt4<<")";
	}
	else if(pilihan8==5)
	{
		pil8=e;
		cout<<"->  "<<g08<<" ("<<opt5<<")";
	}
	float ada7=pil8*0.05;

	//Menghitung Kolesterol Baik
	float value11,value12,value13,value14,value15,ksp1;
	value11 = ada1 + (ada2 * (1 - ada1));
	value12 = ada3 + (value11 * (1 - ada3));
	value13 = ada4 + (value12 * (1 - ada4));
	value14 = ada5 + (value13 * (1 - ada5));
	ksp1=value14;

    //Menghitung Kolesterol Jahat
     float value21,value22,value23,value24,value25,value26,value27,value28,ksp2;
    value21 = ada1 + (ada2 * (1 - ada1));
	value22 = ada3 + (value21 * (1 - ada3));
	value23 = ada4 + (value22 * (1 - ada4));
	value24 = ada5 + (value23 * (1 - ada5));
	value25 = ada6 + (value24 * (1 - ada6));
	value26 = ada7 + (value25 * (1 - ada7));
	value27 = adi1 + (value26 * (1 - adi1));
	ksp2=value27;

	cout<<endl<<endl;

	float max;
    if ((ksp1>=ksp2))
    {
       max=ksp1;
    }
    else if ((ksp2>ksp1))
    {
        max=ksp2;
    }
    else
    {
        max=0;
    }
    float persen = max*100; //menghitung kedalam bentuk persen
    textcolor(7);

    if (max==ksp1)
    {
        if(max<=0.5)
        {
            cout<<"[anda tidak Mengidap atau Memiliki Penyakit Kolesterol] dengan persentase "<<persen<<" %";
        }
        else
        {
            if (pilihan7!=5||pilihan7!=4)
            {
                cout<<"Sesuai Dengan Gejala yang Sudah Diberikan "<<endl;
                cout<<julukan<<" "<<nama<<" Terdiagnosa Penyakit "<<p01<<" Dengan Tingkat Keyakinan Sebesar ";
                textcolor(4);
                cout<<persen<<" %"<<endl;
                cout<<"Hal yang harus dilakukan adalah"<<endl;
                cout<<"1. Rutin Berolahraga"<<endl;
                cout<<"2. Menghentikan Kebiasaan Merokok"<<endl;
                cout<<"3. Membatasi Asupan Makanan yang Mengandung Gula dan Lemak Jahat"<<endl;
                cout<<"4. Memperbanyak Asupan Serat"<<endl;
            }
            else
            {
                textcolor(7);
                cout<<"Sesuai Dengan Gejala yang Sudah Diberikan "<<endl;
                cout<<julukan<<" "<<nama<<" Terdiagnosa Penyakit "<<p02<<" Dengan Tingkat Keyakinan Sebesar ";
                textcolor(4);
                cout<<persen<<" %"<<endl;
                cout<<"1. Rutin Berolahraga"<<endl;
                cout<<"2. Menghentikan Kebiasaan Merokok"<<endl;
                cout<<"3. Membatasi Asupan Makanan yang Mengandung Gula dan Lemak Jahat"<<endl;
                cout<<"4. Memperbanyak Asupan Serat"<<endl;
            }
        }
    }
    else if (max==ksp2)
    {
    	textcolor(7);
        cout<<"Sesuai Dengan Gejala yang Sudah Diberikan "<<endl;
		cout<<julukan<<" "<<nama<<" Terdiagnosa Penyakit "<<p02<<" Dengan Tingkat Keyakinan Sebesar ";
		textcolor(4);
		cout<<persen<<" %"<<endl;
		cout<<"1. Rutin Berolahraga"<<endl;
		cout<<"2. Menghentikan Kebiasaan Merokok"<<endl;
		cout<<"3. Membatasi Asupan Makanan yang Mengandung Gula dan Lemak Jahat"<<endl;
		cout<<"4. Memperbanyak Asupan Serat"<<endl;
    }
    cout<<endl<<endl;
    cout<<endl;

	akhir:
		textcolor(1);
	cout<<" Apakah "<<julukan<<" "<<nama<<" Ingin Mengulang Proses Diagnosa Penyakit Kolesterol ini ? [y/n]"<<endl;
	cin>>ulang;
	cout<<endl<<endl;
	if (ulang=='y'||ulang=='Y')
	{
		goto mulai;
	}
	else if (ulang=='n'||ulang=='N')
   {
   		textcolor(4);
		cout<<"[ ANDA TELAH KELUAR DARI SISTEM PAKAR DIAGNOSA PENYAKIT KOLESTEROL, TERIMA KASIH. ]"<<endl;
   }
   else
   {
   	    cout<<" ANDA MEMASUKKAN HURUF YANG SALAH, COBA LAGI & MOHON DIPERHATIKAN"<<endl;
   	    cout<<endl;
   	    goto akhir;
   	    system("cls");
   }
}


