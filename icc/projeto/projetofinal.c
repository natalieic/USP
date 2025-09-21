/*
O seguinte programa realiza, de maneira simplificada, as reservas de passagens e eventuais mudanças 
de uma única aeronave em apenas um trecho.  
Depois da abertura do voo é possível realizar, modificar, cancelar e consultar as reservas. 
O fechamento do dia fecha as atividades do dia, mas o programa pode ser modificado em uma chamada conseguinte.
O fechamento do voo não permite mais nenhuma outra mudança, sendo apenas possível cosultar as reservas.

Autoria:
*/

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

typedef struct passageiro{
    char Nome[20], Sobrenome[30], CPF[15], Assento[15], Classe[10];
    float Valor;
    short int Status; //Ativo(0) - Cancelado(1)
}Passageiro;

typedef struct voo{
    short int Status; //Aberto(0) - Fechado(1) 
    int QtdAssentos;
    float ValorEconomica;
    float ValorExecutiva;   
    int AssentosOcupados;
    char Voo[15], Origem[5], Destino[5]; 
    int Dia, Mes, Ano;
    int Canceladas; //Quantidade de reservas canceladas
}Voo;


void CopiaDados(Passageiro **Lugares, Voo *InfVoo, int *TamVet); 
/*
Função que copia dados de um arquivo binário para as estruturas de voo e passageiros.
 
 Parâmetros de Entrada:
    Lugares - ponteiro para o vetor de passageiros.
    InfVoo - ponteiro para a estrutura de informações do voo.
    TamVet - ponteiro para o tamanho do vetor de passageiros.
 */

void RealizarReserva(Passageiro **Lugares, Voo *InfVoo); 
/*
Função que realiza a reserva de um passageiro.
 
Parâmetros de Entrada:
    Lugares - ponteiro para o vetor de estruturas de passageiros.
    PassageirosAlocados - ponteiro para o número de passageiros alocados.
    InfVoo - ponteiro para a estrutura de informações do voo.
 */

void ImprimirReserva(Passageiro Reserva, Voo InfVoo); 
/*
 Função que imprime as informações de uma reserva.
 
 Parâmetros de Entrada:
    Reserva - estrutura de informações do passageiro.
    InfVoo - estrutura de informações do voo.
 */

int AchaReserva(Passageiro *Lugares, int Ocupados); 
/*
Função que encontra uma reserva com base no CPF.
 
Parâmetros de Entrada:
    Lugares - vetor de estruturas de passageiros.
    Ocupados - número de assentos ocupados.
  
  Parâmetros de Saída:
    Retorna o índice da reserva encontrada.
 */

void ModificarReserva(Passageiro *Lugares, Voo *InfVoo); 
/*
Função que modifica uma reserva existente.
 
 Parâmetros de Entrada:
    Lugares - vetor de estruturas de passageiros.
    InfVoo - ponteiro para a estrutura de informações do voo.
 */

void FechamentoDia(Passageiro *Lugares, int Ocupados);
/*
 Função que realiza o fechamento diário das reservas.
 
 Parâmetros de Entrada:
    Lugares - vetor de estruturas de passageiros.
    Ocupados - número de assentos ocupados.
 */

void FechamentoVoo(Passageiro *Lugares, Voo *InfVoo);//natalie
/**
 Função que realiza o fechamento do voo.
 
 Parâmetros de Entrada:
    Lugares - vetor de estruturas de passageiros.
    InfVoo - ponteiro para a estrutura de informações do voo.
 */

void GuardaDados(Passageiro *Lugares, Voo InfVoo);//cerri
/*
 Função que salva os dados das reservas e do voo em um arquivo binário.
 
 Parâmetros de Entrada:
    Lugares - vetor de estruturas de passageiros.
    InfVoo - estrutura de informações do voo.
 */

