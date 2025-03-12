
# **Depuração de Programas C no VSCode**

Este guia ajudará a entender os conceitos básicos de depuração e como aplicá-los na linguagem C utilizando o VSCode.

## **Resumo**

Para utilizar o depurador de forma adequada, é necessário seguir alguns passos iniciais:

1. Criar o arquivo de configuração que **compila o programa** (`task.json`).
2. Criar o arquivo de configuração que **chama o depurador** (`launch.json`).
3. Entender como funciona a dinâmica de **breakpoints e steps**.
4. Executar o depurador na interface do **VSCode** e compreender seu funcionamento.

---

## **Arquivos de Configuração**

No **VSCode**, os arquivos `launch.json` e `task.json` são usados para configurar e automatizar a execução e depuração de programas C.

### **1. Arquivo `launch.json` (Configuração do Depurador)**

O `launch.json` define as configurações de depuração, incluindo o programa a ser executado, argumentos, ambiente e modo de execução. Ele permite configurar **breakpoints**, iniciar a depuração em terminais separados e definir opções específicas para diferentes depuradores (como GDB e LLDB para C/C++).

#### **Parâmetros Importantes do `launch.json`**
- `"program"`: Caminho do executável gerado após a compilação.
- `"args"`: Argumentos passados para o programa durante a execução.
- `"cwd"`: Diretório de trabalho onde a depuração será executada.
- `"externalConsole"`: Define se o programa será executado em um terminal separado (necessário para entrada do usuário via `STDIN`).
- `"MIMode"`: Define qual depurador será utilizado (GDB para Windows/Linux, LLDB para macOS).
- `"preLaunchTask"`: Define a tarefa que será executada antes da depuração, geralmente a compilação do código.

> [!CAUTION]
> Se estiver utilizando **MacOS**, é necessário ajustar o `"MIMode"` para `"lldb"`, pois o macOS usa o depurador LLDB nativamente.

#### Exemplo de configuração:

 * **Mac OS**

    ```json
    {
        "version": "0.2.0",
        "configurations": [
            {
                "name": "PPP: Depurar Programa C (MacOS)",
                "type": "cppdbg",
                "request": "launch",
                "program": "${fileDirname}/${fileBasenameNoExtension}",
                "args": [],
                "stopAtEntry": false,
                "cwd": "${fileDirname}",
                "externalConsole": false,
                "MIMode": "lldb",
                "preLaunchTask": "build c code"
            },
        ]
    }
    ```
 * **WSL (no windows)**

    ```json
    {
        "version": "0.2.0",
        "configurations": [
            {
                "name": "PPP: Depurar Programa C (WSL/Linux)",
                "type": "cppdbg",
                "request": "launch",
                "program": "${fileDirname}/${fileBasenameNoExtension}",
                "args": [],
                "stopAtEntry": false,
                "cwd": "${fileDirname}",
                "externalConsole": false,
                "MIMode": "gdb",
                "preLaunchTask": "build c code"
            }
        ]
    }
    ```
---

### **2. Arquivo `task.json` (Configuração da Compilação)**

O `task.json` configura tarefas automatizadas no VSCode, como a **compilação do código**, execução de scripts e outras ações repetitivas. Ele permite definir comandos personalizados que podem ser integrados ao fluxo de trabalho do desenvolvedor, eliminando a necessidade de compilar manualmente antes de rodar o depurador.



