import java.util.Arrays;

public class Loja {
    private Produto[] produtos;
    private int qtdProdutos;

    public Loja(){
        produtos = new Produto[100];
        qtdProdutos = 0;
    }


    public boolean inserir(Produto p) {
        int index = busca(p.codigo);
        if (index >= 0)
            return false;

        produtos[qtdProdutos] = p;
        qtdProdutos++;
        
        return true;
    }


    public boolean adicionar(long codigo, int quantidade) {
        int index = busca(codigo);
        if (index == -1)
            return false;
        
        produtos[index].transacao(quantidade);

        return true;
    }


    public int vender(long codigo, int quantidade) {
        int index = busca(codigo);
        if (index == -1)
            return -1;

        Produto p = produtos[index];
        if (p.quantidade() - quantidade < 0)
            return 0;
        
        p.transacao(-quantidade);

        return 1;
    }


    public Produto procurar(long codigo) {
        int index = busca(codigo);
        return index != -1 ? produtos[index] : null;
    }


    public Produto procurar(String titulo) {
        for (int i = 0; i < qtdProdutos; i++) {
            if (produtos[i].titulo.equals(titulo))
                return produtos[i];
        }

        return null;
    }


    public void sumario() {
        int cnt = 0;
        for (int i = 0; i < qtdProdutos; i++) {
            if (produtos[i] instanceof Livro){
                Livro l = (Livro) produtos[i];
                l.imprime();
                System.out.println("Quantidade: " + l.quantidade() + "\n");
                cnt += l.quantidade();
            }
        }
        System.out.println("Quantidade de Livros: " + cnt + "\n");
        cnt = 0;

        for (int i = 0; i < qtdProdutos; i++) {
            if (produtos[i] instanceof CD){
                CD c = (CD) produtos[i];
                c.imprime();
                System.out.println("Quantidade: " + c.quantidade() + "\n");
                cnt += c.quantidade();
            }
        }
        System.out.println("Quantidade de CDs: " + cnt + "\n");
        cnt = 0;

        for (int i = 0; i < qtdProdutos; i++) {
            if (produtos[i] instanceof DVD){
                DVD d = (DVD) produtos[i];
                d.imprime();
                System.out.println("Quantidade: " + d.quantidade() + "\n");
                cnt += d.quantidade();
            }
        }
        System.out.println("Quantidade de DVDs: " + cnt + "\n");
    }

    
    private int busca(long codigo) {
        for (int i = 0; i < qtdProdutos; i++) {
            if (produtos[i].codigo() == codigo)
                return i;
        }

        return -1;
    }

}