void RealocaVet(Passageiro **Lugares, int Ocupado, int *Alocado);//cerri
/*
 Função que realoca o vetor de passageiros se não houver espaço suficiente previamente alocado.
 
 Parâmetros de Entrada:
    Lugares - ponteiro para o vetor de passageiros.
    Ocupado - número de assentos ocupados.
    Alocado - ponteiro para o número de passageiros alocados no vetor.
*/

void *AlocaVet(int Tam, int Tipo);
/*
 Função que aloca memória para um vetor.
 
 Parâmetros de Entrada:
    Tam - tamanho do vetor.
    Tipo - tipo de dado do vetor.
  
 Parâmetros de Saída:
    Retorna o ponteiro para o vetor alocado.
 */

int main (void) {

    int PassageirosAlocados; char Comando[3]; int i;
    Passageiro *Lugares = NULL; Voo InfVoo; 

    CopiaDados(&Lugares, &InfVoo, &PassageirosAlocados);

    while(1) {
        scanf(" %2s", Comando);

        if (!strcmp(Comando, "FV") || InfVoo.QtdAssentos == InfVoo.AssentosOcupados-InfVoo.Canceladas){
            FechamentoVoo(Lugares, &InfVoo); //imprime informacaoes
            GuardaDados(Lugares, InfVoo); 
            free(Lugares);
            Lugares = NULL;
            return (0);
        
        }
        else if (!strcmp(Comando, "RR")) { 
            RealocaVet(&Lugares, InfVoo.AssentosOcupados, &PassageirosAlocados);

            RealizarReserva(&Lugares, &InfVoo);

        }
        else if (!strcmp(Comando, "CR")) { //Consultar Lugares

            i = AchaReserva(Lugares, InfVoo.AssentosOcupados);     
            if(Lugares[i].Status == 1 || i > InfVoo.AssentosOcupados)
                printf("Reserva não encontrada.\n");
            else
                ImprimirReserva(Lugares[i], InfVoo);  
           
        }
        else if (!strcmp(Comando, "MR")) { //Modificar Lugares
            ModificarReserva(Lugares, &InfVoo);
            
        
        }
        else if (!strcmp(Comando, "CA")) { 
            if (InfVoo.Status == 1){ //o voo está fechado
                FechamentoVoo(Lugares, &InfVoo);   
                scanf("%*s");      
            } 
            else{
                i = AchaReserva(Lugares, InfVoo.AssentosOcupados);
                Lugares[i].Status = 1;
                InfVoo.Canceladas++;
            }
            
        }
        else if (!strcmp(Comando, "FD")) {
            FechamentoDia(Lugares, InfVoo.AssentosOcupados);
            InfVoo.AssentosOcupados -= InfVoo.Canceladas;
            GuardaDados(Lugares, InfVoo);
            free(Lugares);
            Lugares = NULL;
            
            return 0;
        }
    
    }
    

    return 0;
}

/*
A funcao CopiaDados() tenta abrir o arquivo "Dados.bin",
se o arquivo existe, as informçaões do voo são lidas (InfVoo), é alocado a quantidade 
de assentos já ocupados mais 10 posiçoes no vetor de passageiros (Lugares), a variável 
Canceladas é zerada a cada abertura de arquivo.
Se o arquivo não existe, são alocadas 10 posiçoes para o vetor (Lugares) e é lido o comando AV
(Abertura de Voo) que recebe as informações de quantidade de assentos e os valores das passagens. 
O Status igual a 0 significa que o voo está aberto. 
*/
void CopiaDados(Passageiro **Lugares, Voo *InfVoo, int *PassageirosAlocados) {
    FILE* fp = fopen("Dados.bin", "rb");
    char Comando[3]; 

    if (fp != NULL) { 
        fread(InfVoo, sizeof(Voo), 1, fp); 
        
        (*Lugares) = (Passageiro*) AlocaVet((InfVoo->AssentosOcupados+10), sizeof(Passageiro)); 
        
        fread(*Lugares, sizeof(Passageiro), InfVoo->AssentosOcupados, fp);
        *PassageirosAlocados = InfVoo->AssentosOcupados + 10;
        InfVoo->Canceladas = 0;
        fclose(fp);
        fp = NULL;
    } 
    else {  
        
        (*Lugares) = (Passageiro*) AlocaVet(10, sizeof(Passageiro)); 
        *PassageirosAlocados = 10;
        
        scanf(" %s", Comando); 
        scanf(" %d %f %f", &(InfVoo->QtdAssentos), &(InfVoo->ValorEconomica), &(InfVoo->ValorExecutiva));
        InfVoo->Canceladas = 0; 
        InfVoo->AssentosOcupados = 0; 
        InfVoo->Status = 0; 

    }
    
}

