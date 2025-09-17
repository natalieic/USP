public class CD extends Produto {
    private String gravadora;
    private int trilhas;

    public CD(long codigo, String titulo, String artista, int trilhas, String gravadora, int ano) {
        super(codigo, titulo, artista, ano);
        this.gravadora = new String(gravadora);
        this.trilhas = trilhas;
    }

    public int trilhas() {
        return trilhas;
    }

    public String gravadora() {
        return gravadora;
    }

    @Override
    public void imprime() {
        System.out.printf("CD\nCódigo: %d\nTítulo: %s\nBanda: %s\nGravadora: %s\nAno: %d\ntrilhas: %d\n", codigo, titulo, autoria, gravadora, ano, trilhas);
    }
}