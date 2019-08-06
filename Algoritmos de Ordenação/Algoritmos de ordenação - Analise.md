# Algoritmos de ordenação - Analise 



Essa documentação dará uma breve análise dos algoritmos de ordenação estudados na disciplina de Algoritmos e estruturas de Dados II, na universidade Estadual do mato grosso do Sul. O trabalho consiste em uma breve explicação dos algoritmos, seguindo de uma análise do tempo de  coletado no laboratório de informática.



##### Introdução

Sabemos que um bom algoritmo de ordenação tem uma complexidade entre `n` e `n*log(n)`, já um algoritmo ingênuo, péssimo, se faz em `n²`.  Documentaresmos aqui uma sucinta analise desses diversos casos, será apresentado a complexidade do algoritmo, o tempo de execução implementado na linguagem `C`.



## BubleSort 

###### Funcionamento:

A ideia é percorrer o vetor diversas vezes, e a cada passagem fazer flutuar para o topo o maior elemento da sequência. Essa movimentação lembra a forma como as bolhas em um tanque de água procuram seu próprio nível, e disso vem o nome do algoritmo.



Um gif com o funciomaneto do algoritmo:

![bubleSort](/home/fernando/CLionProjects/trabalho2/images/bubleSort.gif)  

 

###### Estabilidade:

O BubleSort  é um algoritmo de **ordenação estável**.





###### Complexidade:

$$
\!\!\!\!\!\!Pior \:\: caso:
O(n^2) \\ 
Caso \: médio: O(n^2) \\
Melhor \: caso: O(n^2)
$$





Logo a baixo, temos uma tabela de valores com tempos  execução em `milisegundos`  para entradas de 10 elementos a 1 milhão. Os tempos de execução do  algoritmo bubleSort   foram coletados  em um computador onde os unicos processos eram o do algoritmo  e do sistema operacional para que a analise fosse a mais precisa.



Informações Técnicas da maquina onde o algoritmo foi radado:

```javascript
function setup() {
    const mySetup = {
        processor: {
          product: "Intel(R) Core(TM) i5-4210U CPU"
          size: "2116MHz"
          capacity: "2700MHz"
          width: 64 
        }
        memory: 8,
        HD: "Sata - 500GB",
        SO: "Linux Mint 19 Cinnamon - 64Bits"
    }
}
```



<u>Primeira Execução</u> - Os tempos da tabela se encontram em  Milissegundos:

| Valores | Aleatório(Tempo)         | Decrescente(Tempo)      | Crescente (Tempo)       |
| ------- | ------------------------ | ----------------------- | ----------------------- |
| 10      | 0,004                    | 0,003                   | 0,002                   |
| 100     | 0,182                    | 0,184                   | 0,093                   |
| 1.000   | 14,586                   | 18,876                  | 9,237                   |
| 10.000  | 394,649                  | 392,764                 | 219,612                 |
| 100.000 | 40.914  - ***Segundos*** | 36.327 - ***Segundos*** | 18.950 - ***Segundos*** |
| 500.000 | 17.080 - ***Minutos***   | 15.139 - ***Minutos***  | 7.903 - ***Minutos***   |



<u>Segunda Execução</u> - Os tempos da tabela se encontram em  Milissegundos:

| Valores | Aleatório(Tempo)        | Decrescente(Tempo)      | Crescente (Tempo)       |
| ------- | ----------------------- | ----------------------- | ----------------------- |
| 10      | 0,003                   | 0,004                   | 0,001                   |
| 100     | 0,182                   | 0,182                   | 0,117                   |
| 1.000   | 14,906                  | 17,720                  | 5,076                   |
| 10.000  | 397,340                 | 366,845                 | 222,245                 |
| 100.000 | 40.90  - ***Segundos*** | 36.318 - ***Segundos*** | 18.949 - ***Segundos*** |
| 500.000 | 17.078 - ***Minutos***  | 15.149 - ***Minutos***  | 7.909 - ***Minutos***   |



<u>Terceira Execução</u> - Os tempos da tabela se encontram em  Milissegundos:

| Valores | Aleatório(Tempo)         | Decrescente(Tempo)      | Crescente (Tempo)       |
| ------- | ------------------------ | ----------------------- | ----------------------- |
| 10      | 0,003                    | 0,003                   | 0,001                   |
| 100     | 0,181                    | 0,183                   | 0,093                   |
| 1.000   | 15,001                   | 17,887                  | 9,421                   |
| 10.000  | 393,298                  | 364,374                 | 190,147                 |
| 100.000 | 40.910  - ***Segundos*** | 36.337 - ***Segundos*** | 18,949 - ***Segundos*** |
| 500.000 | 17.065 - ***Minutos***   | 15.141 - ***Minutos***  | 7.925 - ***Minutos***   |



