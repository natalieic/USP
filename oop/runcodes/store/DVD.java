public class DVD extends Produto {
    private String idioma, genero, nacionalidade;

    public DVD(long codigo, String titulo, String diretor, String idioma, String genero, int ano, String nacionalidade) {
        super(codigo, titulo, diretor, ano);
        this.idioma = new String(idioma);
        this.genero = new String(genero);
        this.nacionalidade = new String(nacionalidade);
    }

    public String idioma() {
        return idioma;
    }

    public String genero() {
        return genero;
    }

    public String nacionalidade() {
        return nacionalidade;
    }

    @Override
    public void imprime() {
        System.out.printf("DVD\nCódigo: %d\nTítulo: %s\nDiretor: %s\nGênero: %s\nAno: %d\nNacionalidade: %s\nIdioma: %s\n", codigo, titulo, autoria, genero, ano, nacionalidade, idioma);
    }
}