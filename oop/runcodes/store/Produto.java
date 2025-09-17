public class Produto {
    protected long codigo;
    protected int ano, qtd;
    protected String titulo, autoria;

    public Produto(long cod, String nome, String autor, int ano){
        codigo = cod;
        titulo = new String(nome);
        autoria = new String(autor);
        this.ano = ano;
        qtd = 0;
    }

    public long codigo() {
        return codigo;
    }

    public int ano() {
        return ano;
    }

    public int quantidade() {
        return qtd;
    }

    public String titulo() {
        return titulo;
    }

    public String autoria() {
        return autoria;
    }

    public void transacao(int variacao) {
        qtd += variacao;
    }

    public void imprime() {
        System.out.printf("Código: %d\nTítulo: %s\nAutoria: %s\nAno: %d\nQuantidade: %d\n", codigo, titulo, autoria, ano, qtd);
    }
}