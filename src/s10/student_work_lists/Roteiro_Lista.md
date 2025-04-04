# Listas Dinâmicas

- Ver a matéria no [slide da aula](https://docs.google.com/presentation/d/e/2PACX-1vTJDxN8YoV8K6OMpp9J_om76Cj01EZkvURC3s-IjB6bfGK8lr6Lu-hS_jzLQtElMrwiHGIyCYA-3FEA/pub?start=false&loop=false&delayms=3000)

* Siga o roteiro abaixo para implementar o lista.c
---

## ✅ 1. Programa de Teste: `testa_lista.c`

Este programa chama as funções do `.h` para guiar o aluno, imprimindo mensagens claras do que está testando e onde pode estar o erro.


Veja o código:

* [`testa_lista.c`](testa_lista.c)

---

## 🛠️ 2. Roteiro de Implementação do `lista.c`

Siga essa ordem:

1. **create**: inicializa a lista com um nó cabeça (sentinela).
2. **empty**: verifica se o primeiro *nó real* da lista (após o sentinela) é `NULL`.
3. **insert**: insere um novo [`person`](lista.h?plain1#L6) no início da lista (ou em ordem alfabética, se quiser evoluir).
4. **print_person**: imprime os dados de uma pessoa.
5. **print**: percorre a lista e usa `print_person`.
6. **search**: percorre a lista para encontrar um nome, retorna o nó atual e o anterior.
7. **delete**: usa `search` para localizar e remover um nó.
8. **clean**: remove todos os nós da lista, mas mantém o sentinela.

---

### 💡 3. Dicas de Implementação

- Comece com uma **lista com sentinela** (um nó vazio no início). Isso facilita inserção e remoção.
- Lembre que todas as funções (exceto `create`) assumem que a lista já foi criada!
- **Use sempre `malloc`** ao inserir e **`free` ao remover**.
- Ao implementar `search`, pense como em uma busca linear: você sempre precisa do "anterior" ao nó que está olhando.
- Faça testes logo após cada função. Use `print()` a todo momento para checar o estado da lista!
- Em `delete`, lembre-se de atualizar o ponteiro `next` do anterior para "pular" o nó deletado.


## 🏛 Comandos Úteis

* Para compilar tudo `make`
* Para testar a lista `make test`
* Para limpar os arquivos `make clean`