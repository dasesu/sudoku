#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;


int sudoku[9][9]{};


bool is_valid(int j, int i, int number){
// retorna 1 si es una posicion valida para ese numero

   // Verificamos en la fila
   for (int ii = 0; ii < 9; ++ii){
      if( sudoku[j][ii] == number ){
         //printf("Invalido: %d ya se encuentra  en la misma fila\n", number);
         return false;
      }
   }

   // Verificamos en la columna
   for (int jj = 0; jj < 9; ++jj){
      if( sudoku[jj][i] == number ){
         //printf("Invalido: %d ya se encuentra  en la misma columna\n", number);
         return false;
      }
   }

   // Verificamos en el cuadro 3x3 que contiene las coordenadas
   int a = j - j%3;
   int b = i - i%3;
   for (int jj = a; jj < a + 3 ; jj++){
      for (int ii = b; ii < b + 3; ii++){
         if( sudoku[jj][ii] == number ){
            //printf("Invalido: %d ya se encuentra  en el cuadro 3x3\n", number);
            return false;
         }
      }
   }
   return true;
}

bool solveSudoku(int jj, int ii){
    if (jj == 9 - 1 && ii == 9){
        return true;
    }
    if (ii == 9) {
        jj++;
        ii = 0;
    }
    // si esta posicion ya esta asignada la salto.
    if (sudoku[jj][ii] > 0){
        return solveSudoku(jj, ii+1);
    } 
    // los valores posibles son:
    // 1, 2, 3, 4, 5, 6, 7, 8, 9
    for (int num = 1; num <= 9; num++){
        if ( is_valid( jj, ii, num) ){
            sudoku[jj][ii] = num;
            if (solveSudoku( jj, ii + 1)){
                return true;
            }
        }
        sudoku[jj][ii] = 0;
    }
    return false;
}


int main(){
   FILE* fp;
   
   fp = fopen("sudoku.txt","r");
   if (fp == NULL) {
      printf("No such file or directory");
      return 1;
   }else{
      
      // load the sudoku problem
      for (int jj = 0; jj < 9; ++jj){
         for (int ii = 0; ii < 9; ++ii){
            fscanf(fp, "%d", &sudoku[jj][ii]);
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

      if( solveSudoku(0,0)  ){
         printf("Solucion: \n");
         for (int jj = 0; jj < 9; ++jj){
            for (int ii = 0; ii < 9; ++ii){
               printf("%d", sudoku[jj][ii]);
               if( ii<8 ){
                  printf(" ");
               }
            }
            printf("\n");
         }
      }
   }
   return 0;
}
