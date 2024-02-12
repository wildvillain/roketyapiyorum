#include <stdio.h>

//alinandeger = bitdegeri*bitbasinadeger;
struct Dac
{
    int aralik[2]; 
    float bitbasinadeger; //5/1023
    float bitdegeri  ; //kaç bit aktif?
    float alinandeger; //bit degeri * bit basina deger
};



struct ivmeolcer
{
    int  aralik[2];
    float  zerog;
    float senseff;
};

struct donuolcer
{
    int  aralik[2];
    float  zerodegree;
    float senseff;
};

struct avniyonik
{
    int aralik[2];
    float sicaklik;
    float guc;
};


float Vout(float bias,float gain,float buyukluk){
    return bias + gain*buyukluk;
}



int main(){
    //alinan bir deger gir.................. noktanın oldugu noktaua
//                                         . 
    struct Dac DAC0510 = {{0,5},5.0/1023.0,1023.0},
               DAC1014 = {{0,10},10.0/16383.0,16383.0};
    
    
    DAC0510.alinandeger = DAC0510.bitbasinadeger*DAC0510.bitdegeri;
    DAC1014.alinandeger = DAC1014.bitbasinadeger*DAC1014.bitdegeri;
    printf("Alinan aktif voltaj degeri %f :\n",DAC1014.alinandeger);




    struct donuolcer G1 = {{-1000,1000} , 4   , 0.0025},
                     G2 = {{-200, 200 } , 5   , 0.0125},
                     G3 = {{-50 , 50}   , 2.5 , 0.05};
    struct ivmeolcer A1 = {{-20,20} , 2.5 , 0.125},
                     A2 = {{-5,5}  , 2.5 , 0.5  },
                     A3 = {{-10,10} , 5   , 0.5  };


    float girdi = 0.25;
    int hangiivme = 0,hangidonu = 0;
    float goruntu;

    printf("Hangi ivme olceri gormek istiyorsaniz bir deger girin: ");
    scanf("%d",&hangiivme);
    printf("Hangi donu olceri gormek istiyorsaniz bir deger girin: ");
    scanf("%d",&hangidonu);

    switch (hangiivme)
    {
    case 1:
        goruntu = Vout(A1.zerog,A1.senseff , girdi);
        printf("%d. Ivme olcer  Gorunen deger : %.2f\n", hangiivme, goruntu);
        printf("%d. Ivme olcer  Aralik : {%d , %d}\n", hangiivme, A1.aralik[0],A1.aralik[1]);
        break;
    case 2:
        goruntu = Vout(A2.zerog,A2.senseff , girdi);
        printf("%d. Ivme olcer  Gorunen deger : %.2f\n",hangiivme, goruntu);
        printf("%d. Ivme olcer  Aralik : {%d , %d}\n",hangiivme, A2.aralik[0],A2.aralik[1]);
        break;
    case 3:
        goruntu = Vout(A3.zerog,A3.senseff , girdi);
        printf("%d. Ivme olcer  Gorunen deger : %.2f\n",hangiivme, goruntu);
        printf("%d. Ivme olcer Aralik : {%d , %d}\n",hangiivme, A3.aralik[0],A3.aralik[1]);
        break;
    default:
        break;
    }
        switch (hangidonu)
    {
    case 1:
        goruntu = Vout(G1.zerodegree,G1.senseff , girdi);
        printf("%d. Donu olcer Gorunen deger : %.2f\n",hangidonu,goruntu);
        printf("%d. Donu olcer Aralik : {%d , %d}\n",hangidonu, G1.aralik[0],G1.aralik[1]);
        break;
    case 2:
        goruntu = Vout(G2.zerodegree,G2.senseff , girdi);
        printf("%d. Donu olcer Gorunen deger : %.2f\n",hangidonu,goruntu);
        printf("%d. Donu olcer Aralik : {%d , %d}\n", hangidonu, G2.aralik[0],G2.aralik[1]);
        break;
    case 3:
        goruntu = Vout(G3.zerodegree,G3.senseff , girdi);
        printf("%d. Donu olcer Gorunen deger : %.2f\n",hangidonu,goruntu);
        printf("%d. Donu olcer Aralik : {%d , %d}\n",hangidonu, G3.aralik[0],G3.aralik[1]);
        break;
    default:
        break;
    }



    

    return 0;
}