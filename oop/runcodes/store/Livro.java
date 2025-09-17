public class Livro extends Produto {
    private String editora, idioma;
    private int edicao, paginas;

    public Livro(long codigo, String titulo, String autor, String editora, int ano, int edicao, int paginas, String idioma) {
        super(codigo, titulo, autor, ano);
        this.editora = new String(editora);
        this.edicao = edicao;
        this.paginas = paginas;
        this.idioma = new String(idioma);
    }

    public String editora() {
        return editora;
    }

    public String idioma() {
        return idioma;
    }

    public int edicao() {
        return edicao;
    }

    public int paginas() {
        return paginas;
    }

    @Override
    public void imprime() {
        System.out.printf("Livro\nCódigo: %d\nTítulo: %s\nAutor: %s\nEditora: %s\nEdição: %d\nAno: %d\nPáginas: %d\nIdioma: %s\n", codigo, titulo, autoria, editora, edicao, ano, paginas, idioma);
    }
}