Você também pode vizualizar um gráfico de comparação entre todos os algoritmos de ordenação analisados aqui, na seção - Gráficos.



Agora, vamos analisar o tempo de execução do algoritmo bubleSort com entradas muito maiores, vamos tratar aqui nessa sucitan analise valores na casa dos 1, 10, 100 Milhões de elementos.

Primeiro vamos fazer uma conta simples com base nos dados que já posuimos para aproximarmos o tempo de execução real do algoritmo sendo implementado em alguma linguagem de programação.



Temos que a complexidade do algoritmo em todos os casos é:


$$
Complexidadade:O(n^2)
$$
 Agora, calcularemos quantas operações *(troca)* o mesmo fará com uma entrada de 1.000.000 de elementos no pior caso:




$$
\begin{eqnarray}
500.000^2 \: \: \: \:  =\: \: \: \: \: \:    250000000000 \\
1.000.000^2 \: =\: \: \:\:\:\:\:\:\:\:\:\:  \: \: \: \: \: \:   1e+12 

\end{eqnarray}
$$

$$
\begin{eqnarray}
\\\\\
250000000000 \:----\!> 1693.881\\
1e+12 \:\:\:\:\:\:\:\:\:\:\:\:\:\:----\!>\:\:\:\:\:x\:\:\:\:\:\:\:
\end{eqnarray}
$$


$$
x \approx 6775.524
$$


Após feita uma simulação real em um computador com valores randomicos o tempo marcado foi de: `6665.009` ou  1.85 Horas, muito próximo do esperado, agora veremos uma média para os valores de `10.000.000` e` 100.000.000`



Os procedimentos seguidos para calcular o tempo de execução para as entradas seguinte é o memso usado para a entrada de `1.000.000`





Entrada de 10.000.000 para o BubleSort é  de:
$$
n
= 10.000.000\\
Tempo = 188.209 Horas
$$
Ou Aproximadamente **8** Dias





Entrada de 100.000.000 para o BubleSort é  de:
$$
n
= 100.000.000\\
Tempo = 313 Horas
$$
Ou Aproximadamente **13** Dias





Considerações finais: O bubleSort não é uma das melhores opções para se escolher, independente do caso a complexidade sempre se manterá `O(n²)`. E Como visto a maneira que a quantidade de elementos aumenta, aumenta junto o tempo e processamento do computador.





## BubleSort - Melhorado

Esse algoritmo é o mesmo que o anterior mas com algumas melhorias, ele é menos ingenuo e um pouco mais inteligente, ele consegue perceber quando não há trocas no vetor e assim logo encerrar a sua execução, visto que o mesmo já está ordenado, ele também não percorre o mesmo tamanho de vetor, a cada execução ele altera o `n` variavel em função da ultima troca realizada, aqui o algoritmo para melhor entendimento:



###### Estabilidade:

O BubleSort Melhorado  é um algoritmo de **ordenação estável**.





```c
void enhance_bubbleSort(int32_t *array, int32_t n) {
    int32_t boolean = 1,
        nFlag = n,
        guard = n, 
        j;
    
    while(boolean) {
        j = 0;
        boolean = 0;
    
        while(j < nFlag - 1) {
            if(array[j] > array[j + 1]) {
                Swap(array[j], array[j + 1]);
                boolean = 1;
                guard = j;
            }
            j++;
        }  
        nFlag = guard + 1;
    }
}
```



Você também pode encontra-lo implementado na parte de código. 



<u>Primeira Execução</u> - Os tempos da tabela se encontram em  Milissegundos:

| Valores | Aleatório(Tempo)         | Decrescente(Tempo)      | Crescente (Tempo)          |
| ------- | ------------------------ | ----------------------- | -------------------------- |
| 10      | 0,003                    | 0,002                   | 0,000                      |
| 100     | 0,137                    | 0,160                   | 0,001                      |
| 1.000   | 11,463                   | 14,362                  | 0,013                      |
| 10.000  | 307,479                  | 286,898                 | 0,093                      |
| 100.000 | 31.672  - ***Segundos*** | 28.697 - ***Segundos*** | 0.206 - ***Milisegundos*** |
| 500.000 | 13.292 - ***Minutos***   | 11.957 - ***Minutos***  | 4.037 - ***Milisegundos*** |



