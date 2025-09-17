import java.util.Scanner;
import java.time.LocalDate;

public class Main{
    // public static void main(String[] args){
    //     Pessoa eu = new Pessoa("Natalie", java.time.LocalDate.of(2006, 6, 8), 52, 163);
    //     System.out.printf("Nome: %s\nIdade: %d\n", eu.getName(), eu.idade());

    //     String instr;
    //     Scanner input = new Scanner(System.in);
    //     do {
    //         instr = input.next();
    //         switch (instr){
    //             case "new":
    //                 System.out.printf("\nInsira:\nNome\nData de nascimento (DD MM AAAA)\nPeso\nAltura\n\n");
    //                 String nome;
    //                 int dd, mm, aaaa;
    //                 float peso, altura;
    //                 nome = input.next();
    //                 dd = input.nextInt();
    //                 mm = input.nextInt();
    //                 aaaa = input.nextInt();
    //                 peso = input.nextFloat();
    //                 altura = input.nextFloat();
    //                 break;
    //             case "exit":
    //                 System.exit(0);
    //             default:
    //                 System.out.println("Instrução inválida.");
    //         }
            
    //     } while (true);
    // }

    public static void main(String[] args){
        Agenda rede = new Agenda();
        Pessoa p1 = new Pessoa("Natalie", LocalDate.of(2006, 6, 8), 52, 164);
        rede.adicionar(p1);
        rede.adicionar(new Pessoa("Caio", LocalDate.of(2005, 6, 8), 52, 164));
        rede.adicionar(new Pessoa("Nicolas", LocalDate.of(2005, 6, 8), 52, 164));
        rede.adicionar(new Pessoa("Felipe", LocalDate.of(2005, 6, 8), 52, 164));
        rede.adicionar(new Pessoa("Veiga", LocalDate.of(2005, 6, 8), 52, 164));
        rede.adicionar(new Pessoa("Akimi", LocalDate.of(2005, 6, 8), 52, 164));

        rede.mostrarTudo();

    }
}