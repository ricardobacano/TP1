/* Arquivo MAIN que usa o TAD racionais */

/* coloque seus includes aqui */

#include <stdio.h> 
#include <stdlib.h>
#include "racionais.h"

int main () {

    // inicializado o srand em 0 como foi estabelecido em PDF para testes 
    srand(4);

    int n, max;
    
    do { 
        printf("Digite um valor para 'n' entre 0 e 100:\n");
        scanf("%d", &n);
    } while (n < 0 || n > 100); 

    do { 
        printf("Digite um valor para 'MAX' entre 0 e 30:\n");
        scanf("%d", &max);
    } while (max < 0 || max >= 30);

    for (int i = 1; i <= n; i++) 
    {
        printf("%d: ",i);

        struct racional r1 = sorteia_r(max);
        struct racional r2 = sorteia_r(max);
    
        imprime_r(r1);
        printf(" ");
        imprime_r(r2);
        printf(" ");

        if (!valido_r(r1) || !valido_r(r2)) {

            printf("NUMERO INVALIDO\n");
            return 1;
        }

        /* Variaveias que armazenam o resultado das operções */
        struct racional sum_result = soma_r(r1, r2);
        struct racional sub_result = subtrai_r(r1, r2);
        struct racional multi_result = multiplica_r(r1, r2);
        struct racional div_result =  divide_r(r1, r2); 

        imprime_r(sum_result);
        imprime_r(sub_result);
        imprime_r(multi_result);

        if (!valido_r(div_result)) 
        {
            printf("DIVISAO INVALIDA\n");
            return 1;
        } else {  
        imprime_r(div_result);
        }

        printf("\n");
    }
        return 0;
}
