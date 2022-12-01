/****************************************************************************
**					SAKARYA ÜNİVERSİTESİ
**			BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				  BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				   PROGRAMLAMAYA GİRİŞİ DERSİ
**
**				ÖDEV NUMARASI=1
**				ÖĞRENCİ ADI-SOYADI :Deniz UMUR
**				ÖĞRENCİ NUMARASI.: B221210038
**				DERS GRUBU…………: 1-A
****************************************************************************/

#include <iomanip>
#include <stdlib.h>
#include <iostream>
#include<time.h>
#include<locale.h>
using namespace std;

struct dogumtarihi {//dogum tarihi struct
    int gun, ay, yil;
};
struct ogrenci {// öğrenci struct
    string adi, soyadi, harfnotu;
    int noot, kısasınav1, kısasınav2, ödev1, ödev2, proje, vize, final, yılicinotu;
    dogumtarihi dogumtarihi;
};

dogumtarihi sinifdg[100];
ogrenci sinif[100];
int kontrol(string ne, int min, int max);
void standartsapma(ogrenci sinif[], int size);
void aralıgınustundekinotlar(ogrenci sinif[], int size);
void aralıgınaltındakinotlar(ogrenci sinif[], int size);
void aralıktakinotlar(ogrenci sinif[], int size);
void enbuyukbulma(ogrenci sinif[], int size);
void enkucukbulma(ogrenci sinif[], int size);
void ortalama(ogrenci sinif[], int size);
string notcevirici(int x);
void ekranaliste(ogrenci sinif[], int size);


