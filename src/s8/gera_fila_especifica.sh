#!/bin/bash


# Uso
# ./gerar_codigo.sh char* TYPE_IS_STRING

# Nome base do programa (sem extensão)
ARQUIVO_BASE="main"
SAIDA="codigo_gerado.c"

# Tipo que será usado na compilação (ex: int, char*, float, struct etc)
# Exemplo de uso: ./gerar_codigo.sh char* TYPE_IS_STRING
TIPO="$1"
TIPO_FLAG="$2"

if [ -z "$TIPO" ] || [ -z "$TIPO_FLAG" ]; then
    echo "Uso: $0 <TIPO> <TIPO_FLAG>"
    echo "Exemplo: $0 char* TYPE_IS_STRING"
    exit 1
fi

echo "Gerando código com TYPE=$TIPO e $TIPO_FLAG..."

# Executa o pré-processador e gera o código final
gcc -E -DTYPE="$TIPO" -D$TIPO_FLAG $ARQUIVO_BASE.c -o $SAIDA

echo "Código gerado salvo em: $SAIDA"
