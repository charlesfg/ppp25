#include <stdio.h>
#include "pilha.h"

void testeCriacao()
{
    printf("Teste 1: Criação da pilha...\n");
    pilha_t *p = criaPilha();
    if (p != NULL && pilhaVazia(p))
    {
        printf("-> OK: Pilha criada com sucesso e está vazia.\n\n");
    }
    else
    {
        printf("-> ERRO: Problema na criação ou pilha não está vazia.\n\n");
    }
    destroiPilha(p);
}

void testePushPop()
{
    printf("Teste 2: Inserção (push) e remoção (pop)...\n");
    pilha_t *p = criaPilha();

    // Empilhando alguns valores
    push(p, 10);
    push(p, 20);
    push(p, 30);

    if (!pilhaVazia(p))
    {
        printf("-> OK: Elementos empilhados com sucesso.\n");
    }
    else
    {
        printf("-> ERRO: Pilha ainda está vazia após push.\n");
    }

    // Verificando ordem (LIFO)
    int a = pop(p);
    int b = pop(p);
    int c = pop(p);

    if (a == 30 && b == 20 && c == 10)
    {
        printf("-> OK: Ordem de remoção correta (LIFO).\n\n");
    }
    else
    {
        printf("-> ERRO: Ordem de remoção incorreta. a=%d, b=%d, c=%d\n\n", a, b, c);
    }

    destroiPilha(p);
}

void testePopDePilhaVazia()
{
    printf("Teste 3: pop() em pilha vazia...\n");
    pilha_t *p = criaPilha();
    int valor = pop(p);
    printf("-> Valor retornado: %d (esperado: comportamento definido pelo aluno)\n\n", valor);
    destroiPilha(p);
}

void testeDestruicao()
{
    printf("Teste 4: Destruição da pilha...\n");
    pilha_t *p = criaPilha();
    push(p, 1);
    push(p, 2);
    push(p, 3);
    if (pilhaVazia(p))
    {
        printf("-> ERRO: Inserção não funciona, não há como testar.\n");
    }
    destroiPilha(p);

    if (!pilhaVazia(p))
    {
        printf("-> ERRO: Pilha não foi destruida corretamente.\n");
    }
    else
    {
        printf("-> OK: Pilha destruída (verificar se não houve vazamento de memória com valgrind).\n\n");
    }
}

void testeComMaisElementos()
{
    printf("Teste 5: Pilha com muitos elementos...\n");
    pilha_t *p = criaPilha();
    int i;
    for (i = 0; i < 1000; i++)
    {
        push(p, i);
    }

    int ok = 1;
    for (i = 999; i >= 0; i--)
    {
        if (pop(p) != i)
        {
            ok = 0;
            break;
        }
    }

    if (ok && pilhaVazia(p))
    {
        printf("-> OK: Todos os elementos empilhados e desempilhados corretamente.\n\n");
    }
    else
    {
        printf("-> ERRO: Problema com empilhamento/desempilhamento.\n\n");
    }

    destroiPilha(p);
}

int main()
{
    printf("==== INÍCIO DOS TESTES ====\n\n");

    testeCriacao();
    testePushPop();
    testePopDePilhaVazia();
    testeDestruicao();
    testeComMaisElementos();

    printf("==== FIM DOS TESTES ====\n");

    return 0;
}