int main()
{

    srand(time(NULL));
    ogrenci sinif[100];

    int ekransil, menusecim, devam, ilkaralık, ikinciaralık;
    int e = 0;
    int toplam = 0;
    int r = 0;
    int t = 0;
    int y = 0;
    setlocale(LC_ALL, "Turkish");
    string adlar[30] = { "Ali","Serhat","Mehmet","Enes","Cihan","Melih","Arda","Yusuf","Berk","Alperen","Umut","İbrahim","Talha","Osman Eren","Eren","Furkan","Ekin","Süleyman","Samet","Emir","Eda","Gökce","Sıla","Miray","Pınar","Derya","Ekin","Beyza","Merve","Melisa" };
    string soyadlar[30] = { "Calık","Altınok", "Öztürk","Gül","Kan","Han","Diri","Öz","Az","Yaz","Yaş","Kaş","Parlak","Yaman","Kaya","Yahsi","Ulu","Sele","Sal","Karslı","Çakmak","Demir" ,"Erbay","Yener","Karan","Tezcan","Karaeski","Bayraktar","Cakır","Zengin" };
    struct ogrenci {// öğrenci struct
        string adi, soyadi, harfnotu;
        int noot, kısasınav1, kısasınav2, ödev1, ödev2, proje, vize, final;
    };

    int yontemsecimi;
    do {
        cout << "Eleman belirleme yöntemini seçiniz  Random=1 Manuel(elle giriş)=2 " << endl;
        cin >> yontemsecimi;
        switch (yontemsecimi) {// kullanıcı istemeden sistemden çıkamasın diye kontrol sistemi
        case 1:
            //random isim soyisim not olusturma
            for (int i = 0; i < 100; i++) {
                int  randomad = rand() % 30;
                int   randomsoyad = rand() % 30;
                sinif[i].dogumtarihi.gun = rand() % 30 + 1;
                sinif[i].dogumtarihi.ay = rand() % 12 + 1;
                sinif[i].dogumtarihi.yil = rand() % 4 + 2001;
                sinif[i].adi = adlar[randomad];
                sinif[i].soyadi = soyadlar[randomsoyad];

                for (int i = 0; i < 10; i++) {//random not
                    sinif[i].noot = rand() % 40;
                };
                for (int i = 10; i < 60; i++) {
                    sinif[i].noot = 40 + rand() % 30;
                };
                for (int i = 60; i < 75; i++) {
                    sinif[i].noot = 70 + rand() % 10;
                };
                for (int i = 75; i < 100; i++) {
                    sinif[i].noot = 100 - rand() % 19;
                };



            };
            for (int i = 0; i < 100; i++) {
                int x = sinif[i].noot;
                sinif[i].harfnotu = notcevirici(x);
            }



            break;
        case 2:
            //dışarıdan manuel isim soyisim not girme 
            for (int i = 0; i < 100; i++) {
                cout << i + 1 << ". ögrencinin ismini gir" << endl; cin >> sinif[i].adi;
                cout << i + 1 << ". ögrencinin soyismini gir" << endl; cin >> sinif[i].soyadi;

                sinif[i].kısasınav1 = kontrol("1. kısa sınav", 0, 100);
                sinif[i].kısasınav2 = kontrol("2. kısa sınav", 0, 100);
                sinif[i].ödev1 = kontrol("1. ödev", 0, 100);
                sinif[i].ödev2 = kontrol("2. ödev", 0, 100);
                sinif[i].proje = kontrol("proje", 0, 100);
                sinif[i].vize = kontrol("vize", 0, 100);
                sinif[i].final = kontrol("final ", 0, 100);
                sinifdg[i].gun = kontrol("dogun günü", 0, 30);
                sinifdg[i].ay = kontrol("dogun ayı", 0, 12);
                sinifdg[i].yil = kontrol("dogun yılı", 1998, 2004);



                sinif[i].yılicinotu = ((sinif[i].vize * 50 / 100) + ((sinif[i].kısasınav1 + sinif[i].kısasınav2) * 7 / 100) + ((sinif[i].ödev1 + sinif[i].ödev2) * 10 / 100) + (sinif[i].proje * 16 / 100));
                sinif[i].noot = ((sinif[i].yılicinotu * 45 / 100) + (sinif[i].final * 55 / 100));

                int x = sinif[i].noot;
                sinif[i].harfnotu = notcevirici(x);

            }
            break;
        default:
            cout << "yanlis secim yaptiniz" << endl;
            break;

        }
    } while (yontemsecimi != 1 and yontemsecimi != 2);


    do {

        //menü
        do {
            cout << endl << endl << endl << "\t\t***MENÜ***\n 1-sınıf listesi yazdırma\n 2-Sınıfın en yüksek notunu sorgulama\n 3-Sınıfın en düşük notunu sorgulama\n 4-Sınıfın ortalamasını hesaplama\n 5-Sınıfın standart sapmasını hesaplama\n 6-Başarı notu belirli bir aralıkta olanları listeleme\n 7-Başarı notu belirtilen bir değerin altında olan öğrencileri listeleme\n 8-Başarı notu belirtilen bir değerin üstünde olan öğrencileri listeleme" << endl;
            cin >> menusecim;

            switch (menusecim)
            {//MENÜ

            case 1: //liste yazdırma

                ekranaliste(sinif, 100);
                break;
            case 2:
                //sınıfın en yüksek notunu yazdırma

                enbuyukbulma(sinif, 100);


                break;
            case 3:
                //sınıfın en düşük notunu yazdırma
                int enkucukkim;

                enkucukbulma(sinif, 100);
                break;
            case 4:
                //sınıfın ortalamasını bulma

                ortalama(sinif, 100);


                break;
            case 5:
                //standart sapma
                standartsapma(sinif, 100);

                break;
            case 6:
                //belli bir aralıkta olan notları bulma 
                aralıktakinotlar(sinif, 100);
                break;
            case 7:
                //girilen değerin altındaki notlar

                aralıgınaltındakinotlar(sinif, 100);


                system("pause");
                break;
            case 8:
                //girilen değerin üstündeki notlar

                aralıgınustundekinotlar(sinif, 100);


                system("pause");
                break;

            default:
            {
                cout << "yanlıs secim yaptınız" << endl;

                break;
            };
            };

            cout << "devam etmek icin 1 e basnız" << endl;
            cin >> devam;

            system("CLS");

        } while (menusecim <= 8 and menusecim >= 1);



    } while (devam == 1);


    system("pause");

}
int kontrol(string ne, int min, int max) { //sayının  kontrol fonksiyonu
    int n;
    do {
        cout << ne << " için " << min << " ile " << max << " arasında bir değer giriniz" << endl;
        cin >> n;
        if (!(n >= min and n <= max)) {
            cout << "DEGER İSTENEN ARAKIKTA DEGIL" << endl;

        };
    } while (!(n >= min and n <= max));



    return n;
}
void standartsapma(ogrenci sinif[], int size) {//standart sapma hesaplama
    static int toplam = 0;
    float varyans = 0;


    float standartsapma;
    for (int i = 0; i < size; i++) {
        toplam = toplam + sinif[i].noot;
    }
    float ort = toplam / 100;
    for (int i = 0; i < size; i++) {
        varyans = varyans + (pow((ort - sinif[i].noot), 2));
    }
    varyans = varyans / 99;
    standartsapma = pow(varyans, 1 / 2);
    cout << "standart sapma= " << standartsapma << endl;


}