/*
A função RealizarReserva() primeiro verifica se o voo está aberto, caso esteja fechado são impressas as
informações de fechamento de voo e não é feita a reserva. Depois, são lidos os dados do passageiro 
(Nome, Sobrenome, CPF, Data, Voo, Assento, Classe, Valor, Origem e Destino) que são armazenados na variável 
InfVoo e no vetor Lugares na posição AssentosOcupados. Ao final é feito o incremento na variável AssentosOcupados de InfVoo.
*/
void RealizarReserva(Passageiro **Lugares, Voo *InfVoo) {  
    if(InfVoo->Status == 1){ //o voo está fechado 
        FechamentoVoo((*Lugares), InfVoo);
        scanf(" %*s %*s %*s %*d %*d %*d %*s %*s %*s %*f %*s %*s");
    }else{
        int i =  InfVoo->AssentosOcupados;  
        scanf(" %s %s %s %d %d %d %s %s %s %f %s %s", (*Lugares)[i].Nome,  (*Lugares)[i].Sobrenome,  (*Lugares)[i].CPF, 
        &InfVoo->Dia, &InfVoo->Mes, &InfVoo->Ano, InfVoo->Voo, (*Lugares)[i].Assento, (*Lugares)[i].Classe,
        &(*Lugares)[i].Valor, InfVoo->Origem, InfVoo->Destino);  
        (*Lugares)[i].Status = 0;
        InfVoo->AssentosOcupados++; 
    }
    
}
/*
A funcao ImprimirReserva() imprime as informações da variável Reserva do tipo Passageiro que é passada 
como parâmetro para a função. 
*/

void ImprimirReserva(Passageiro Reserva, Voo InfVoo) { 
    printf("%s\n", Reserva.CPF);
    printf("%s %s\n", Reserva.Nome, Reserva.Sobrenome);
    printf("%02d/%02d/%d\n", InfVoo.Dia, InfVoo.Mes, InfVoo.Ano);
    printf("Voo: %s\n", InfVoo.Voo);
    printf("Assento: %s\n", Reserva.Assento);
    printf("Classe: %s\n", Reserva.Classe);
    printf("Trecho: %s %s\n", InfVoo.Origem, InfVoo.Destino);
    printf("Valor: %.2f\n", Reserva.Valor);
    printf("--------------------------------------------------\n");
}

/*
A função AchaReserva() lê um CPF (uma string) e percorre os elementos do vetor Lugares 
até que ele encontre um CPF que seja igual ao adquirido ou até que ele tenha percorrido 
todas as posições ocupadas. Devolve o índice da posição com o mesmo CPF do lido. 
*/

int AchaReserva(Passageiro *Lugares, int Ocupados) {
    char Consulta[15]; int i = 0;
    scanf(" %s", Consulta);

    while (strcmp(Consulta, Lugares[i].CPF)!= 0 && i <= Ocupados) { //com esse i <= Ocupados devolve um indice valido 
    //se eu peco um elemento com um CPF que não existe ele da um print com nada 
        i++; 
    }
    
    return i;
}

/*
A funcao ModificarReserva primeiro verifica se o voo está aberto, caso esteja fechado são impressas as
informações de fechamento de voo e não é feita a modificação. A função AchaReserva devolve o índice da 
passagem que vai ser alterada. Primeiramente, verifica-se se essa passagem foi cancelada, se não, são
lidos os novos dados e as informações alteradas são impressas na tela.  
*/