<u>Segunda Execução</u> - Os tempos da tabela se encontram em  Milissegundos:

| Valores | Aleatório(Tempo)         | Decrescente(Tempo)      | Crescente (Tempo)          |
| ------- | ------------------------ | ----------------------- | -------------------------- |
| 10      | 0,003                    | 0,002                   | 0,000                      |
| 100     | 0,134                    | 0,143                   | 0,001                      |
| 1.000   | 10,776                   | 14,823                  | 0,012                      |
| 10.000  | 305,760                  | 291,615                 | 0,093                      |
| 100.000 | 31,711  - ***Segundos*** | 28,665 - ***Segundos*** | 0,964 - ***Milisegundos*** |
| 500.000 | 13.280 - ***Minutos***   | 11.955 - ***Minutos***  | 4.703 - ***Milisegundos*** |



<u>Terceira Execução</u> - Os tempos da tabela se encontram em  Milissegundos:

| Valores | Aleatório(Tempo)         | Decrescente(Tempo)      | Crescente (Tempo)          |
| ------- | ------------------------ | ----------------------- | -------------------------- |
| 10      | 0,003                    | 0,002                   | 0,000                      |
| 100     | 0,137                    | 0,143                   | 0,001                      |
| 1.000   | 10,328                   | 16,571                  | 0,010                      |
| 10.000  | 307,196                  | 288,789                 | 0,062                      |
| 100.000 | 31,671  - ***Segundos*** | 28,679 - ***Segundos*** | 1,133 - ***Milisegundos*** |
| 500.000 | 13.271 - ***Minutos***   | 11.959 - ***Minutos***  | 4.846 - ***Milisegundos*** |



Você também pode vizualizar um gráfico de comparação entre todos os algoritmos de ordenação analisados aqui, na seção - Gráficos.



Aproximações de tempo para entradas de `1.000.000`, `10.000.000` e `100.000.000`

| 1.000.0000  | Horas | Dias |
| :---------- | ----- | ---- |
| 10.000.000  | 141   | 7    |
| 100.000.000 | 258   | 15   |



## InsertionSort

**Insertion Sort**, ou *ordenação por inserção*, é o algoritmo de ordenação que, dado uma estrutura (array, lista) constrói uma matriz final com um elemento de cada vez, uma inserção por vez. Assim como algoritmos de ordenação quadrática, é bastante eficiente para problemas com pequenas entradas, sendo o mais eficiente entre os algoritmos desta ordem de classificação.



![insertionSort](/home/fernando/CLionProjects/trabalho2/images/insertionSort.gif)

###### Estabilidade:

O InsertionSort  é um algoritmo de **ordenação estável**.





###### Complexidade:

$$
\!\!\!\!\!\!Pior \:\: caso:
O(n^2) \\ 
Caso \: médio: O(n^2) \\
Melhor \: caso: O(n)
$$







<u>Primeira Execução</u> - Os tempos da tabela se encontram em  Milissegundos:

| Valores | Aleatório(Tempo)        | Decrescente(Tempo)      | Crescente (Tempo)          |
| ------- | ----------------------- | ----------------------- | -------------------------- |
| 10      | 0,001                   | 0,001                   | 0,000                      |
| 100     | 0,037                   | 0,059                   | 0,002                      |
| 1.000   | 2,820                   | 5,703                   | 0,015                      |
| 10.000  | 94,605                  | 143,877                 | 0,031                      |
| 100.000 | 5.613  - ***Segundos*** | 11.169 - ***Segundos*** | 1.515 - ***Milisegundos*** |
| 500.000 | 2.326 - ***Minutos***   | 4.648 - ***Minutos***   | 7.498 - ***Milisegundos*** |



<u>Segunda Execução</u> - Os tempos da tabela se encontram em  Milissegundos:

| Valores | Aleatório(Tempo)        | Decrescente(Tempo)      | Crescente (Tempo)          |
| ------- | ----------------------- | ----------------------- | -------------------------- |
| 10      | 0,000                   | 0,001                   | 0,000                      |
| 100     | 0,016                   | 0,059                   | 0,003                      |
| 1.000   | 2,807                   | 5,508                   | 0,016                      |
| 10.000  | 86,267                  | 116,950                 | 0,036                      |
| 100.000 | 5,626  - ***Segundos*** | 11,161 - ***Segundos*** | 0.505 - ***Milisegundos*** |
| 500.000 | 2.328 - ***Minutos***   | 4.671 - ***Minutos***   | 7.771 - ***Milisegundos*** |



