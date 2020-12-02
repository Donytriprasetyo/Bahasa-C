#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<windows.h>
#include <time.h>

void gotoxy(int batas1, int batas2)
{
    HANDLE crusor;
    COORD to;
    to.X = batas1;
    to.Y = batas2;
    crusor = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(crusor,to);
}

void readPass(char *temp) {
    int key = 0, index = 0;

    do {
        key = getch();

        switch (key) {

            case '\b':
                if (index > 0) {
                    index = index - 1;
                    temp[index] = 0;

                    printf("\b \b");
                }

                break;
            default:
                if (key > 31 && key < 127) {
                    temp[index] = key;
                    index = index + 1;

                    printf("*");
                }
        }
    } while (key != 13);
    temp[index] = '\0';
}

void loading(int x,int y){
	system("cls");
	int i;
	gotoxy(x,y-1);printf("Loading...");


	for(i=x;i<=x+19;i++){
	    gotoxy(i,y);printf("%c",196);
		gotoxy(i,y+1);printf("%c",196);
	}
	for(i=y;i<=y+1;i++){
	    gotoxy(x,i);printf("%c",179);
		gotoxy(x+19,i);printf("%c",179);
	}
	gotoxy(x,y);printf("%c",218);
	gotoxy(x+19,y);printf("%c",191);
	gotoxy(x,y+1);printf("%c",192);
	gotoxy(x+19,y+1);printf("%c",217);
	for ( i = x; i<=x+19;i++){
		gotoxy(i,y);printf("%c",220);
		gotoxy(i,y+1);printf("%c",223);
		Sleep(20);
	}
	system("cls");
}

typedef struct deklarasi
{

    char nama[100];
    int nim;
    char progdi[100];
    char alamat[100];
    char asal[100];

    char s_nama[100];
    int s_nim;
    char s_progdi[100];
    char s_alamat[100];
    char s_asal[100];

    int tempat;

    char riwayat[100];
}z;


int a,c,d,edit,cari,sort,h,r[100];
int b = 1;
int pilihan;
int input;
int input1;
char temp1[100];
char hapus[100];
char edit1[100];
char cari1 [100];
char edit2[100];
char y;


int login()
{
    struct tm *Sys_T;

    time_t Tval;
    Tval = time(NULL);
    Sys_T = localtime(&Tval);
    system("cls");
    char username[100];
    char password[100];
    login :
    system("color 1E");
    system("cls");
    gotoxy(34,6);
    printf("+---------------------------------------------------+"); //41
    gotoxy(53,7);
    printf("LOGIN DULU KAK!");
    gotoxy(34,8);
    printf("+---------------------------------------------------+"); //41
    for (a=9;a<=12;a++)
    {
        gotoxy(34,a);
        printf("|");
        gotoxy(86,a);
        printf("|");
    }
    gotoxy(34,13);
    printf("====================================================="); //41
    gotoxy(50,10);
    printf("USERNAME : ");
    gotoxy(50,11);
    printf("PASSWORD : ");
    gotoxy(36,14);
    printf("TODAY : %d-%d-%d",Sys_T->tm_mday,Sys_T->tm_mon+1,1900+Sys_T->tm_year);
    gotoxy(61,10);
    gets(username);
    gotoxy(61,11);
    readPass(password);
    if(strcmp(username,"admin")==0 && strcmp(password,"admin")==0){
            gotoxy(34,15);
            printf("------------------ Akses Diterima -------------------\n");
            gotoxy(34,16);
            system("pause");
        } else{
             gotoxy(34,15);
             printf("------------ Username & Password Invalid ------------\n");
             gotoxy(34,16);
             system("pause");
             goto login;
        }
}

