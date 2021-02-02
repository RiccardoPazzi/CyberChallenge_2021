/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo 
{
    int n_of_tasks;
    struct nodo* next;
} lista_processi;


int main() {
    int N, K;
    int n_of_Processes = 0;
    lista_processi* cursore_coda = NULL;
    lista_processi* cursore_coda_prev = NULL;
    lista_processi* tmp = NULL;
    lista_processi* processo_coda_struct;
    lista_processi** processo_coda = &processo_coda_struct;
    
    //head = (node_t *) malloc(sizeof(node_t))

    scanf("%d %d\n", &N, &K);

    int *V = (int *)malloc(N * sizeof(int));

    for(int i=0; i<N; i++)
      scanf("%d", &V[i]);

    int solution = 0;

    // WRITE YOUR SOLUTION HERE
    // Devo scorrere la lista V e trovare K processi da aggiungere alla coda
    // Un processo andrà aggiunto alla lista_processi se ha più task del processo_coda
    *processo_coda = (lista_processi *) malloc(sizeof(lista_processi));
    (*processo_coda)->n_of_tasks = V[0];
    (*processo_coda)->next = NULL;
    n_of_Processes++;
    
    for(int i = 1; i<N; i++)
    {
        if(V[i] >= (*processo_coda)->n_of_tasks)
        {
            //Inserisco il processo nella coda dei processi più grandi, scorrendo
            // con un cursore la lista_processi e tenendola ordinata
            cursore_coda = (*processo_coda);
            while(cursore_coda != NULL && V[i] >= cursore_coda->n_of_tasks)
            {
                cursore_coda_prev = cursore_coda;
                cursore_coda = cursore_coda->next;
            }
            
            //Ho trovato la posizione dell'elemento, aggiungo e controllo se la coda è piena
            tmp = (lista_processi *) malloc(sizeof(lista_processi));
            cursore_coda_prev->next = tmp;
            tmp->n_of_tasks = V[i];
            tmp->next = cursore_coda;
            
            if(n_of_Processes == K+1)
            {
                //Elimino il primo elemento della coda
                lista_processi * temp_node = NULL;

                temp_node = (*processo_coda)->next;
                free(*processo_coda);
                (*processo_coda) = temp_node;

            }
            else
            {
                n_of_Processes++;
            }
        }
        
    }
    
    cursore_coda = (*processo_coda);
    for(int i=0; i<K+1;i++)
    {
        solution = solution+cursore_coda->n_of_tasks;
        cursore_coda = cursore_coda->next;
    }

    printf("%d\n", solution);

    return 0;
}
