/* realizar operações para armazenar e romover pessoas, 
achar uma pessoa pelo nome e achar a pessoa que está em 
uma determinada posição da agenda.*/


public class Agenda{
    private Pessoa[] agenda;
    private short qtdPessoas;
    private int MAX_TAM = 100;

    public Agenda(){
        agenda = new Pessoa[MAX_TAM];
        qtdPessoas = 0;
    }

    public boolean adicionar(Pessoa p){
        short pos = acharPosicao(p.getName());
        if (agenda[pos] != null)
            return false;

        agenda[pos] = p;
        qtdPessoas++;
    
        return true;
    }

    public Pessoa remover(Pessoa p){
        short pos = acharPosicao(p.getName());
        if (pos == -1)
            return null;
        Pessoa out = agenda[pos];
        agenda[pos] = null;
        qtdPessoas--;

        return out;
    }

    public Pessoa buscaNome(String nome){
        short pos = acharPosicao(nome);
        return agenda[pos];
    }

    public Pessoa buscaPosicao(short pos){
        return agenda[pos];
    }

    public void mostrarTudo(){
        System.out.println("Pessoas:");
        short cnt = 0;
        for (short i = 0; cnt < qtdPessoas; i++) {
            if (agenda[i] != null) {
                System.out.printf("\t%d\t%s\n", i, agenda[i].getName());
                cnt++;
            }
        }
    }

    /* Se não acha o nome: retorna a devida posição vazia para ele 
       Se acha: retorna a posição da pessoa com aquele nome. */
    private short acharPosicao(String nome){
        short i, cnt = 0;
        for (i = 0; cnt < qtdPessoas; i++){
            if (agenda[i] != null){ // se é null eu vou pra próx
                cnt++;
                int comp = agenda[i].getName().compareTo(nome); // usar str1.equals(str2)
                if (comp < 0)
                    continue;
                else if (comp > 0)
                    moverDireita(i);
                break;
            }
        }
        return i;
    }

    private void moverDireita(short pos){
        for (int i = MAX_TAM - 2; i > pos; i--){
            agenda[i+1] = agenda[i];
        }
    }

}