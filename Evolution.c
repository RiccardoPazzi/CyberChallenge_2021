/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, M, K;

    scanf("%d %d %d\n", &N, &M, &K);

    char **G = (char **)malloc(N * sizeof(char *));
    for(int i=0; i<N; i++) {
        G[i] = (char *)malloc(M * sizeof(char));
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++)
            scanf("%c", &G[i][j]);
        scanf("\n");
    }

    // WRITE YOUR SOLUTION HERE

    //Devo scorrere la matrice e creare una copia su cui lavoro ad ogni step
    //Una versione avanzata potrebbe utilizzare metodi predittivi per saltare step
    //Ma sbatti
    //Prima creo una matrice con i numeri, poi sostituisco con i simboli incrociando i
    //dati con la matrice di partenza
    int **population_matrix = (int **)malloc(N * sizeof(int *));
    for(int i=0; i<N; i++) {
        population_matrix[i] = (int *)malloc(M * sizeof(int));
    }
    
    //Ripeto l'algoritmo di aggiornamento K volte, la matrice di popolazione va
    //pulita ad ogni iterazione
    
    for(int p=0; p<K; p++)
    {
        //Scorro G e creo la population_matrix
        for(int i=0; i<N; i++) 
        {
            for(int j=0; j<M; j++)
            {
                //Se la cella non è vuota
               if(G[i][j] == '+' || G[i][j] == '*')
               {
                   //Scorro le celle intorno alla cella i,j
                   for(int delta_row=-1; delta_row<=1; delta_row++)
                   {
                       for(int delta_col=-1; delta_col<=1; delta_col++)
                       {
                           if(i+delta_row >= 0 && i+delta_row < N && j+delta_col >= 0 && j+delta_col < M){
                                if(delta_row != 0 || delta_col != 0)
                                {
                                    population_matrix[i+delta_row][j+delta_col]++;
                                }
                           }
                       }
                      
                   }
               } 
            }
        }
        //Aggiorno G
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<M; j++)
            {
                if(population_matrix[i][j] > 4)
                {
                    if(G[i][j] == '.')
                        G[i][j] = '+';
                    else if(G[i][j] == '+')
                        G[i][j] = '*';
                    else if(G[i][j] == '*')
                        G[i][j] = '+';
                }
                else if(population_matrix[i][j] < 4)
                {
                    if(G[i][j] == '+')
                        G[i][j] = '.';
                    else if(G[i][j] == '*')
                        G[i][j] = '.';
                }
            }
        }
        
        //Svuoto la population_matrix
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++)
                population_matrix[i][j] = 0;
        }
    }
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++)
            printf("%c", G[i][j]);
        printf("\n");
    }

    return 0;
}