# Projeto: Filtros BMP em C

Este projeto em C implementa filtros simples para imagens BMP. A aplicação inclui um conjunto de filtros como escala de cinza, bordas, desfoque e reflexão.

## Pré-requisitos

- Linguagem de Programação C
- Compilador (por exemplo, gcc)
- Imagens BMP para testar os filtros

## Como Compilar

Certifique-se de ter os pré-requisitos instalados. Em seguida, siga estas etapas:

```bash
make filter
```
Isso compilará o projeto e gerará um executável.

##Como Executar

Execute o programa fornecendo os arquivos de entrada e saída:

```bash
./filter -g input.bmp output_grayscale.bmp 
./filter -e input.bmp output_edges.bmp
./filter -b input.bmp output_blur.bmp
./filter -r input.bmp output_reflection.bmp
```
Substitua input.bmp pelo nome do arquivo de entrada e output.bmp pelo nome desejado para o arquivo de saída, adicionando a opção do filtro desejado.

##Filtros Implementados
Escala de Cinza (-g)
O filtro de escala de cinza converte a imagem colorida para tons de cinza, tornando cada pixel uma média ponderada das componentes vermelha, verde e azul.

Bordas (-e)
O filtro de bordas destaca as transições de intensidade na imagem, realçando as bordas.

Desfoque (-b)
O filtro de desfoque suaviza a imagem, substituindo cada pixel pela média ponderada de seus pixels vizinhos.

Reflexão (-r)
O filtro de reflexão inverte a imagem horizontalmente, criando um efeito de espelhamento.

##Estrutura do Projeto
bmp.h: Definições e estruturas relacionadas a BMP.
helpers.c: Funções auxiliares.
helpers.h: Declarações de funções auxiliares.
filter.c: Código-fonte principal.
Makefile: Script de compilação.
