

# Se estiver curioso veja as variavies aqui:
# https://web.archive.org/web/20230325102835/http://wiki.bash-hackers.org/scripting/posparams


function compila {
    set -x
    echo "Compilando o programa '${@: -1}'"
    gcc -Wall -Werror -g -O0 "$@"
    set +x
}


if ! -e ../utils.o ; then
    echo "Utils not available!"
    cd ..
    compila -c utils.c
    cd -
fi

compila "-DTYPE=char *" -DTYPE_IS_STRING 1112.c fila_generica.c -o 1112

compila "-DTYPE=int" -DTYPE_IS_INT 1121.c -I../ ../utils.o fila_generica.c -o 1121