int main()
{
    struct tm *Sys_T;

    time_t Tval;
    Tval = time(NULL);
    Sys_T = localtime(&Tval);
    login();
    loading(50,15);
    z data[100];
    awal :
    system("color 1F");
    system("cls");
    gotoxy(29,3);
    printf("+");
    gotoxy(101,3);
    printf("+");

    for(a=30;a<=100;a++)
    {
        gotoxy(a,3);
        printf("-");
    }
    gotoxy(47,5);
    char opening[]="SELAMAT DATANG DI DATA MAHASISWA ADMIN";
    for (a=0;a<strlen(opening);a++)
    {
        printf("%c",opening[a]);
        Sleep(1);
    }
    gotoxy(55,6);
    printf("=== PROGRAM ADMIN ===");
    gotoxy(29,8);
    printf("+");
    gotoxy(101,8);
    printf("+");
    for(a=30;a<=100;a++)
    {
        gotoxy(a,8);
        printf("-");
    }
    for(a=9;a<=21;a++)
    {
        gotoxy(29,a);
        printf("|");
        gotoxy(101,a);
        printf("|");
    }
    gotoxy(40,10);
    printf("Tekan 1 ---> Membuat Database Baru Mahasiswa");
    gotoxy(40,11);
    printf("Tekan 2 ---> Menampilkan Isi Database Mahasiswa");
    gotoxy(40,12);
    printf("Tekan 3 ---> Menambah Data Baru ke Database Mahasiswa");
    gotoxy(40,13);
    printf("Tekan 4 ---> Menghapus Data di Database Mahasiswa");
    gotoxy(40,14);
    printf("Tekan 5 ---> Mengedit Data di Database Mahasiswa");
    gotoxy(40,15);
    printf("Tekan 6 ---> Mencari Data di Database Mahasiswa");
    gotoxy(40,16);
    printf("Tekan 7 ---> Riwayat Aktivitas Mahasiswa");
    gotoxy(40,17);
    printf("Tekan 8 ---> Mengurutkan Data di Database Mahasiswa");
    gotoxy(40,18);
    printf("Tekan 9 ---> Keluar dari program");
    gotoxy(29,22);
    printf("+");
    gotoxy(101,22);
    printf("+");
    for(a=30;a<=100;a++)
    {
        gotoxy(a,22);
        printf("-");
    }
    gotoxy(40,20);
    printf("Masukkan Pilihan Anda ===> ");
    scanf("%d",&pilihan);
    if (pilihan>=1 && pilihan<=9)
    {
    switch(pilihan)
    {
    case 1:
        buat :
    system("color 8E");
    system("cls");
    gotoxy(29,3);
    printf("+");
    gotoxy(101,3);
    printf("+");
    for(a=30;a<=100;a++)
    {
        gotoxy(a,3);
        printf("-");
    }
    gotoxy(57,5);
    printf("DATA MAHASISWA ADMIN");
    gotoxy(48,6);
    printf("===Membuat Database Baru Mahasiswa===");
    gotoxy(29,8);
    printf("+");
    gotoxy(101,8);
    printf("+");
    for(a=30;a<=100;a++)
    {
        gotoxy(a,8);
        printf("-");
    }
    gotoxy(29,11);
    printf("+");
    gotoxy(101,11);
    printf("+");
    for(a=30;a<=100;a++)
    {
        gotoxy(a,11);
        printf("-");
    }
    gotoxy(48,9);
    printf("Data Maksimum yang bisa diinput ---> 4");
    gotoxy(48,10);
    printf("Banyak data yang ingin diinput  ---> ");
    scanf("%d",&input);
    h++;
    r[h] = input;
    strcpy(data[h].riwayat,"Admin telah membuat data ");
    if (input>4)
    {
        gotoxy(88,10);
        printf("(Max 4)");
        input = 4;
    }
    input1 = input+b-1;
    printf("\n");
    for (b;b<=input1;b++)
    {
        printf("\n\t\t\t\t DATA MAHASISWA KE-%d",b);
        printf("\n\t\t\t\t NAMA MAHASISWA \t: ");
        fflush(stdin);
        gets(data[b].nama);
        printf("\t\t\t\t NIM MAHASISWA \t\t: ");
        scanf("%d",&data[b].nim);
        printf("\t\t\t\t PROGDI MAHASISWA \t: ");
        fflush(stdin);
        gets(data[b].progdi);
        printf("\t\t\t\t ALAMAT MAHASISWA \t: ");
        fflush(stdin);
        gets(data[b].alamat);
        printf("\t\t\t\t ASAL MAHASISWA \t: ");
        fflush(stdin);
        gets(data[b].asal);
    }
    system("pause");
    goto awal;
    break;
    case 2:
    system("color 8E");
    system("cls");
    gotoxy(19,3);
    printf("+");
    gotoxy(111,3);
    printf("+");
    for(a=20;a<=110;a++)
    {
        gotoxy(a,3);
        printf("-");
    }
    gotoxy(57,5);
    printf("DATA MAHASISWA ADMIN");
    gotoxy(47,6);
    printf("===DATA MAHASISWA YANG TELAH DIINPUT===");
    gotoxy(19,8);
    printf("+");
    gotoxy(111,8);
    printf("+");
    for(a=20;a<=110;a++)
    {
        gotoxy(a,8);
        printf("-");
    }
    gotoxy(19,10);
    printf("+");
    gotoxy(111,10);
    printf("+");
    for(a=20;a<=110;a++)
    {
        gotoxy(a,10);
        printf("-");
    }
    gotoxy(20,9);
    printf("NAMA");
    gotoxy(38,9);
    printf("NIM");
    gotoxy(56,9);
    printf("PROGDI");
    gotoxy(74,9);
    printf("ALAMAT");
    gotoxy(92,9);
    printf("ASAL");
    if (data[1].nim=='\0')
    {
        gotoxy(19,12);
        printf("+");
        gotoxy(111,12);
        printf("+");
        for(a=20;a<=110;a++)
        {
            gotoxy(a,12);
            printf("-");
        }
        gotoxy(20,11);
        printf("NO DATA !!!");
        gotoxy(20,13);
        system("pause");
        goto awal;
    }
    else
    {
    for(a=1;a<=input1;a++){
            if (data[a].nim==0){
            strcpy(data[a].nama,data[a+1].nama);
            data[a].nim=data[a+1].nim;
            strcpy(data[a].progdi,data[a+1].progdi);
            strcpy(data[a].alamat,data[a+1].alamat);
            strcpy(data[a].asal,data[a+1].asal);
            input1--;
            }
    }
    for (c=11;c<11+input1;c++){
        for(d=c-10;d<=c-10;d++){
            gotoxy(20,c);
            printf("%s",data[d].nama);
            gotoxy(38,c);
            printf("%d",data[d].nim);
            gotoxy(56,c);
            printf("%s",data[d].progdi);
            gotoxy(74,c);
            printf("%s",data[d].alamat);
            gotoxy(92,c);
            printf("%s",data[d].asal);
        }
    }
    gotoxy(19,c+1);
    printf("+");
    gotoxy(111,c+1);
    printf("+");
    for(a=20;a<=110;a++)
    {
        gotoxy(a,c+1);
        printf("-");
    }
    }
    printf("\n\n");
    system("pause");
    goto awal;
    break;
    case 3:
    system("cls");
    system("color 8E");
    gotoxy(29,3);
    printf("+");
    gotoxy(101,3);
    printf("+");
    for(a=30;a<=100;a++)
    {
        gotoxy(a,3);
        printf("-");
    }
    gotoxy(57,5);
    printf("DATA MAHASISWA ADMIN");
    gotoxy(48,6);
    printf("===Memnambah Database Baru Mahasiswa===");
    gotoxy(29,8);
    printf("+");
    gotoxy(101,8);
    printf("+");
    for(a=30;a<=100;a++)
    {
        gotoxy(a,8);
        printf("-");
    }
    gotoxy(29,11);
    printf("+");
    gotoxy(101,11);
    printf("+");
    for(a=30;a<=100;a++)
    {
        gotoxy(a,11);
        printf("-");
    }
    gotoxy(48,9);
    printf("Data Maksimum yang bisa diinput ---> 4");
    gotoxy(48,10);
    printf("Banyak data yang ingin diinput  ---> ");
    scanf("%d",&input);
    h++;
    r[h] = input;
    strcpy(data[h].riwayat,"Admin telah menambahkan data");
    if (input>4)
    {
        gotoxy(88,10);
        printf("(Max 4)");
        input = 4;
    }
    input1 = input+b-1;
    printf("\n");
    for (b;b<=input1;b++)
    {
        printf("\n\t\t\t\t DATA MAHASISWA KE-%d",b);
        printf("\n\t\t\t\t NAMA MAHASISWA \t: ");
        fflush(stdin);
        gets(data[b].nama);
        printf("\t\t\t\t NIM MAHASISWA \t\t: ");
        scanf("%d",&data[b].nim);
        printf("\t\t\t\t PROGDI MAHASISWA \t: ");
        fflush(stdin);
        gets(data[b].progdi);
        printf("\t\t\t\t ALAMAT MAHASISWA \t: ");
        fflush(stdin);
        gets(data[b].alamat);
        printf("\t\t\t\t ASAL MAHASISWA \t: ");
        fflush(stdin);
        gets(data[b].asal);
    }
    system("pause");
    goto awal;
    case 4:
        if (data[1].nim=='\0')
        {
            goto buat;
        }
        else
        {
    system("cls");
    system("color 8E");
    gotoxy(29,3);
    printf("+");
    gotoxy(101,3);
    printf("+");
    for(a=30;a<=100;a++)
    {
        gotoxy(a,3);
        printf("-");
    }
    gotoxy(57,5);
    printf("DATA MAHASISWA ADMIN");
    gotoxy(48,6);
    printf("===Menghapus Database Baru Mahasiswa===");
    gotoxy(29,8);
    printf("+");
    gotoxy(101,8);
    printf("+");
    for(a=30;a<=100;a++)
    {
        gotoxy(a,8);
        printf("-");
    }
    gotoxy(29,10);
    printf("+");
    gotoxy(101,10);
    printf("+");
    for(a=30;a<=100;a++)
    {
        gotoxy(a,10);
        printf("-");
    }
    gotoxy(40,9);
    printf("Masukkan NIM yang ingin dihapus ---> ");
    gotoxy(78,9);
    int hapusn;
    scanf("%d",&hapusn);
    h++;
    r[h] = hapusn;
    strcpy(data[h].riwayat,"Admin telah menghapus data dengan nim ");
    for (a=1;a<=input1;a++){
    if (data[a].nim==hapusn)
    {
        printf("\n\t\t\t\t NAMA MAHASISWA \t: %s",data[a].nama);
        printf("\n\t\t\t\t NIM MAHASISWA \t\t: %d",data[a].nim);
        printf("\n\t\t\t\t PROGDI MAHASISWA \t: %s",data[a].progdi);
        printf("\n\t\t\t\t ALAMAT MAHASISWA \t: %s",data[a].alamat);
        printf("\n\t\t\t\t ASAL MAHASISWA \t: %s",data[a].asal);
        printf("\n\t\t\t\t Lanjutkan Menghapus ? [y|n] ---> ");
        scanf("%s",&y);
        if (y=='y')
        {
            for(a;a<=input1;a++){
            strcpy(data[a].nama,data[a+1].nama);
            data[a].nim=data[a+1].nim;
            strcpy(data[a].progdi,data[a+1].progdi);
            strcpy(data[a].alamat,data[a+1].alamat);
            strcpy(data[a].asal,data[a+1].asal);
            }
            data[input1].nim=0;
            printf("\n\t\t\t\t NIM %d berhasil di hapus\n",hapusn);
            printf("\n\t\t\t\t");
            system("pause");
            goto awal;
        }
        else if (y=='n')
        {
            goto awal;
        }
        }
    }
    printf("\n\n\t\t\t\t NIM %d belum terdaftar\n",hapusn);
    }
    printf("\n\t\t\t\t");
    system("pause");
    goto awal;
    break;
    case 5:
    edit3 :
    system("cls");
    system("color 8E");
    gotoxy(29,3);
    printf("+");
    gotoxy(101,3);
    printf("+");
    for(a=30;a<=100;a++)
    {
        gotoxy(a,3);
        printf("-");
    }
    gotoxy(57,5);
    printf("DATA MAHASISWA ADMIN");
    gotoxy(52,6);
    printf("===Mengedit Data Mahasiswa===");
    gotoxy(29,8);
    printf("+");
    gotoxy(101,8);
    printf("+");
    for(a=30;a<=100;a++)
    {
        gotoxy(a,8);
        printf("-");
    }
    gotoxy(29,14);
    printf("+");
    gotoxy(101,14);
    printf("+");
    for(a=30;a<=100;a++)
    {
        gotoxy(a,14);
        printf("-");
    }
    gotoxy(37,9);
    printf("Apa yang ingin anda edit ?");
    gotoxy(37,10);
    printf("1. Nama Mahasiswa");
    gotoxy(63,10);
    printf("3. Progdi Mahasiswa");
    gotoxy(37,11);
    printf("2. Alamat Mahasiswa");
    gotoxy(63,11);
    printf("4. Asal Mahasiswa");
    gotoxy(37,12);
    printf("Pilihan Anda           ---> ");
    gotoxy(37,13);
    printf("Masukkan NIM Mahasiswa ---> ");
    gotoxy(66,12);
    scanf("%d",&edit);
    gotoxy(66,13);
    int edit1;
    scanf("%d",&edit1);
    switch(edit)
    {
    case 1:
        for (a=1;a<=input1;a++){
            if (data[a].nim==edit1){
                gotoxy(37,16);
                printf("UBAH DATA");
                gotoxy(37,17);
                printf("Data saat ini  : %s",data[a].nama);
                gotoxy(37,18);
                printf("Data yang baru : ");
                fflush(stdin);
                gets(edit2);
                strcpy(data[a].nama,edit2);
                gotoxy(37,20);
                printf("Data berhasil diubah !!!");
                gotoxy(37,22);
                h++;
                r[h] = edit1;
                strcpy(data[h].riwayat,"Admin telah mengubah nama di nim  ");
                system("pause");
                goto awal;
            }
        }
        break;
    case 2:
        for (a=1;a<=input1;a++){
            if (data[a].nim==edit1){
                gotoxy(37,16);
                printf("UBAH DATA");
                gotoxy(37,17);
                printf("Data saat ini  : %s",data[a].alamat);
                gotoxy(37,18);
                printf("Data yang baru : ");
                fflush(stdin);
                gets(edit2);
                strcpy(data[a].alamat,edit2);
                gotoxy(37,20);
                printf("Data berhasil diubah !!!");
                gotoxy(37,22);
                h++;
                r[h] = edit1;
                strcpy(data[h].riwayat,"Admin telah mengubah alamat di nim  ");
                system("pause");
                goto awal;
            }
        }
        break;
    case 3:
        for (a=1;a<=input1;a++){
            if (data[a].nim==edit1){
                gotoxy(37,16);
                printf("UBAH DATA");
                gotoxy(37,17);
                printf("Data saat ini  : %s",data[a].progdi);
                gotoxy(37,18);
                printf("Data yang baru : ");
                fflush(stdin);
                gets(edit2);
                strcpy(data[a].progdi,edit2);
                gotoxy(37,20);
                printf("Data berhasil diubah !!!");
                gotoxy(37,22);
                h++;
                r[h] = edit1;
                strcpy(data[h].riwayat,"Admin telah mengubah progdi di nim  ");
                system("pause");
                goto awal;
            }
        }
        break;
    case 4:
        for (a=1;a<=input1;a++){
            if (data[a].nim==edit1){
                gotoxy(37,16);
                printf("UBAH DATA");
                gotoxy(37,17);
                printf("Data saat ini  : %s",data[a].asal);
                gotoxy(37,18);
                printf("Data yang baru : ");
                fflush(stdin);
                gets(edit2);
                strcpy(data[a].asal,edit2);
                gotoxy(37,20);
                printf("Data berhasil diubah !!!");
                gotoxy(37,22);
                h++;
                r[h] = edit1;
                strcpy(data[h].riwayat,"Admin telah mengubah asal di nim  ");
                system("pause");
                goto awal;
            }
        }
        break;
    default:
        goto edit3;
    }
    gotoxy(37,18);
    printf("NIM %d Belum Terdaftar !!!",edit1);
    gotoxy(37,20);
    system("pause");
    goto awal;
    case 6:
    system("cls");
    system("color 8E");
    gotoxy(29,3);
    printf("+");
    gotoxy(101,3);
    printf("+");
    for(a=30;a<=100;a++)
    {
        gotoxy(a,3);
        printf("-");
    }
    gotoxy(57,5);
    printf("DATA MAHASISWA ADMIN");
    gotoxy(52,6);
    printf("===Mencari Data Mahasiswa===");
    gotoxy(29,8);
    printf("+");
    gotoxy(101,8);
    printf("+");
    for(a=30;a<=100;a++)
    {
        gotoxy(a,8);
        printf("-");
    }
    gotoxy(29,16);
    printf("+");
    gotoxy(101,16);
    printf("+");
    for(a=30;a<=100;a++)
    {
        gotoxy(a,16);
        printf("-");
    }
    gotoxy(37,9);
    printf("Apa yang ingin anda cari ?");
    gotoxy(37,10);
    printf("1. Nama Mahasiswa");
    gotoxy(37,11);
    printf("2. NIM Mahasiswa");
    gotoxy(37,12);
    printf("3. Progdi Mahasiswa");
    gotoxy(63,10);
    printf("4. Alamat Mahasiswa");
    gotoxy(63,11);
    printf("5. Asal Mahasiswa");
    gotoxy(37,14);
    printf("Pilihan Anda              ---> ");
    gotoxy(68,14);
    scanf("%d",&cari);
    c=10;
    switch(cari)
    {
    case 1:
        gotoxy(37,15);
        printf("Masukkan Nama Mahasiswa   ---> ");
        scanf("%s",cari1);
        system("color 8E");
        system("cls");
        gotoxy(19,3);
        printf("+");
        gotoxy(111,3);
        printf("+");
        for(a=20;a<=110;a++)
        {
            gotoxy(a,3);
            printf("-");
        }
        gotoxy(57,5);
        printf("DATA MAHASISWA ADMIN");
        gotoxy(51,6);
        printf("===DATA MAHASISWA YANG DICARI===");
        gotoxy(19,8);
        printf("+");
        gotoxy(111,8);
        printf("+");
        for(a=20;a<=110;a++)
        {
            gotoxy(a,8);
            printf("-");
        }
        gotoxy(19,10);
        printf("+");
        gotoxy(111,10);
        printf("+");
        for(a=20;a<=110;a++)
        {
            gotoxy(a,10);
            printf("-");
        }
        gotoxy(20,9);
        printf("NAMA");
        gotoxy(38,9);
        printf("NIM");
        gotoxy(56,9);
        printf("PROGDI");
        gotoxy(74,9);
        printf("ALAMAT");
        gotoxy(92,9);
        printf("ASAL");
            for (a=1;a<=input1;a++){
                if (strcmp(data[a].nama,cari1)==0)
                {
                    c++;
                    gotoxy(20,c);
                    printf("%s",data[a].nama);
                    gotoxy(38,c);
                    printf("%d",data[a].nim);
                    gotoxy(56,c);
                    printf("%s",data[a].progdi);
                    gotoxy(74,c);
                    printf("%s",data[a].alamat);
                    gotoxy(92,c);
                    printf("%s",data[a].asal);
                }
        }
        gotoxy(19,c+1);
        printf("+");
        gotoxy(111,c+1);
        printf("+");
        for(a=20;a<=110;a++)
        {
            gotoxy(a,c+1);
            printf("-");
        }
        printf("\n\n");
        system("pause");
        goto awal;
        break;
    case 2:
        gotoxy(37,15);
        printf("Masukkan NIM Mahasiswa    ---> ");
        int cari1n;
        scanf("%d",&cari1n);
        system("cls");
        gotoxy(19,3);
        printf("+");
        gotoxy(111,3);
        printf("+");
        for(a=20;a<=110;a++)
        {
            gotoxy(a,3);
            printf("-");
        }
        gotoxy(57,5);
        printf("DATA MAHASISWA ADMIN");
        gotoxy(51,6);
        printf("===DATA MAHASISWA YANG DICARI===");
        gotoxy(19,8);
        printf("+");
        gotoxy(111,8);
        printf("+");
        for(a=20;a<=110;a++)
        {
            gotoxy(a,8);
            printf("-");
        }
        gotoxy(19,10);
        printf("+");
        gotoxy(111,10);
        printf("+");
        for(a=20;a<=110;a++)
        {
            gotoxy(a,10);
            printf("-");
        }
        gotoxy(20,9);
        printf("NAMA");
        gotoxy(38,9);
        printf("NIM");
        gotoxy(56,9);
        printf("PROGDI");
        gotoxy(74,9);
        printf("ALAMAT");
        gotoxy(92,9);
        printf("ASAL");
            for (a=1;a<=input1;a++){
                if (data[a].nim==cari1n)
                {
                    c++;
                    gotoxy(20,c);
                    printf("%s",data[a].nama);
                    gotoxy(38,c);
                    printf("%d",data[a].nim);
                    gotoxy(56,c);
                    printf("%s",data[a].progdi);
                    gotoxy(74,c);
                    printf("%s",data[a].alamat);
                    gotoxy(92,c);
                    printf("%s",data[a].asal);
                }
        }
        gotoxy(19,c+1);
        printf("+");
        gotoxy(111,c+1);
        printf("+");
        for(a=20;a<=110;a++)
        {
            gotoxy(a,c+1);
            printf("-");
        }
        printf("\n\n");
        system("pause");
        goto awal;
        break;
    case 3:
        gotoxy(37,15);
        printf("Masukkan Progdi Mahasiswa ---> ");
        scanf("%s",cari1);
        system("cls");
        gotoxy(19,3);
        printf("+");
        gotoxy(111,3);
        printf("+");
        for(a=20;a<=110;a++)
        {
            gotoxy(a,3);
            printf("-");
        }
        gotoxy(57,5);
        printf("DATA MAHASISWA ADMIN");
        gotoxy(51,6);
        printf("===DATA MAHASISWA YANG DICARI===");
        gotoxy(19,8);
        printf("+");
        gotoxy(111,8);
        printf("+");
        for(a=20;a<=110;a++)
        {
            gotoxy(a,8);
            printf("-");
        }
        gotoxy(19,10);
        printf("+");
        gotoxy(111,10);
        printf("+");
        for(a=20;a<=110;a++)
        {
            gotoxy(a,10);
            printf("-");
        }
        gotoxy(20,9);
        printf("NAMA");
        gotoxy(38,9);
        printf("NIM");
        gotoxy(56,9);
        printf("PROGDI");
        gotoxy(74,9);
        printf("ALAMAT");
        gotoxy(92,9);
        printf("ASAL");
            for (a=1;a<=input1;a++){
                if (strcmp(data[a].progdi,cari1)==0)
                {
                    c++;
                    gotoxy(20,c);
                    printf("%s",data[a].nama);
                    gotoxy(38,c);
                    printf("%d",data[a].nim);
                    gotoxy(56,c);
                    printf("%s",data[a].progdi);
                    gotoxy(74,c);
                    printf("%s",data[a].alamat);
                    gotoxy(92,c);
                    printf("%s",data[a].asal);
                }
        }
        gotoxy(19,c+1);
        printf("+");
        gotoxy(111,c+1);
        printf("+");
        for(a=20;a<=110;a++)
        {
            gotoxy(a,c+1);
            printf("-");
        }
        printf("\n\n");
        system("pause");
        goto awal;
        break;
    case 4:
        gotoxy(37,15);
        printf("Masukkan Alamat Mahasiswa ---> ");
        scanf("%s",cari1);
        system("cls");
        gotoxy(19,3);
        printf("+");
        gotoxy(111,3);
        printf("+");
        for(a=20;a<=110;a++)
        {
            gotoxy(a,3);
            printf("-");
        }
        gotoxy(57,5);
        printf("DATA MAHASISWA ADMIN");
        gotoxy(51,6);
        printf("===DATA MAHASISWA YANG DICARI===");
        gotoxy(19,8);
        printf("+");
        gotoxy(111,8);
        printf("+");
        for(a=20;a<=110;a++)
        {
            gotoxy(a,8);
            printf("-");
        }
        gotoxy(19,10);
        printf("+");
        gotoxy(111,10);
        printf("+");
        for(a=20;a<=110;a++)
        {
            gotoxy(a,10);
            printf("-");
        }
        gotoxy(20,9);
        printf("NAMA");
        gotoxy(38,9);
        printf("NIM");
        gotoxy(56,9);
        printf("PROGDI");
        gotoxy(74,9);
        printf("ALAMAT");
        gotoxy(92,9);
        printf("ASAL");
            for (a=1;a<=input1;a++){
                if (strcmp(data[a].alamat,cari1)==0)
                {
                    c++;
                    gotoxy(20,c);
                    printf("%s",data[a].nama);
                    gotoxy(38,c);
                    printf("%d",data[a].nim);
                    gotoxy(56,c);
                    printf("%s",data[a].progdi);
                    gotoxy(74,c);
                    printf("%s",data[a].alamat);
                    gotoxy(92,c);
                    printf("%s",data[a].asal);
                }
        }
        gotoxy(19,c+1);
        printf("+");
        gotoxy(111,c+1);
        printf("+");
        for(a=20;a<=110;a++)
        {
            gotoxy(a,c+1);
            printf("-");
        }
        printf("\n\n");
        system("pause");
        goto awal;
        break;
    case 5:
        gotoxy(37,15);
        printf("Masukkan Asal Mahasiswa   ---> ");
        scanf("%s",cari1);
        system("cls");
        gotoxy(19,3);
        printf("+");
        gotoxy(111,3);
        printf("+");
        for(a=20;a<=110;a++)
        {
            gotoxy(a,3);
            printf("-");
        }
        gotoxy(57,5);
        printf("DATA MAHASISWA ADMIN");
        gotoxy(51,6);
        printf("===DATA MAHASISWA YANG DICARI===");
        gotoxy(19,8);
        printf("+");
        gotoxy(111,8);
        printf("+");
        for(a=20;a<=110;a++)
        {
            gotoxy(a,8);
            printf("-");
        }
        gotoxy(19,10);
        printf("+");
        gotoxy(111,10);
        printf("+");
        for(a=20;a<=110;a++)
        {
            gotoxy(a,10);
            printf("-");
        }
        gotoxy(20,9);
        printf("NAMA");
        gotoxy(38,9);
        printf("NIM");
        gotoxy(56,9);
        printf("PROGDI");
        gotoxy(74,9);
        printf("ALAMAT");
        gotoxy(92,9);
        printf("ASAL");
            for (a=1;a<=input1;a++){
                if (strcmp(data[a].asal,cari1)==0)
                {
                    c++;
                    gotoxy(20,c);
                    printf("%s",data[a].nama);
                    gotoxy(38,c);
                    printf("%d",data[a].nim);
                    gotoxy(56,c);
                    printf("%s",data[a].progdi);
                    gotoxy(74,c);
                    printf("%s",data[a].alamat);
                    gotoxy(92,c);
                    printf("%s",data[a].asal);
                }
        }
        gotoxy(19,c+1);
        printf("+");
        gotoxy(111,c+1);
        printf("+");
        for(a=20;a<=110;a++)
        {
            gotoxy(a,c+1);
            printf("-");
        }
        printf("\n\n");
        system("pause");
        goto awal;
        break;
    }
    case 7:
    system("cls");
    system("color 8E");
    gotoxy(29,3);
    printf("+");
    gotoxy(101,3);
    printf("+");
    for(a=30;a<=100;a++)
    {
        gotoxy(a,3);
        printf("-");
    }
    gotoxy(57,5);
    printf("DATA MAHASISWA ADMIN");
    gotoxy(52,6);
    printf("===RIWAYAT AKTIVITAS ADMIN===");
    gotoxy(29,8);
    printf("+");
    gotoxy(101,8);
    printf("+");
    for(a=30;a<=100;a++)
    {
        gotoxy(a,8);
        printf("-");
    }
    gotoxy(30,9);
    printf("NO.");
    gotoxy(35,9);
    printf("TANGGAL");
    gotoxy(50,9);
    printf("AKTIVITAS");
    gotoxy(29,10);
    printf("+");
    gotoxy(101,10);
    printf("+");
    for(a=30;a<=100;a++)
    {
        gotoxy(a,10);
        printf("-");
    }
    for (c=11;c<11+h;c++){
        for(d=c-10;d<=c-10;d++){
            gotoxy(30,c);
            printf("%d",d);
            gotoxy(36,c);
            printf("%d-%d-%d",Sys_T->tm_mday,Sys_T->tm_mon+1,1900+Sys_T->tm_year);
            gotoxy(50,c);
            printf("%s %d",data[d].riwayat,r[d]);
        }
    }
    gotoxy(29,c+1);
    printf("+");
    gotoxy(101,c+1);
    printf("+");
    for(a=30;a<=100;a++)
    {
        gotoxy(a,c+1);
        printf("-");
    }
    gotoxy(20,c+2);
    system("pause");
    goto awal;
    break;
    case 8:
    system("cls");
    system("color 8E");
    if (data[1].nim=='\0')
    {
        printf("NO DATA !!!\n");
        system("pause");
        goto awal;
    }
    else
    {
    gotoxy(29,3);
    printf("+");
    gotoxy(101,3);
    printf("+");
    for(a=30;a<=100;a++)
    {
        gotoxy(a,3);
        printf("-");
    }
    gotoxy(57,5);
    printf("DATA MAHASISWA ADMIN");
    gotoxy(52,6);
    printf("===Mensorting Data Mahasiswa===");
    gotoxy(29,8);
    printf("+");
    gotoxy(101,8);
    printf("+");
    for(a=30;a<=100;a++)
    {
        gotoxy(a,8);
        printf("-");
    }
    gotoxy(29,16);
    printf("+");
    gotoxy(101,16);
    printf("+");
    for(a=30;a<=100;a++)
    {
        gotoxy(a,16);
        printf("-");
    }
    gotoxy(37,9);
    printf("Apa yang ingin anda cari ?");
    gotoxy(37,10);
    printf("1. Nama Mahasiswa");
    gotoxy(37,11);
    printf("2. NIM Mahasiswa");
    gotoxy(37,12);
    printf("3. Progdi Mahasiswa");
    gotoxy(63,10);
    printf("4. Alamat Mahasiswa");
    gotoxy(63,11);
    printf("5. Asal Mahasiswa");
    gotoxy(37,14);
    printf("Pilihan Anda              ---> ");
    gotoxy(68,14);
    scanf("%d",&sort);
    switch(sort)
    {
    case 1 :
        for(a = 1; a <= input1; a++)
    {
        strcpy(data[a].s_nama,data[a].nama);
        data[a].s_nim=data[a].nim;
        strcpy(data[a].s_progdi,data[a].progdi);
        strcpy(data[a].s_alamat,data[a].alamat);
        strcpy(data[a].s_asal,data[a].asal);
    }
        for(int i=1;i<=input1;i++){
            int j,bd;
            j=i;
            for(int k=i;k<=input1;k++)
            {
                    bd=strcmp(data[j].s_nama,data[k].s_nama);
                    if(bd==1) j=k;
                    }
                                if(j!=i){
                             char temp[5][30];
                             strcpy(temp[0],data[j].s_nama);
                             data[1].tempat=data[j].s_nim;
                             strcpy(temp[2],data[j].s_progdi);
                             strcpy(temp[3],data[j].s_alamat);
                             strcpy(temp[4],data[j].s_asal);
                             strcpy(data[j].s_nama,data[i].s_nama);
                             data[j].s_nim=data[i].s_nim;
                             strcpy(data[j].s_progdi,data[i].s_progdi);
                             strcpy(data[j].s_alamat,data[i].s_alamat);
                             strcpy(data[j].s_asal,data[i].s_asal);
                             strcpy(data[i].s_nama,temp[0]);
                             data[i].s_nim=data[1].tempat;
                             strcpy(data[i].s_progdi,temp[2]);
                             strcpy(data[i].s_alamat,temp[3]);
                             strcpy(data[i].s_asal,temp[4]);}
                    }
        system("color 8E");
    system("cls");
    gotoxy(19,3);
    printf("+");
    gotoxy(111,3);
    printf("+");
    for(a=20;a<=110;a++)
    {
        gotoxy(a,3);
        printf("-");
    }
    gotoxy(57,5);
    printf("DATA MAHASISWA ADMIN");
    gotoxy(47,6);
    printf("===DATA MAHASISWA YANG TELAH DIurutkan===");
    gotoxy(19,8);
    printf("+");
    gotoxy(111,8);
    printf("+");
    for(a=20;a<=110;a++)
    {
        gotoxy(a,8);
        printf("-");
    }
    gotoxy(19,10);
    printf("+");
    gotoxy(111,10);
    printf("+");
    for(a=20;a<=110;a++)
    {
        gotoxy(a,10);
        printf("-");
    }
    gotoxy(20,9);
    printf("NAMA");
    gotoxy(38,9);
    printf("NIM");
    gotoxy(56,9);
    printf("PROGDI");
    gotoxy(74,9);
    printf("ALAMAT");
    gotoxy(92,9);
    printf("ASAL");
    for (c=11;c<11+input1;c++){
        for(d=c-10;d<=c-10;d++){
            gotoxy(20,c);
            printf("%s",data[d].s_nama);
            gotoxy(38,c);
            printf("%d",data[d].s_nim);
            gotoxy(56,c);
            printf("%s",data[d].s_progdi);
            gotoxy(74,c);
            printf("%s",data[d].s_alamat);
            gotoxy(92,c);
            printf("%s",data[d].s_asal);
        }
    }
    gotoxy(19,c+1);
    printf("+");
    gotoxy(111,c+1);
    printf("+");
    for(a=20;a<=110;a++)
    {
        gotoxy(a,c+1);
        printf("-");
    }
    gotoxy(20,c+2);
    system("pause");
    goto awal;
    break;
    case 2 :
        for(a = 1; a <= input1; a++)
    {
        strcpy(data[a].s_nama,data[a].nama);
        data[a].s_nim=data[a].nim;
        strcpy(data[a].s_progdi,data[a].progdi);
        strcpy(data[a].s_alamat,data[a].alamat);
        strcpy(data[a].s_asal,data[a].asal);
    }
        for(int i=1;i<=input1;i++){
            int j,bd;
            j=i;
            for(int k=i;k<=input1;k++)
            {
                    if(data[j].s_nim>data[k].s_nim) j=k;
                    }
                                if(j!=i){
                             char temp[5][30];
                             strcpy(temp[0],data[j].s_nama);
                             data[1].tempat=data[j].s_nim;
                             strcpy(temp[2],data[j].s_progdi);
                             strcpy(temp[3],data[j].s_alamat);
                             strcpy(temp[4],data[j].s_asal);
                             strcpy(data[j].s_nama,data[i].s_nama);
                             data[j].s_nim=data[i].s_nim;
                             strcpy(data[j].s_progdi,data[i].s_progdi);
                             strcpy(data[j].s_alamat,data[i].s_alamat);
                             strcpy(data[j].s_asal,data[i].s_asal);
                             strcpy(data[i].s_nama,temp[0]);
                             data[i].s_nim=data[1].tempat;
                             strcpy(data[i].s_progdi,temp[2]);
                             strcpy(data[i].s_alamat,temp[3]);
                             strcpy(data[i].s_asal,temp[4]);}
                    }
        system("color 8E");
    system("cls");
    gotoxy(19,3);
    printf("+");
    gotoxy(111,3);
    printf("+");
    for(a=20;a<=110;a++)
    {
        gotoxy(a,3);
        printf("-");
    }
    gotoxy(57,5);
    printf("DATA MAHASISWA ADMIN");
    gotoxy(47,6);
    printf("===DATA MAHASISWA YANG TELAH DIurutkan===");
    gotoxy(19,8);
    printf("+");
    gotoxy(111,8);
    printf("+");
    for(a=20;a<=110;a++)
    {
        gotoxy(a,8);
        printf("-");
    }
    gotoxy(19,10);
    printf("+");
    gotoxy(111,10);
    printf("+");
    for(a=20;a<=110;a++)
    {
        gotoxy(a,10);
        printf("-");
    }
    gotoxy(20,9);
    printf("NAMA");
    gotoxy(38,9);
    printf("NIM");
    gotoxy(56,9);
    printf("PROGDI");
    gotoxy(74,9);
    printf("ALAMAT");
    gotoxy(92,9);
    printf("ASAL");
    for (c=11;c<11+input1;c++){
        for(d=c-10;d<=c-10;d++){
            gotoxy(20,c);
            printf("%s",data[d].s_nama);
            gotoxy(38,c);
            printf("%d",data[d].s_nim);
            gotoxy(56,c);
            printf("%s",data[d].s_progdi);
            gotoxy(74,c);
            printf("%s",data[d].s_alamat);
            gotoxy(92,c);
            printf("%s",data[d].s_asal);
        }
    }
    gotoxy(19,c+1);
    printf("+");
    gotoxy(111,c+1);
    printf("+");
    for(a=20;a<=110;a++)
    {
        gotoxy(a,c+1);
        printf("-");
    }
    gotoxy(20,c+2);
    system("pause");
    goto awal;
    break;
    case 3:
        for(a = 1; a <= input1; a++)
    {
        strcpy(data[a].s_nama,data[a].nama);
        data[a].s_nim=data[a].nim;
        strcpy(data[a].s_progdi,data[a].progdi);
        strcpy(data[a].s_alamat,data[a].alamat);
        strcpy(data[a].s_asal,data[a].asal);
    }
        for(int i=1;i<=input1;i++){
            int j,bd;
            j=i;
            for(int k=i;k<=input1;k++)
            {
                    bd=strcmp(data[j].s_progdi,data[k].s_progdi);
                    if(bd==1) j=k;
                    }
                                if(j!=i){
                             char temp[5][30];
                             strcpy(temp[0],data[j].s_nama);
                             data[1].tempat=data[j].s_nim;
                             strcpy(temp[2],data[j].s_progdi);
                             strcpy(temp[3],data[j].s_alamat);
                             strcpy(temp[4],data[j].s_asal);
                             strcpy(data[j].s_nama,data[i].s_nama);
                             data[j].s_nim=data[i].s_nim;
                             strcpy(data[j].s_progdi,data[i].s_progdi);
                             strcpy(data[j].s_alamat,data[i].s_alamat);
                             strcpy(data[j].s_asal,data[i].s_asal);
                             strcpy(data[i].s_nama,temp[0]);
                             data[i].s_nim=data[1].tempat;
                             strcpy(data[i].s_progdi,temp[2]);
                             strcpy(data[i].s_alamat,temp[3]);
                             strcpy(data[i].s_asal,temp[4]);}
                    }
        system("color 8E");
    system("cls");
    gotoxy(19,3);
    printf("+");
    gotoxy(111,3);
    printf("+");
    for(a=20;a<=110;a++)
    {
        gotoxy(a,3);
        printf("-");
    }
    gotoxy(57,5);
    printf("DATA MAHASISWA ADMIN");
    gotoxy(47,6);
    printf("===DATA MAHASISWA YANG TELAH Diurutkan===");
    gotoxy(19,8);
    printf("+");
    gotoxy(111,8);
    printf("+");
    for(a=20;a<=110;a++)
    {
        gotoxy(a,8);
        printf("-");
    }
    gotoxy(19,10);
    printf("+");
    gotoxy(111,10);
    printf("+");
    for(a=20;a<=110;a++)
    {
        gotoxy(a,10);
        printf("-");
    }
    gotoxy(20,9);
    printf("NAMA");
    gotoxy(38,9);
    printf("NIM");
    gotoxy(56,9);
    printf("PROGDI");
    gotoxy(74,9);
    printf("ALAMAT");
    gotoxy(92,9);
    printf("ASAL");
    for (c=11;c<11+input1;c++){
        for(d=c-10;d<=c-10;d++){
            gotoxy(20,c);
            printf("%s",data[d].s_nama);
            gotoxy(38,c);
            printf("%d",data[d].s_nim);
            gotoxy(56,c);
            printf("%s",data[d].s_progdi);
            gotoxy(74,c);
            printf("%s",data[d].s_alamat);
            gotoxy(92,c);
            printf("%s",data[d].s_asal);
        }
    }
    gotoxy(19,c+1);
    printf("+");
    gotoxy(111,c+1);
    printf("+");
    for(a=20;a<=110;a++)
    {
        gotoxy(a,c+1);
        printf("-");
    }
    gotoxy(20,c+2);
    system("pause");
    goto awal;
    break;
    case 4:
        for(a = 1; a <= input1; a++)
    {
        strcpy(data[a].s_nama,data[a].nama);
        data[a].s_nim=data[a].nim;
        strcpy(data[a].s_progdi,data[a].progdi);
        strcpy(data[a].s_alamat,data[a].alamat);
        strcpy(data[a].s_asal,data[a].asal);
    }
        for(int i=1;i<=input1;i++){
            int j,bd;
            j=i;
            for(int k=i;k<=input1;k++)
            {
                    bd=strcmp(data[j].s_alamat,data[k].s_alamat);
                    if(bd==1) j=k;
                    }
                                if(j!=i){
                             char temp[5][30];
                             strcpy(temp[0],data[j].s_nama);
                             data[1].tempat=data[j].s_nim;
                             strcpy(temp[2],data[j].s_progdi);
                             strcpy(temp[3],data[j].s_alamat);
                             strcpy(temp[4],data[j].s_asal);
                             strcpy(data[j].s_nama,data[i].s_nama);
                             data[j].s_nim=data[i].s_nim;
                             strcpy(data[j].s_progdi,data[i].s_progdi);
                             strcpy(data[j].s_alamat,data[i].s_alamat);
                             strcpy(data[j].s_asal,data[i].s_asal);
                             strcpy(data[i].s_nama,temp[0]);
                             data[i].s_nim=data[1].tempat;
                             strcpy(data[i].s_progdi,temp[2]);
                             strcpy(data[i].s_alamat,temp[3]);
                             strcpy(data[i].s_asal,temp[4]);}
                    }
        system("color 0B");
    system("cls");
    gotoxy(19,3);
    printf("+");
    gotoxy(111,3);
    printf("+");
    for(a=20;a<=110;a++)
    {
        gotoxy(a,3);
        printf("-");
    }
    gotoxy(57,5);
    printf("DATA MAHASISWA ADMIN");
    gotoxy(47,6);
    printf("===DATA MAHASISWA YANG TELAH DIurutkan===");
    gotoxy(19,8);
    printf("+");
    gotoxy(111,8);
    printf("+");
    for(a=20;a<=110;a++)
    {
        gotoxy(a,8);
        printf("-");
    }
    gotoxy(19,10);
    printf("+");
    gotoxy(111,10);
    printf("+");
    for(a=20;a<=110;a++)
    {
        gotoxy(a,10);
        printf("-");
    }
    gotoxy(20,9);
    printf("NAMA");
    gotoxy(38,9);
    printf("NIM");
    gotoxy(56,9);
    printf("PROGDI");
    gotoxy(74,9);
    printf("ALAMAT");
    gotoxy(92,9);
    printf("ASAL");
    for (c=11;c<11+input1;c++){
        for(d=c-10;d<=c-10;d++){
            gotoxy(20,c);
            printf("%s",data[d].s_nama);
            gotoxy(38,c);
            printf("%d",data[d].s_nim);
            gotoxy(56,c);
            printf("%s",data[d].s_progdi);
            gotoxy(74,c);
            printf("%s",data[d].s_alamat);
            gotoxy(92,c);
            printf("%s",data[d].s_asal);
        }
    }
    gotoxy(19,c+1);
    printf("+");
    gotoxy(111,c+1);
    printf("+");
    for(a=20;a<=110;a++)
    {
        gotoxy(a,c+1);
        printf("-");
    }
    gotoxy(20,c+2);
    system("pause");
    goto awal;
    break;
    case 5 :
        for(a = 1; a <= input1; a++)
    {
        strcpy(data[a].s_nama,data[a].nama);
        data[a].s_nim=data[a].nim;
        strcpy(data[a].s_progdi,data[a].progdi);
        strcpy(data[a].s_alamat,data[a].alamat);
        strcpy(data[a].s_asal,data[a].asal);
    }
        for(int i=1;i<=input1;i++){
            int j,bd;
            j=i;
            for(int k=i;k<=input1;k++)
            {
                    bd=strcmp(data[j].s_asal,data[k].s_asal);
                    if(bd==1) j=k;
                    }
                                if(j!=i){
                             char temp[5][30];
                             strcpy(temp[0],data[j].s_nama);
                             data[1].tempat=data[j].s_nim;
                             strcpy(temp[2],data[j].s_progdi);
                             strcpy(temp[3],data[j].s_alamat);
                             strcpy(temp[4],data[j].s_asal);
                             strcpy(data[j].s_nama,data[i].s_nama);
                             data[j].s_nim=data[i].s_nim;
                             strcpy(data[j].s_progdi,data[i].s_progdi);
                             strcpy(data[j].s_alamat,data[i].s_alamat);
                             strcpy(data[j].s_asal,data[i].s_asal);
                             strcpy(data[i].s_nama,temp[0]);
                             data[i].s_nim=data[1].tempat;
                             strcpy(data[i].s_progdi,temp[2]);
                             strcpy(data[i].s_alamat,temp[3]);
                             strcpy(data[i].s_asal,temp[4]);}
                    }
        system("color 0B");
    system("cls");
    gotoxy(19,3);
    printf("+");
    gotoxy(111,3);
    printf("+");
    for(a=20;a<=110;a++)
    {
        gotoxy(a,3);
        printf("-");
    }
    gotoxy(57,5);
    printf("DATA MAHASISWA ADMIN");
    gotoxy(47,6);
    printf("===DATA MAHASISWA YANG TELAH DIurutkan===");
    gotoxy(19,8);
    printf("+");
    gotoxy(111,8);
    printf("+");
    for(a=20;a<=110;a++)
    {
        gotoxy(a,8);
        printf("-");
    }
    gotoxy(19,10);
    printf("+");
    gotoxy(111,10);
    printf("+");
    for(a=20;a<=110;a++)
    {
        gotoxy(a,10);
        printf("-");
    }
    gotoxy(20,9);
    printf("NAMA");
    gotoxy(38,9);
    printf("NIM");
    gotoxy(56,9);
    printf("PROGDI");
    gotoxy(74,9);
    printf("ALAMAT");
    gotoxy(92,9);
    printf("ASAL");
    for (c=11;c<11+input1;c++){
        for(d=c-10;d<=c-10;d++){
            gotoxy(20,c);
            printf("%s",data[d].s_nama);
            gotoxy(38,c);
            printf("%d",data[d].s_nim);
            gotoxy(56,c);
            printf("%s",data[d].s_progdi);
            gotoxy(74,c);
            printf("%s",data[d].s_alamat);
            gotoxy(92,c);
            printf("%s",data[d].s_asal);
        }
    }
    gotoxy(19,c+1);
    printf("+");
    gotoxy(111,c+1);
    printf("+");
    for(a=20;a<=110;a++)
    {
        gotoxy(a,c+1);
        printf("-");
    }
    gotoxy(20,c+2);
    system("pause");
    goto awal;
    break;
    }
    }
    case 9:
    system("color 1E");
    system("cls");
    gotoxy(34,8);
    printf("=====================================================");
    for (a=9;a<=13;a++)
    {
        gotoxy(34,a);
        printf("|");
        gotoxy(86,a);
        printf("|");
    }
    gotoxy(52,11);
    printf("TERIMA KASIH !!!");
    gotoxy(34,14);
    printf("=====================================================");
    return(0);
    break;
    }
    }
    else{
        goto awal;
    }
}
