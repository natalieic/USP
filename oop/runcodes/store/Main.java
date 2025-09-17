import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Loja loja = new Loja();
        Scanner input = new Scanner(System.in);

        while (input.hasNextLine()) {
            String linha = input.nextLine();
            String[] partes = linha.split(",");

            switch (partes[0]) {
                case "I": 
                    opInserir(loja, partes);
                    break;

                case "A":
                    opAdicionar(loja, partes);
                    break;

                case "V":
                    opVender(loja, partes);
                    break;

                case "P":
                    opProcurar(loja, partes);
                    break;

                case "S":
                    opSumarizar(loja);
                    break;
            }

        }
    }


    private static void opInserir(Loja loja, String[] partes) {
        System.out.printf("\nOperação inserir ");
        Produto p;
        long codigo = Long.parseLong(partes[2]);

        if (partes[1].equals("Livro")){
            p = new Livro(codigo, partes[3], partes[4], partes[5], Integer.parseInt(partes[6]), Integer.parseInt(partes[7]), Integer.parseInt(partes[8]), partes[9]);
            System.out.println("livro: " + codigo);
        }
        else if (partes[1].equals("CD")){
            p = new CD(codigo, partes[3], partes[4], Integer.parseInt(partes[5]), partes[6], Integer.parseInt(partes[7]));
            System.out.println("CD: " + codigo);
        }

        else {
            p = new DVD(codigo, partes[3], partes[4], partes[5], partes[6], Integer.parseInt(partes[7]), partes[8]);
            System.out.println("DVD: " + codigo);
        }
        
        if (loja.inserir(p))
            mensagemDeSucesso();
        else
            mensagemDeErro(p.codigo(), 'C');
    }


    private static void opAdicionar(Loja loja, String[] partes) {
        long codigo = Long.parseLong(partes[1]);
        int qtd = Integer.parseInt(partes[2]);

        System.out.printf("\nOperação de compra: %d\n", codigo);

        if (loja.adicionar(codigo, qtd))
            mensagemDeSucesso(codigo);
        else
            mensagemDeErro(codigo, 'I');
    }


    private static void opVender(Loja loja, String[] partes) {
        long codigo = Long.parseLong(partes[1]);
        int qtd = Integer.parseInt(partes[2]);

        System.out.printf("\nOperação de venda: %d\n", codigo);

        int resultado = loja.vender(codigo, qtd);

        if(resultado == 1)
            mensagemDeSucesso(codigo);
        else if (resultado == 0)
            mensagemDeErro(codigo, qtd);
        else
            mensagemDeErro(codigo, 'I');
    }


    private static void opProcurar(Loja loja, String[] partes) {
        Produto encontrado;
        System.out.printf("\nProcurando: %s\n", partes[1]);

        try {
            long codigo = Long.parseLong(partes[1]);
            encontrado = loja.procurar(codigo);
        } catch (NumberFormatException e) {
            encontrado = loja.procurar(partes[1]);
        }

        if (encontrado != null){
            System.out.println("Encontrado:");
            encontrado.imprime();
        }
        else
            System.out.println("Produto não encontrado: " + partes[1]);
    }


    private static void opSumarizar(Loja loja) {
        System.out.println("\nOperação de sumarização: ");
        loja.sumario();
    }


    private static void mensagemDeSucesso() {
        System.out.println("Operação realizada com sucesso");
    }


    private static void mensagemDeSucesso(long codigo) {
        System.out.println("Operação realizada com sucesso: " + codigo);
    }


    private static void mensagemDeErro(long codigo, char erro) {
        if (erro == 'C') {
            System.out.printf("***Erro: Código já cadastrado: %d\n", codigo);
        } else if (erro == 'I') {
            System.out.printf("***Erro: Código inexistente: %d\n", codigo);
        }
    }

    
    private static void mensagemDeErro(long codigo, int qtd) {
        System.out.printf("***Erro: Estoque insuficiente: %d Quantidade: %d\n", codigo, qtd);
    }
}