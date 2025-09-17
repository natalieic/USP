
public class Elevador{
    private int atual, andares, lotacao, lotMax;
    private byte status;    // 1 = subindo, 0 = parado, -1 = descendo

    public Elevador(int total, int capacidade){
        atual = 0;
        andares = total;
        lotacao = 0;
        lotMax = capacidade;
        status = 0;
    }

    public chamar(int curr, int dest){

    }

    private static byte locate(int meuAndar){
            byte l;
        if (atual > meuAndar)
            l = 1;
        else if (atual == meuAndar)
            l = 0;
        else
            l = -1;

        return l;
    }

    public static void main(String[] args){
        
    }
}

/* Classe tv: 
    priorizar inicialização dentro do contrutor
*/