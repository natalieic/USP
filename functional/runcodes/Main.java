// Natalie Isernhagen Coelho - 15481332
import java.util.Scanner;
import java.nio.file.Paths;
import java.nio.file.Path;
import java.nio.file.Files;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.stream.Stream;

public class Main {
    public static void main(String[] args) {
        // Leitura das entradas
        int n1, n2, n3, n4;
        Scanner input = new Scanner(System.in);
        n1 = input.nextInt();
        n2 = input.nextInt();
        n3 = input.nextInt();
        n4 = input.nextInt();

        // Acessa o arquivo
        Path file = Paths.get("dados.csv");
        // Processa o csv e retorna uma ArrayList cujos elementos são 
        // arrays de strings que representam as linhas e cada string da
        // é um campo do csv
        ArrayList<String[]> listOfColumns = parseCsv(file);

        // Inicializa o array de objetos StatPais
        ArrayList<StatPais> stats = new ArrayList<StatPais>();

        // Constrói um StatPais para cada linha processada do arquivo
        // e adiciona no array
        for (String[] column: listOfColumns) {
            String country = column[0];
            int confirmed = Integer.parseInt(column[1]);
            int deaths = Integer.parseInt(column[2]);
            int recovery = Integer.parseInt(column[3]);
            int active = Integer.parseInt(column[4]);

            StatPais newStat = new StatPais(country, confirmed, deaths, recovery, active);
            stats.add(newStat);
        }

    // 1) Imprime a soma de 'active' dos países em que 'confirmed' é >= n1
        int sum = stats
                .stream()
                .filter(s -> s.getConfirmed() >= n1)
                .mapToInt(StatPais::getActive)
                .sum();
        System.out.println(sum);

    // 2) Imprime a soma de 'deaths' dos n3 países com menor 'confirmed' dentre os n2 com maior 'active'
        sum = stats
            .stream()
            .sorted(Comparator.comparing(StatPais::getActive).reversed())
            .limit(n2)
            .sorted(Comparator.comparing(StatPais::getConfirmed))
            .limit(n3)
            .mapToInt(StatPais::getDeaths)
            .sum();
        System.out.println(sum);

    // 3) Imprime em ordem o 'country' dos n4 países com maior 'confirmed'
        stats
            .stream()
            .sorted(Comparator.comparing(StatPais::getConfirmed).reversed())
            .limit(n4)
            .map(StatPais::getCountry)
            .sorted()
            .forEach(s -> System.out.println(s));
    }

    // Função que processa o arquivo csv e retorna os dados em strings
    private static ArrayList<String[]> parseCsv(Path file) {
        // Array que recebe as linhas do csv
        ArrayList<String> lines = new ArrayList<String>();
        // Array que recebe as linhas quebradas em campos
        ArrayList<String[]> splittedColumns = new ArrayList<String[]>();

        try {
           lines.addAll(Files.readAllLines(file)); // Lê as linhas do csv
        } catch (IOException e) {
            System.out.println("Erro no processamento do arquivo.");
            return splittedColumns;
        }
        // Para cada linha, separa por vírgula e adiciona no array final
        lines.stream().map(line -> line.split(",")).forEach(columns -> splittedColumns.add(columns));

        return splittedColumns;
    }
}

// Definição da classe StatPais
class StatPais {
    private String country;
    private int confirmed;
    private int deaths;
    private int recovery;
    private int active;

    public StatPais(String country, int confirmed, int deaths, int recovery, int active) {
        this.country = country;
        this.confirmed = confirmed;
        this.deaths = deaths;
        this.recovery = recovery;
        this.active = active;
    }

    public String getCountry() {
        return this.country;
    }

    public int getConfirmed() {
        return this.confirmed;
    }

    public int getDeaths() {
        return this.deaths;
    }

    public int getRecovery() {
        return this.recovery;
    }

    public int getActive() {
        return this.active;
    }

}