void ModificarReserva(Passageiro *Lugares, Voo *InfVoo) {
    if(InfVoo->Status == 1){ //o voo está fechado 
        FechamentoVoo(Lugares, InfVoo);
        scanf("%*s %*s %*s %*s");
    }
    else {
        int i = AchaReserva(Lugares, InfVoo->AssentosOcupados);
        if(Lugares[i].Status == 1 || i>InfVoo->AssentosOcupados){
            printf("Reserva não encontrada.\n");
        }
        else {
            scanf("%s %s %14s %s", Lugares[i].Nome, Lugares[i].Sobrenome,
            Lugares[i].CPF, Lugares[i].Assento);

            printf("Reserva Modificada:\n");
            ImprimirReserva(Lugares[i], *InfVoo);
        }
    }
}

/*
A função FechamentoDia percorre o vetor Lugares e soma o número de reservas não canceladas, 
bem como os valores das passagens de cada reserva ativa. Então, a função imprime a quantidade 
total de reservas válidas e o valor total arrecadado até então.
*/

void FechamentoDia(Passageiro *Lugares, int Ocupados){
    float ValorParcial = 0;
    int ReservasAtivas = 0;

    for(int i = 0; i < Ocupados; i++){
        if(Lugares[i].Status == 0){ //nao foi cancelado
            ValorParcial += Lugares[i].Valor;
            ReservasAtivas++;

        }
    }
    printf("Fechamento do dia:\nQuantidade de Reservas: %d\nPosição: %.2f\n", ReservasAtivas, ValorParcial);
    printf("--------------------------------------------------\n");

}

void FechamentoVoo(Passageiro *Lugares, Voo *InfVoo) {
    float ValorTotal = 0;
    printf("Voo Fechado!\n");

    for (int i = 0; i < InfVoo->AssentosOcupados; i++) {
        if(!Lugares[i].Status) {

        printf("\n%s\n", Lugares[i].CPF);
        printf("%s %s\n", Lugares[i].Nome, Lugares[i].Sobrenome);
        printf("%s\n", Lugares[i].Assento);
                    
        ValorTotal += Lugares[i].Valor;
        }
    }
    InfVoo->Status = 1; 
    printf("Valor Total: %.2f\n", ValorTotal);
    printf("--------------------------------------------------\n");
    
}

/*A funcação GuardaDados armazena as informacoes do voo (InfVoo) e o vetor
de Passageiros (Lugares), sempre tomando cuidado de não guardar as informações
de reservas canceladas*/

void GuardaDados(Passageiro *Lugares, Voo InfVoo) {
    FILE *fp = fopen("Dados.bin", "wb");
    fwrite(&InfVoo, sizeof(Voo), 1, fp);
    for (int i = 0; i < InfVoo.AssentosOcupados+InfVoo.Canceladas; i++){
        if (Lugares[i].Status == 0) { //nao foi cancelado
            fwrite(&Lugares[i], sizeof(Passageiro), 1, fp);
        }
    }   
    fclose(fp);
    fp = NULL;
}

/*A função RealocaVet faz a verificação da quantidade de casas alocadas no vetor de 
Passageiros (Lugares), caso seja igual a quantidade de casas ocupadas (Ocupado),
é realizada a realocação do vetor adicionando 10 posições a mais.
A função aborta o programa em caso de erro na realocação*/

void RealocaVet(Passageiro **Lugares, int Ocupado, int *Alocado) {
    if (Ocupado == (*Alocado)) {
        (*Lugares) = (Passageiro*)realloc((*Lugares), (Ocupado+10)*sizeof(Passageiro)); 
        (*Alocado) += 10;
    }
    if (*Lugares == NULL) {
        printf("Erro na realocação de memória\n");
        exit (1);
    }
}

void *AlocaVet(int Tam, int Tipo) {
    void *vet = malloc(Tam*Tipo);
    if (vet == NULL) {
        printf("Erro na alocação de memória\n");
        exit(1);
    }
    else 
        return vet;
}