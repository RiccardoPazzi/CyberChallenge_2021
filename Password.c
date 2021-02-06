#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
bool isPermutation(char PassW[10001], char stringa[10001]) 
{
    //Le due stringhe devono avere la stessa lunghezza
   char temp;

   int i, j;
   int n = strlen(PassW);
   int m = strlen(stringa);
   
   if(n != m) return false;


   for (i = 0; i < n-1; i++) {
      for (j = i+1; j < n; j++) {
         if (stringa[i] > stringa[j]) {
            temp = stringa[i];
            stringa[i] = stringa[j];
            stringa[j] = temp;
         }
      }
   }
   
   for (i = 0; i < n-1; i++) {
      for (j = i+1; j < n; j++) {
         if (PassW[i] > PassW[j]) {
            temp = PassW[i];
            PassW[i] = PassW[j];
            PassW[j] = temp;
         }
      }
   }
   
   if(strcmp(PassW, stringa) == 0) return true;
   
   return false;
}

void solve() {
    bool correct = false;
    char P[10001], H[10001];

    scanf("%s", P);
    scanf("%s", H);

    // WRITE YOUR SOLUTION HERE
    //Devo scorrere la stringa di unità uguali alla lunghezza della password e
    //verificare se può essere una permutazione, in caso affermativo
    
    int passLength = strlen(P);
    int hashLength = strlen(H);
    int k;
    char subbuff[passLength+1];
    
    for(int i=0; i<=(hashLength-passLength); i++)
    {
        //k = i+passLength-1;
        memcpy(subbuff, &H[i], passLength);
        subbuff[passLength] = '\0';
        if(isPermutation(subbuff, P))
        {
            correct = true;
            break;
        }
    }
    printf("%s\n", correct ? "1" : "0");
}

int main() {
  int T;
  scanf("%d", &T);

  for(int i=0; i<T; i++) {
    solve();
  }

  return 0;
}