<u>Terceira Execução</u> - Os tempos da tabela se encontram em  Milissegundos:

| Valores | Aleatório(Tempo)        | Decrescente(Tempo)      | Crescente (Tempo)          |
| ------- | ----------------------- | ----------------------- | -------------------------- |
| 10      | 0,001                   | 0,001                   | 0,001                      |
| 100     | 0,037                   | 0,059                   | 0,002                      |
| 1.000   | 2,794                   | 6,818                   | 0,016                      |
| 10.000  | 93,317                  | 137,413                 | 0,148                      |
| 100.000 | 5,621  - ***Segundos*** | 11,162 - ***Segundos*** | 0,394 - ***Milisegundos*** |
| 500.000 | 2.326 - ***Minutos***   | 4.649 - ***Minutos***   | 7,895 - ***Milisegundos*** |



Você também pode vizualizar um gráfico de comparação entre todos os algoritmos de ordenação analisados aqui, na seção - Gráficos. 





Aproximações de tempo para entradas de `1.000.000`, `10.000.000` e `100.000.000`

| 1.000.0000  | Horas | Dias |
| :---------- | ----- | ---- |
| 10.000.000  |       |      |
| 100.000.000 |       |      |





## MergeSort

No MergeSort sua ideia básica consiste em Dividir (o problema em vários subproblemas e resolver esses subproblemas através da recursividade) e Conquistar (após todos os subproblemas terem sido resolvidos ocorre a conquista que é a união das resoluções dos subproblemas).





![mergeSort](/home/fernando/CLionProjects/trabalho2/images/mergeSort.gif)



###### Estabilidade:

O mergeSort  é um algoritmo de **ordenação estável**, e é possível adaptar a estrutura a ser ordenada de forma a tornar a ordenação não estável.





###### Complexidade:

$$
\!\!\!\!\!\!Pior caso \:\: caso:
O(n *logn) \\ 
Caso \: médio: O(n *logn) \\
Melhor \: caso: O(n*logn)
$$



Tabela de valores do tempo de execução:



| Valores | Aleatório(Tempo) | Decrescente(Tempo) | Crescente (Tempo) |
| ------- | ---------------- | ------------------ | ----------------- |
| 10      | 0.000            | 0.000              | 0.000             |
| 100     | 0.000            | 0.000              | 0.000             |
| 1.000   | 0.009            | 0.006              | 0.003             |
| 10.000  | 0.550            | 0.584              | 0.309             |
| 100.000 | 66.662           | 60.254             | 31.024            |
| 500.000 | 1584.879         | 1693.881           | 802.110           |



O Gráfico abaixo faz um comparativo entre os tempos e valores. BubleSort melhorado



![ ](/home/fernando/Downloads/chart.png) 

Como o mergeSort tem complexidade `n log(n)` podemos medir o tempo de execução do algoritmo em um tempo aceitavel, você os encontra na tabela abaixo: 

| 1.000.0000  | Horas | Dias |
| :---------- | ----- | ---- |
| 10.000.000  |       |      |
| 100.000.000 |       |      |





## HeapSort

