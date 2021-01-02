//Leggere dal file stipendi.dat gli stipendi dei lavoratori e aumentarli del 10%

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[10];
    int stipendio;
}Dipendente;

int main(void){
    FILE *fp;
    Dipendente d[10];
    for(int i=0;i<3;i++){
        scanf("%s",d[i].nome);
        scanf("%d",d[i].stipendio);
    }
    fp = fopen("stipendi.dat","wb");
    fwrite(d,sizeof(d),4,fp);
    return 0;
}