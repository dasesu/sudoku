#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;


int sudoku[9][9]{};
char mapa[9][9]{};


int verify_number(int j, int i, int number){
// retorna 1 si es una posicion valida para ese numero

   int valid = 1;

   // Verificamos en la fila
   for (int ii = 0; ii < 9; ++ii){
      if( sudoku[j][ii] == number ){
         valid=0;
         //printf("Invalido: %d ya se encuentra  en la misma fila\n", number);
         return valid;
      }
   }

   // Verificamos en la columna
   for (int jj = 0; jj < 9; ++jj){
      if( sudoku[jj][i] == number ){
         valid=0;
         //printf("Invalido: %d ya se encuentra  en la misma columna\n", number);
         return valid;
      }
   }

   // Verificamos en el cuadro 3x3 que contiene las coordenadas
   for (int jj = j/3; jj < 9; ++jj){
      for (int ii = i/3; ii < 9; ++ii){
         if( sudoku[j][ii] == number ){
            valid=0;
            //printf("Invalido: %d ya se encuentra  en el cuadro 3x3\n", number);
            return valid;
         }
      }
   }
   
   return valid;
}

int es_solucion(){
   int valid=1;
   for (int jj = 0; jj < 9; ++jj){
      for (int ii = 0; ii < 9; ++ii){
         if( sudoku[jj][jj] != 0 && verify_number(jj, ii, sudoku[jj][jj] ) != 0 ){
            valid=0;
            return valid;
         }
      }
   }
   return valid;
}


int main(){
   FILE* fp;
   
   int num{};


   fp = fopen("sudoku.txt","r");
   if (fp == NULL) {
      printf("No such file or directory");
      return 1;
   }else{
      
      // load the sudoku problem
      for (int jj = 0; jj < 9; ++jj){
         for (int ii = 0; ii < 9; ++ii){
            fscanf(fp, "%d", &sudoku[jj][ii]);
            if(sudoku[jj][ii] == 0){
               mapa[jj][ii] = '.';
            }else{
               mapa[jj][ii] = '#';
            }
         }
      }
      
      
      printf("Sudoku to solve:\n");
      for (int jj = 0; jj < 9; ++jj){
         for (int ii = 0; ii < 9; ++ii){
            printf("%d", sudoku[jj][ii]);
            if( ii<8 ){
               printf(" ");
            }
         }
         printf("\n");
      }


      printf("\n");
      printf("Current map:\n");
      for (int jj = 0; jj < 9; ++jj){
         for (int ii = 0; ii < 9; ++ii){
            printf("%c", mapa[jj][ii]);
            if( ii<8 ){
               printf(" ");
            }
         }
         printf("\n");
      }

      

   }
   return 0;
}
