#include <stdio.h>

#define COLUNAS  10
#define LINHAS  10

int main(){
    int tabuleiro[10][10];

    int navio1[3] = {3, 3, 3};
    int navio2[3] = {3, 3, 3};
    int navio3[3] = {3, 3, 3};
    int navio4[3] = {3, 3, 3};
    
    int naviolinha1 = 2;
    int naviocoluna1 = 1;

    int naviolinha2 = 5;
    int naviocoluna2 = 7;

    int naviolinha3 = 1;
    int naviocoluna3 = 5;

    int naviolinha4 = 8;
    int naviocoluna4 = 2;
    int i, j;

    for(i = 0;i < COLUNAS; i++){
        for(j = 0; j < LINHAS; j++){
            tabuleiro[i][j] = 0;
        }
    }

    if(naviocoluna1 + 2 < COLUNAS){
        for(i = 0; i < 3; i++){
            tabuleiro[naviolinha1][naviocoluna1 + i] = navio1[i];
        }
}
if(naviolinha2 + 2 < LINHAS){
        for(i = 0; i < 3; i++){
            tabuleiro[naviolinha2 + i][naviocoluna2 ] = navio2[i];
        }
}
if(naviolinha3 + 2 < LINHAS && naviocoluna3 + 2 < COLUNAS){
        for(i = 0; i < 3; i++){
            tabuleiro[naviolinha3 + i][naviocoluna3 + i] = navio3[i];
        }
}
if(naviolinha4 - 2 >= 0 && naviocoluna4 + 2 < COLUNAS){
        for(i = 0; i < 3; i++){
            tabuleiro[naviolinha4 - i][naviocoluna4 + i] = navio4[i];
        }
}

printf("Tabuleiro: \n \n ");
   for(i = 0;i < COLUNAS; i++){
        for(j = 0; j < LINHAS; j++){
             printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }



}