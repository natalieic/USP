import java.util.Scanner;

public class Calc {
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        int n1 = input.nextInt();
        char op = input.next().charAt(0);
        int n2 = input.nextInt();
        long res = 0;
        switch(op){
            case '+': res = n1 + n2; break;
            case '-': res = n1 - n2; break;
            case '*': res = n1 * n2; break;
            case '/': res = n1 / n2; break;
            default: System.out.println("Operação inválida.");
            System.exit(0);
        }

        System.out.printf("%d %c %d = %d%n", n1, op, n2, res);
    }
}