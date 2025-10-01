/*
        AULA 5
    
    ~~~ CONVENÇÕES, BOAS PRÁTICAS STYLE GUIDES ~~~

    Comentar blocos complexos e raciocínios específicos. O mais sucinto possível enquanto se mantenha a clareza. Evitar comentários óbvios e redundantes.
    Na maioria das vezes um código bem escrito é autoexplicativo.

    Organizar o código de forma que facilite a compreensão, a manutenção e a adição de novas funcionalidades.
    Modularizar, separar o código em partes menores independentes, tem beneficia reutilizar o código, legibilidade, facilita a manutenção e a colaboração.

    Declarar variáveis mais localmente possível, próximo ao seu primeiro uso. Preferível inicializar na declaração. Mantenha variáveis confinadas à estrutura em que são usadas. Ex.: while(char* str!=NULL)...

    ~~~ QUICKSORT ~~~

    Casos base: vazio, 1 elemento, 2 elementos
        Caso 2 elementos: comparar

    esoclher pivo
    percorrer da esquerda pra direita até que v[i]>=pivo
    percirrer da direita pra esquerda até que elemento <= pivo
    troca v[i] com v[j]
    para quando i e j se encontrarem

*/

/*
        AULA 6

    ~~~ HEAPSORT ~~~

    É um algoritmo in-place e não-estável

        ~ Vetores e árvores binárias
    Em uma árvore binária, todos os elementos à esquerda de um são menores que ele, e todos à sua direita são maiores que ele.
    Árvore completa é aquela em que a altura até qualquer subárvore (distância entre raíz e subárvore) é igual a 1.

        ~ Representação no vetor
    Suponha um vetor de 1 a n em que o índice 1 é a raíz.
    O pai de qualquer filho f é f/2.
    O filho esquerdo de um índice p é 2p (se 2p <= n) e o filho direito é 2p+1 (se 2p+1 <= n).

    Exercício:

    bool is_heap(int* arr, int n){
    bool min_max;
    if(arr[0]>arr[1])
        min_max=0; // suponho max heap
    else
        min_max=1; // suponho min heap

    int i=0;
    for(int j=2*i+1; j<n; i++){
        if(min_max && (arr[i]>arr[j-1] || arr[i]>arr[j]))
            return false;
        else if(!min_max && (arr[i]<arr[j-1] || arr[i]<arr[j]))
            return false;
    }

    return true;
}

    último nó com filhos é n/2.
    para cada nó pai, ele é comparado com seus filhos.
        maior=p
        if(maior<filho-esquerda)
            maior=filho-esquerda;
        if(maior<filho-direita)
            maior=filho-direita;
        if(maior!=p)
            swap(p, maior);

        Funcionamento do heapsort
        Transformar o vetor em uma min ou max heap
        troca de lugar a raiz e o último elemento
        reajustar a heap a partir do novo elemento raíz.
*/

/*
        AULA 7 - Algoritmos de ordenação não comparativos

    ~~~ COUNTING SORT (Contagem de tipos) ~~~
    Conta a frequência de cada valor.
    Estável.

    ~~~ RADIXSORT ~~~
    Usa um algoritmo estável (como o counting sort) como subrotina.

*/

/*
        AULA 10 - Hashing
    
    Acesso direto, mas endereçamento indireto.
    Resolve uso de armazenamento ineficiente.

    Etapas:
    computar o valor da função de transformação
    metodos comuns de resolver colisões
    - endereçamento aberto
        sondagem linear
        sondagem quadrática (procura posições com um incremento)
        hash dupla
*/

