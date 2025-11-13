#include <stdio.h>

#define COLUNAS 10
#define LINHAS 10
#define TAMANHO 5

int main(){
    int tabuleiro[LINHAS][COLUNAS];
    
    int cone[TAMANHO][TAMANHO];
    int cruz[TAMANHO][TAMANHO];
    int octaedro[TAMANHO][TAMANHO];
    
    // Definição dos 4 navios
    int navio1[3] = {3, 3, 3};
    int navio2[3] = {3, 3, 3};
    int navio3[3] = {3, 3, 3};
    int navio4[3] = {3, 3, 3};
    
    // coordenadas dos navios
    int naviolinha1 = 2;
    int naviocoluna1 = 1;
    int naviolinha2 = 5;
    int naviocoluna2 = 7;
    int naviolinha3 = 1;
    int naviocoluna3 = 5;
    int naviolinha4 = 8;
    int naviocoluna4 = 2;
    
    // origem habilidade
    int habilidadelinha = 5;
    int habilidadecoluna = 3;
    
    int i, j;
    
    // tabuleiro = 00
    for(i = 0; i < LINHAS; i++){
        for(j = 0; j < COLUNAS; j++){
            tabuleiro[i][j] = 0;
        }
    }
    
//navio 1
    if(naviocoluna1 + 2 < COLUNAS){
        for(i = 0; i < 3; i++){
            tabuleiro[naviolinha1][naviocoluna1 + i] = navio1[i];
        }
    }
    
    // naavio 2
    if(naviolinha2 + 2 < LINHAS){
        for(i = 0; i < 3; i++){
            tabuleiro[naviolinha2 + i][naviocoluna2] = navio2[i];
        }
    }
    
    // navio 3 descendo
    if(naviolinha3 + 2 < LINHAS && naviocoluna3 + 2 < COLUNAS){
        for(i = 0; i < 3; i++){
            tabuleiro[naviolinha3 + i][naviocoluna3 + i] = navio3[i];
        }
    }
    
    // Navio 4 subindo
    if(naviolinha4 - 2 >= 0 && naviocoluna4 + 2 < COLUNAS){
        for(i = 0; i < 3; i++){
            tabuleiro[naviolinha4 - i][naviocoluna4 + i] = navio4[i];
        }
    }
    
    //cone expamndindo pra baixo
    for(i = 0; i < TAMANHO; i++){
        for(j = 0; j < TAMANHO; j++){
            if(j >= (2 - i) && j <= (2 + i) && i <= 2){
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
        }
    }
   //cruz
    for(i = 0; i < TAMANHO; i++){
        for(j = 0; j < TAMANHO; j++){
            
            if(i == 2 || j == 2){
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }
        }
    }
    
    //octaedro 
    for(i = 0; i < TAMANHO; i++){
        for(j = 0; j < TAMANHO; j++){
            int distancia = (i - 2 < 0 ? -(i - 2) : (i - 2)) + 
                           (j - 2 < 0 ? -(j - 2) : (j - 2));
            if(distancia <= 2){
                octaedro[i][j] = 1;
            } else {
                octaedro[i][j] = 0;
            }
        }
    }
    // exibicão da habilidade , com possibilidade de alterar
    
    int offset = TAMANHO / 2; 
    
    for(i = 0; i < TAMANHO; i++){
        for(j = 0; j < TAMANHO; j++){
            // calcula a posição no tabuleiro
            int tab_linha = habilidadelinha - offset + i;
            int tab_coluna = habilidadecoluna - offset + j;
            
            // verifica se está dentro dos limites do tabuleiro
            if(tab_linha >= 0 && tab_linha < LINHAS && 
               tab_coluna >= 0 && tab_coluna < COLUNAS){
                // se a posição da habilidade está ativa (valor 1)
                if(cone[i][j] == 1){
                    // marca com 5 (área de efeito) se não for navio
                    if(tabuleiro[tab_linha][tab_coluna] != 3){
                        tabuleiro[tab_linha][tab_coluna] = 5;
                    }
                }
            }
        }
    }
    
    // exibir o tabuleiro
    printf("Tabuleiro com Habilidade Especial:\n\n");
    
    for(i = 0; i < LINHAS; i++){
        for(j = 0; j < COLUNAS; j++){
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    
    printf("\nLegenda:\n");
    printf("0 = Agua\n");
    printf("3 = Navio\n");
    printf("5 = Area de efeito da habilidade\n");
    
    return 0;
}