#### **Parâmetros Importantes do `task.json`**
- `"type"`: Define o tipo de tarefa (para C/C++, usa-se `"cppbuild"`).
- `"label"`: Nome da tarefa, usado para ser referenciado no `launch.json`.
- `"command"`: Caminho para o compilador (`gcc`, `clang`, ou `cl.exe` no Windows).
- `"args"`: Argumentos de compilação, como opções de otimização, warnings e geração de informações de depuração (`-g`).
- `"problemMatcher"`: Define padrões para captura de erros e warnings na saída do compilador.
- `"group"`: Indica se a tarefa pertence ao grupo de **build** (compilação automática).


  > [!TIP]
  > O compilador pode variar entre sistemas operacionais:
  > - **Windows**: Use `gcc.exe` (MinGW) ou `cl.exe` (MSVC).
  > - **Linux**: Use `gcc` ou `clang`.
  > - **MacOS**: Prefira `clang`, que é o compilador padrão.


 * **Mac OS**

    ```json
    {
        "tasks": [
            {
                "type": "cppbuild",
                "label": "build c code",
                "command": "/usr/bin/clang",
                "args": [
                    "-fcolor-diagnostics",
                    "-fansi-escape-codes",
                    "-Wall",
                    "-g",
                    "${file}",
                    "-o",
                    "${fileDirname}/${fileBasenameNoExtension}"
                ],
                "options": {
                    "cwd": "${fileDirname}"
                },
                "problemMatcher": [
                    "$gcc"
                ],
                "group": {
                    "kind": "build",
                    "isDefault": true
                },
            },
        ],
        "version": "2.0.0"
    }
    ```

 * **WSL (windows)**

   ```json
    {
        "version": "2.0.0",
        "tasks": [
            {
                "type": "shell",
                "label": "build c code (Linux)",
                "command": "/usr/bin/gcc",
                "args": [
                    "-Wall",
                    "-g",
                    "${file}",
                    "-o",
                    "${fileDirname}/${fileBasenameNoExtension}"
                ],
                "options": {
                    "cwd": "${fileDirname}"
                },
                "group": {
                    "kind": "build",
                    "isDefault": true
                },
                "problemMatcher": [
                    "$gcc"
                ]
            }
        ]
    }```



## **Conceitos Básicos de Depuração**

A **depuração** (*debugging*) é o processo de encontrar e corrigir erros em um programa. No VSCode, a depuração é facilitada pelo uso de **breakpoints** e comandos para navegar no código.

- **Breakpoint (Ponto de Interrupção)**: Um ponto onde a execução do código é pausada para inspecionar variáveis e fluxo de execução.
- **Step Over (Passar por cima - F10)**: Executa a linha atual sem entrar em funções chamadas.
- **Step Into (Entrar - F11)**: Entra na função chamada na linha atual.
- **Step Out (Sair - Shift + F11)**: Sai da função atual e retorna ao contexto anterior.
- **Continue (Continuar - F5)**: Retoma a execução até o próximo breakpoint.

---

## **Configuração do VSCode para Depuração**

Para depurar um programa C no VSCode, siga os passos abaixo:

1. **Criando o Arquivo `launch.json`**
   - No VSCode, vá para o menu **Executar** > **Adicionar Configuração**.
   - Escolha "C++ (GDB/LLDB) (Iniciar)".
   - Edite os parâmetros conforme necessário.

1. **Criando o Arquivo `tasks.json`**
  - No VSCode, vá para o menu **Termina ** > **Configurar Tarefas**
  - Adicine uma tarefa como no exemplo acima 
  - Edite os parâmetros conforme necessário.

   > [!TIP]
   > Adapte os códigos necessários, pois os exemplos são apenas modelos.

## **Executando o Programa em um Terminal Separado**
   - Para permitir a leitura de entrada (`STDIN`), configure `"externalConsole": true` no `launch.json`.

 > [!TIP]
 > Só é necessário ativar o `"externalConsole": true` caso o programa em questão necessite ler informações do usuário diretamente do terminal



## **Leituras e Recursos Complementares**
- [Debugging C Programs with VSCode](https://code.visualstudio.com/docs/cpp/cpp-debug)
- [Documentação oficial para Mac](https://code.visualstudio.com/docs/cpp/config-clang-mac)
- [Documentação oficial para Windows](https://code.visualstudio.com/docs/cpp/config-msvc)


