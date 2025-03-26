#ifndef NO_H
#define NO_H

/*
Só é preciso utilzar a flag
'-DTYPE=<Tipo de dado>' para compilar, por exemplo:
-DTYPE=int
*/

// Verifica se TYPE foi definido
#ifndef TYPE
#error "Você deve definir o tipo TYPE antes de incluir este arquivo. Ex: #define TYPE int"
#endif

// Estrutura de nó genérica
typedef struct no
{
    TYPE valor;
    struct no *proximo;
} item;

#endif // NO_H
