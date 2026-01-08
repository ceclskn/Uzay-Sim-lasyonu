#include <stdio.h>
#include <math.h>

#define PI 3.14

const char *gezegenler[] = {"Merkur","Venus","Dunya","Mars","Jupiter","Saturn","Uranus","Neptun"};

int main(){
    char isim[50];
    int secim = 0;
    double yer_cekimleri[] = {3.70 , 8.87, 9.81, 3.71, 23.12, 8.96, 8.69, 11.00};

    printf(" Adinizi giriniz: ");
    scanf("%s",isim);

    while(1){
        printf("\n%s, lutfen yapmak istediginiz simulasyon deneyini seciniz:\n", isim);
        printf("1. Serbest Dusme\n2. Yukari Atis\n3. Agirlik\n4. Kutlecekimsel Potansiyel Enerji\n5. Hidrostatik Basinc\n6. Arsimet Kaldirma Kuvveti\n7. Basit Sarkac Periyodu\n8. Sabit Ip Gerilmesi\n9. Asansor\n(Cikis icin '-1')");
        printf("Secim: ");
        scanf("%d",&secim);

        if(secim==-1) break;

        switch (secim){
            case 1:{
                double t;
                printf("Sureyi sn cinsinden giriniz: ");
                scanf("%lf",&t);
                t=(t<0) ? -t:t;
                serbest_dusme(yer_cekimleri,&t);
                break;
            }
            case 2:{
                double v0;
                printf(" Kac m/s hizla firlatildigini yaziniz: ");
                scanf("%lf",&v0);
                v0=(v0<0) ? -v0:v0;
                yukari_atis(yer_cekimleri,&v0);
                break;
            }
            case 3:{
                double m;
                printf("Kutleyi kg cinsinden giriniz: ");
                scanf("%lf",&m);
                m=(m<0) ? -m:m;
                agirlik(yer_cekimleri,&m);
                break;
            }
            case 4:{
                double h,m;
                printf("Kutleyi kg cinsinden giriniz: ");
                scanf("%lf",&m);
                m=(m<0) ? -m:m;
                printf("Yuksekligi m cinsinden giriniz: ");
                scanf("%lf",&h);
                h=(h<0) ? -h:h;
                kutlecekimsel_pot_enerji(yer_cekimleri,&m,&h);
                break;
            }
            case 5:{
                double h,rho;
                printf("Sivinin birim hacmindeki kütlesini kg/m3 giriniz: ");
                scanf("%lf",&rho);
                rho=(rho<0) ? -rho:rho;
                printf("Yuksekligi m cinsinden giriniz: ");
                scanf("%lf",&h);
                h=(h<0) ? -h:h;
                hidrostatik_basinc(yer_cekimleri,&rho,&h);
                break;
            }
            case 6:{
                double V,rho;
                printf("Sivinin birim hacmindeki kütlesini kg/m3 giriniz: ");
                scanf("%lf",&rho);
                rho=(rho<0) ? -rho:rho;
                printf("Batan hacmi m3 cinsinden giriniz: ");
                scanf("%lf",&V);
                V=(V<0) ? -V:V;
                kaldirma_kuv(yer_cekimleri,&V, &rho);
                break;
            }
            case 7:{
                double L;
                printf("Sarkacin uzunlugunu m cinsinden giriniz: ");
                scanf("%lf",&L);
                L=(L<0) ? -L:L;
                sarkac_periyodu(yer_cekimleri,&L);
                break;
            }
            case 8:{
                double m;
                printf("Kutleyi kg cinsinden giriniz: ");
                scanf("%lf",&m);
                m=(m<0) ? -m:m;
                ip_gerilmesi(yer_cekimleri,&m);
                break;
            }
            case 9:{
                double a,m;
                printf("Kutleyi kg cinsinden giriniz: ");
                scanf("%lf",&m);
                m=(m<0) ? -m:m;
                printf("Asansorun ivmesi m/s2 cinsinden giriniz: ");
                scanf("%lf",&a);
                a=(a<0) ? -a:a;
                asansor(yer_cekimleri,&m,&a);
                break;
            }
            default:
                printf("Gecersiz secim!!! Lutfen 1-9 arasinda bir deger girin.\n");
        }
    }
    printf("Program sonlandirildi. Iyi calismalar, %s\n",isim);
    return 0; }

    void serbest_dusme(double *yer_cekimi, double *t){
        printf("\n--- SARKAC PERIYODU DENEYI ---\n");
        for(int i=0; i<8; i++){
            double h= (*(yer_cekimi+i)*(*t)*(*t))/2;
            printf("%s gezegeninde kat edilen yol: %f metre\n",*(gezegenler+i),h);
        }
    }
    void yukari_atis(double *yer_cekimi, double *v0){
        printf("\n--- YUKARI ATIS DENEYI ---\n");
        for(int i=0;i<8; i++){
            double h= ((*v0)*(*v0))/(2*(*(yer_cekimi+i)));
            printf("%s gezegeninde cikilabikecek en yuksek yukseklik: %f metre\n",*(gezegenler+i),h);
        }
    }
    void agirlik(double *yer_cekimi, double *m){
        printf("\n--- AGIRLIK DENEYI ---\n");
        for(int i=0; i<8; i++){
            double G= (*m)*(*(yer_cekimi+i));
            printf("%s gezegeninde olan agirligi: %f N\n",*(gezegenler+i),G);
        }
    }
    void kutlecekimsel_pot_enerji(double *yer_cekimi, double *m, double *h){
        printf("\n--- KUTLECEKÝMSEL POTANSÝYEL ENERJÝ DENEYI ---\n");
        for(int i=0; i<8; i++){
            double E= (*m)*(*(yer_cekimi+i))*(*h);
            printf("%s gezegeninde cismin kütleçekimsel potansiyel enerjisi: %f joule\n",*(gezegenler+i),E);
        }
    }
    void hidrostatik_basinc(double *yer_cekimi, double *rho, double *h){
        printf("\n--- HIDROSTATIK BASINC DENEYI ---\n");
        for(int i=0; i<8; i++){
            double P= (*rho)*(*(yer_cekimi+i))*(*h);
            printf("%s gezegeninde sývýnýn yuzeyine uyguladýgý basýncý: %f Pa\n",*(gezegenler+i),P);
        }
    }
    void kaldirma_kuv(double *yer_cekimi, double *V, double *rho){
        printf("\n--- ARSIMET KALDIRMA KUVVETÝ DENEYI ---\n");
        for(int i=0; i<8; i++){
            double F= (*rho)*(*(yer_cekimi+i))*(*V);
            printf("%s gezegeninde kaldirma kuvveti: %f N\n",*(gezegenler+i),F);
        }
    }
    void sarkac_periyodu(double *yer_cekimi, double *L){
        printf("\n--- BASIT SARKAC PERIYODU DENEYI ---\n");
        for(int i=0; i<8; i++){
            double T= 2 * PI * sqrt((*L)/(*(yer_cekimi+i)));
            printf("%s gezegeninde salinim periyodu: %f sn\n",*(gezegenler+i),T);
        }
    }
    void ip_gerilmesi(double *yer_cekimi, double *m){
        printf("\n--- SABIT IP GERILMESI DENEYI ---\n");
        for(int i=0; i<8; i++){
            double T= (*m)*(*(yer_cekimi+i));
            printf("%s gezegeninde ipin gerilme kuvveti: %f N\n",*(gezegenler+i),T);
        }
    }
    void asansor(double *yer_cekimi, double *m, double *a) {
    int yon;
    int hatali_giris = 1;
    while (hatali_giris) {
        printf("\n--- ASANSOR DENEYI ---\n");
        printf("Asansor Durumu:\n1 - Yukari Hizlanma / Asagi Yavaslama\n0 - Asagi Hizlanma / Yukari Yavaslama\nSecim: ");
        scanf("%d", &yon);
        if (yon == 0 || yon == 1) {
            hatali_giris = 0;
        } else {
            printf("\n Hatali tuslama yaptiniz!!! Lutfen 0 veya 1 giriniz.\n");
        }
    }
    printf("\n-------------------------------\n");

    for (int i = 0; i < 8; i++) {
            if (yon == 1) {
            double N = (*m) * ( *(yer_cekimi+i)+ (*a));
            printf("%s gezegeninde Yukari Hizlanma / Asagi Yavaslama durumunda cismin agirligi: %f\n", *(gezegenler + i), N);
        } else {
            double N = (*m) * (*(yer_cekimi+i) - (*a));
            printf("%s gezegeninde Asagi Hizlanma / Yukari Yavaslama durumunda cismin agirligi: %f\n", *(gezegenler + i), N);
        }
    }
}