void ekranaliste(ogrenci sinif[], int size) {//ekrana sınıf listesi yazdırma{
    for (int i = 0; i < 100; i++) {
        int x = sinif[i].noot;
        sinif[i].harfnotu = notcevirici(x);
        cout << "\n###################################################################################################" << endl;
        cout << i+1<<".Ögrencinin adi soyadi sayisal notu/ harf notu -- doğum tarihi = " <<setw(1)<< sinif[i].adi << " " <<setw(1)<< sinif[i].soyadi << " " <<setw(1)<< sinif[i].noot << " / " <<setw(1)<<sinif[i].harfnotu << "--" <<setw(1)<< sinif[i].dogumtarihi.gun << "/" << sinif[i].dogumtarihi.ay << "/" << sinif[i].dogumtarihi.yil;
        if ((i + 1) % 20 == 0) {
            cout << "\n\t**Devam etmek icin herhangi bir tusa basnız**" << endl;
            system("pause");

            system("CLS");

        };
    }
}
void ortalama(ogrenci sinif[], int size) {//ortalama hesaplama
    int static toplam = 0;
    for (int j = 0; j < size; j++) {
        toplam = toplam + sinif[j].noot;
    }
    cout << "ortalama= " << toplam / 100 << endl;
    toplam = 0;
};
void enbuyukbulma(ogrenci sinif[], int size) {//en yüksek notu hesaplama
    string enyuksekalanad, enyuksekalansoyad;
    int static enbuyuk = 0;

    for (int i = 0; i < 100; i++) {
        if (sinif[i].noot > enbuyuk) {
            enbuyuk = sinif[i].noot;
            enyuksekalanad = sinif[i].adi;
            enyuksekalansoyad = sinif[i].soyadi;
        }
    }
    cout << "En yüksek notu alan/ not=  " << enyuksekalanad << " " << enyuksekalansoyad << " " << enbuyuk << endl;
};
void enkucukbulma(ogrenci sinif[], int size) {//en düşük nptu hesaplama 
    string endusukalanad, endusukalansoyad;
    int static enkucuk = 100;
    for (int i = 0; i < 100; i++) {
        if (sinif[i].noot < enkucuk) {
            enkucuk = sinif[i].noot;
            endusukalanad = sinif[i].adi;
            endusukalansoyad = sinif[i].soyadi;
        }
    };
    cout << "En düşük notu alan/ not=  " << endusukalanad << " " << endusukalansoyad << " " << enkucuk << endl;
};
void aralıgınustundekinotlar(ogrenci sinif[], int size)
{//girilen sayıdan buyuk notları yazdırma
    cout << "Girdiğiniz değerin üstündeki sayılar yazdırılacaktır.(Girdiğiniz sayı dahil edilecektir) " << endl;

    int buyukolduguaralık;
    buyukolduguaralık = kontrol("Alt sınır", 0, 100);
    for (int i = 0; i < size; i++) {
        if (sinif[i].noot >= buyukolduguaralık) {
            cout << sinif[i].adi << " " << sinif[i].soyadi << " " << sinif[i].noot << endl;
        }
    }
};
void aralıgınaltındakinotlar(ogrenci sinif[], int size)//girilen sayıdan küçük olan notları yazdırma
{
    cout << "Girdiğiniz değerin altındaki sayılar yazdırılacaktır.(Girdiğiniz sayı dahil edilecektir) " << endl;

    int kucukolduguaralık;
    kucukolduguaralık = kontrol("Üst sınır", 0, 100);
    for (int i = 0; i < size; i++)
    {
        if (sinif[i].noot <= kucukolduguaralık)
        {
            cout << sinif[i].adi << " " << sinif[i].soyadi << " " << sinif[i].noot << endl;
        }
    }
};
void aralıktakinotlar(ogrenci sinif[], int size) {//belli aralıktaki notları yazdırma
    int ilkaralık, ikinciaralık;
    ilkaralık = kontrol("ilk aralık", 0, 100);
    ikinciaralık = kontrol("ikinci aralık", 0, 100);

    while (ilkaralık > ikinciaralık) {
        cout << "girdiğiniz ilk sayi ikinciden büyük veya esit olamaz" << endl;
        ilkaralık = kontrol("ilk aralık", 0, 100);
        ikinciaralık = kontrol("ikinci aralık", 0, 100);
    }

    for (int i = 0; i < size; i++)
    {
        if (sinif[i].noot >= ilkaralık and sinif[i].noot <= ikinciaralık) { // notu belli aralıkta olan öğrencilerin adını yazdırma 
            cout << sinif[i].adi << " " << sinif[i].soyadi << " " << sinif[i].noot << endl;
        }
    }

}
string notcevirici(int x) { //notu harf notuna çeviren fonksiyon
    string harfnotu;
    for (int i = 0; i < 100; i++) {
        if (x <= 38) {
            harfnotu = "FF";
        }
        else if (x>= 39 and x <= 45) {
          harfnotu = "FD";
        }
        else if (x >= 46 and x <= 52) {
         harfnotu = "DD";
        }
        else if (x >= 53 and x <= 59) {
          harfnotu = "DC";
        }
        else if (x >= 60 and x<= 66) {
            harfnotu = "CC";
        }
        else if (x >= 67 and x <= 73) {
            harfnotu = "CB";
        }
        else if (x >= 74 and x <= 80) {
           harfnotu = "BB";
        }
        else if (x >= 81 and x<= 87) {
            harfnotu = "BA";
        }
        else if (x >= 88 and x <= 100) {
            harfnotu = "AA";
        }

      return harfnotu;
    }
}