O heapsort utiliza uma estrutura de dados chamada [heap](https://pt.wikipedia.org/wiki/Heap), para ordenar os elementos à medida que os insere na estrutura. Assim, ao final das inserções, os elementos podem ser sucessivamente removidos da raiz da heap, na ordem desejada, lembrando-se sempre de manter a propriedade de max-heap.

Um heap pode ser representada como uma árvore, observe, somente **represetando** para melhor vizualização.

![heap-avoreve](/home/fernando/CLionProjects/trabalho2/images/heap-avoreve.gif)

Abaixo um gif que demonstra o algoritmo em execução:

![heapSort](/home/fernando/CLionProjects/trabalho2/images/heapSort.gif)





###### Estabilidade:

O heapsort não é um algoritmo de [ordenação estável](https://pt.wikipedia.org/wiki/Ordenação_estável). Porém, é possível adaptar a estrutura a ser ordenada de forma a tornar a ordenação estável.





###### Complexidade:

$$
\!\!\!\!\!\!Pior caso \:\: caso:\: O(n^2) \\ 
Caso \: médio: O(n *logn) \\
Melhor \: caso: O(n*logn)
$$







| Valores | Aleatório(Tempo) | Decrescente(Tempo) | Crescente (Tempo) |
| ------- | ---------------- | ------------------ | ----------------- |
| 10      | 0.000            | 0.000              | 0.000             |
| 100     | 0.000            | 0.000              | 0.000             |
| 1.000   | 0.009            | 0.006              | 0.003             |
| 10.000  | 0.550            | 0.584              | 0.309             |
| 100.000 | 66.662           | 60.254             | 31.024            |
| 500.000 | 1584.879         | 1693.881           | 802.110           |



O Gráfico abaixo faz um comparativo entre os tempos e valores. BubleSort melhorado



![ ](/home/fernando/Downloads/chart.png)



Como o mergeSort tem complexidade `O(n*logn)` podemos medir o tempo de execução do algoritmo em um tempo aceitavel, você os encontra na tabela abaixo: 

| 1.000.0000  | Horas | Dias |
| :---------- | ----- | ---- |
| 10.000.000  |       |      |
| 100.000.000 |       |      |





## QuickSort

Como o mergeSort , o quicksort dividi e conquista, e é um algoritmo recursivo. A maneira que o quicksort usa a divizão e conquista é um pouco diferente de como o mergeSort o faz. Na mesclagem, a etapa de divisão não faz praticamente nada e todo o trabalho real acontece na etapa de combinação. O Quicksort é o oposto: todo o trabalho real acontece na etapa de divisão. 



![quicksort](/home/fernando/CLionProjects/trabalho2/images/quicksort.gif)



O algoritm quicksort é um método de ordenação muito rápido e eficiente, inventado por C.A.R. Hoare em 19601, quando visitou a Universidade de Moscovo como estudante. Naquela época, Hoare trabalhou em um projeto de tradução de máquina  para o National Physical Laboratory. Ele criou o quicksort ao tentar traduzir um dicionário de inglês para russo, ordenando as palavras, tendo como objetivo reduzir o problema original em subproblemas que possam ser resolvidos mais fácil e rápido. Foi publicado em 1962 após uma série de refinamentos.



###### Estabilidade:

O quicksort é um algoritmo de ordenação por comparação não-estável



###### Complexidade:

$$
\!\!\!\!\!\!Pior caso \:\: caso:\: O(n^2) \\ 
Caso \: médio: O(n *logn) \\
Melhor \: caso: O(n*logn)
$$





| Valores | Aleatório(Tempo) | Decrescente(Tempo) | Crescente (Tempo) |
| ------- | ---------------- | ------------------ | ----------------- |
| 10      | 0.000            | 0.000              | 0.000             |
| 100     | 0.000            | 0.000              | 0.000             |
| 1.000   | 0.009            | 0.006              | 0.003             |
| 10.000  | 0.550            | 0.584              | 0.309             |
| 100.000 | 66.662           | 60.254             | 31.024            |
| 500.000 | 1584.879         | 1693.881           | 802.110           |



O Gráfico abaixo faz um comparativo entre os tempos e valores. BubleSort melhorado



![ ](/home/fernando/Downloads/chart.png)



Como o QuickSort tem complexidade de pior caso `O(n²)` orimos aproximas  o tempo de execução do algoritmo, você os encontra na tabela abaixo: 

| 1.000.0000  | Horas | Dias |
| :---------- | ----- | ---- |
| 10.000.000  |       |      |
| 100.000.000 |       |      |



Considerações: Por mais que o o QuickSort possua o pior caso em `n²` ele é o mais utilizado na prática, isso se da pelo fato de  que os casos médios das ordenações ficam em `O(n*logn)`, O quickSort também é um dos algoritmos mais conhecidos no mundo,  e ele é customizado para subrir a necessidade do caso.





Qual algoritmo usar ?

Para entender essa questão, precisamos ter uma idéa geral de como os dados estão distribuidos no veteor, ou seja.

Vamos a um exemplo, se temos um vetor com Milhões de elementos e sabemos que nesse vetor os valores estão distribuidos de forma ordenada, qual seria o melhor algoritmo ?



Exemplo do vetor:  `[ 1, 2, 3, 5, 9, 2, 7, 8, 9, 10, 14, 11, 12, 13... ]`

Os dados estão distrubiodos mais ou menos nessa ordem, alguns elementos estão em desordem.



O algoritmo mais recomendado aqui é o InsertionSort, por quê ?

Pelo fato 







# Gráficos 



Os gráficos abaixo 