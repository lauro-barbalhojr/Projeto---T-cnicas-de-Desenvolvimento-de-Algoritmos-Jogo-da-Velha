#include <stdio.h>
#include <stdlib.h>


void tabuleiro(char posicoes2[3][3]){
    system("cls");
    puts("JOGO DA VELHA EM C\n\n");
    printf("\t %c | %c | %c \n", posicoes2[0][0],posicoes2[0][1],posicoes2[0][2]);
    printf("\t-----------\n");
    printf("\t %c | %c | %c \n", posicoes2[1][0],posicoes2[1][1],posicoes2[1][2]);
    printf("\t-----------\n");
    printf("\t %c | %c | %c \n", posicoes2[2][0],posicoes2[2][1],posicoes2[2][2]);
}

int main(){
    char posicoes[3][3] = { {'1','2','3'},
                            {'4','5','6'},
                            {'7','8','9'},
                            };
tabuleiro(posicoes);
char resposta;
int numjogadas,linha,coluna,turno=0,i,j;
do{
   numjogadas=1;
   for(i=0;i<=2;i++){
    for(j=0;j<=2;j++){
        posicoes[i][j]=' ';
    }
   }
   do{
      tabuleiro(posicoes);
      if(turno%2==0){
        printf("Jogador X\n");
      }else{
        printf("Jogador O\n");
      }
      printf("Insira a linha da jogada: ");
      scanf("%d",&linha);
      printf("Insira a coluna da jogada: ");
      scanf("%d",&coluna);
      if(linha<1 || coluna<1 || linha>3 || coluna>3 ){
        linha=0;
        coluna=0;
      }else if(posicoes[linha-1][coluna-1] != ' '){
        linha=0;
        coluna=0;
      }else{
        if(turno%2==0){
            posicoes[linha-1][coluna-1]='X';
        }else{
            posicoes[linha-1][coluna-1]='O';
        }
        turno++;
        numjogadas++;
      }
      if(posicoes[0][0]=='X' && posicoes[0][1]=='X' && posicoes[0][2]=='X'){numjogadas=11;}
      if(posicoes[1][0]=='X' && posicoes[1][1]=='X' && posicoes[1][2]=='X'){numjogadas=11;}
      if(posicoes[2][0]=='X' && posicoes[2][1]=='X' && posicoes[2][2]=='X'){numjogadas=11;}
      if(posicoes[0][0]=='X' && posicoes[1][1]=='X' && posicoes[2][2]=='X'){numjogadas=11;}
      if(posicoes[2][0]=='X' && posicoes[1][1]=='X' && posicoes[2][0]=='X'){numjogadas=11;}

      if(posicoes[0][0]=='O' && posicoes[0][1]=='O' && posicoes[0][2]=='O'){numjogadas=12;}
      if(posicoes[1][0]=='O' && posicoes[1][1]=='O' && posicoes[1][2]=='O'){numjogadas=12;}
      if(posicoes[2][0]=='O' && posicoes[2][1]=='O' && posicoes[2][2]=='O'){numjogadas=12;}
      if(posicoes[0][0]=='O' && posicoes[1][1]=='O' && posicoes[2][2]=='O'){numjogadas=12;}
      if(posicoes[2][0]=='O' && posicoes[1][1]=='O' && posicoes[2][0]=='O'){numjogadas=12;}

   }while(numjogadas<=9);
   tabuleiro(posicoes);
   if(numjogadas==10){
    printf("Deu Velha!\n ");
   }
   if(numjogadas==11){
    printf("Jogador X venceu!\n ");
   }
   if(numjogadas==12){
    printf("Jogador O venceu!\n ");
   }
   printf("Jogar novamente? (S/N)\n");
   scanf("%s",&resposta);
}while(resposta=='s');
}
