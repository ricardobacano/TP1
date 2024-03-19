#include <stdlib.h>
#include <stdio.h>
#include "racionais.h"

/* retorna um numero aleatorio entre min e max, inclusive. */

int aleat (int min, int max) 
{
    /*Ajusta o valor aleatorio dentro do intervalo desejado*/
    int result = max - min;
    return min + rand() % (result + 1); 
}

/* Calcula o mdc pelo metodo de euclides*/
int mdc (int a, int b) 
{
    int resto;

    if (b == 0) {
        return a;
    }

    while (b != 0) 
    {
        resto = a % b;
        a = b;
        b = resto;
    }

    return a;
}

int mmc (int a, int b)
{
    if (a == 0 || b == 0) {
        return 0;
    }

    return (a * b) / mdc(a, b); 
}

struct racional simplifica_r (struct racional r)
{
    if (r.num == 0) {
        r.valido = 1;
        r.den = 1;
        
        return r;
    }

    /* calcula o mdc de ambos os racionais */
    int both_mdc = mdc(r.num, r.den);

    r.num /= both_mdc; 
    r.den /= both_mdc;

    if (r.den < 0) {
        r.num = -r.num;
        r.den = -r.den;
    }

    return r;
}

struct racional cria_r (int numerador, int denominador) 
{

    struct racional r;

    if (denominador != 0){
        r.valido = 1;
    } else {
        r.valido = 0;
    }

    r.num = numerador;
    r.den = denominador;

    return r;
}

struct racional sorteia_r (int n) 
{ 
    /*a funcao aleat define os numeros */
    int numerador = aleat(0, n);
    int denominador = aleat(0, n);

    return simplifica_r(cria_r(numerador, denominador));
}

void imprime_r (struct racional r)
{
    if (!r.valido) {
        printf("INVALIDO ");
        return;
    }
    
     if (r.num == 0) {
        printf("0 ");
        return;
    }

    if (r.den == 1) {
        printf("%d ", r.num);
        return;
    }

    if (r.num == r.den) {
        printf("1 ");
        return;
    }

    if (r.den < 0) {
        r.num = -r.num;
        r.den = -r.den;
    }

     printf("%d/%d ", r.num, r.den);
}

/* Retorna 1 se o racional r eh valido ou 0 caso contrario */ 
int valido_r(struct racional r) 
{
    return r.valido == 1;
}

struct racional soma_r (struct racional r1, struct racional r2) 
{
    /* define um denominador em comum para r1 e r2 */
    int both_den = mmc(r1.den, r2.den); 
    int numerador = r1.num * (both_den / r1.den) + r2.num * (both_den / r2.den);

    return simplifica_r((cria_r(numerador, both_den)));
}

struct racional subtrai_r (struct racional r1, struct racional r2)
{
    /* define um denominador em comum para r1 e r2 */
    int both_den = mmc(r1.den, r2.den); 
    int numerador = r1.num * (both_den / r1.den) - r2.num * (both_den / r2.den);

    return simplifica_r((cria_r(numerador, both_den)));
}

struct racional multiplica_r (struct racional r1, struct racional r2)
{
    int numerador = (r1.num * r2.num);
    int denominador = (r1.den * r2.den);

    return simplifica_r((cria_r(numerador, denominador)));  
}

struct racional divide_r (struct racional r1, struct racional r2) 
{
    if (r2.num == 0 || r2.den == 0) {
        /* verifica se o numerador ou o denominador eh 0 */ 
        /* se for 0, indica que a divisao nao funciona pois nao pode div por 0*/

        struct racional r; /* se for divisao por 0, todos os elementos sao zerados*/
        r.valido = 0;
        r.den = 0;
        r.num = 0;
        return r;
    }

    int numerador = r1.num * r2.den; 
    int denominador = r2.num * r1.den;

    return simplifica_r((cria_r(numerador, denominador)));
}


