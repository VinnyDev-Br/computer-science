import java.util.Scanner;

public class Exec{

public Investimento criarInvestimento(int i, Scanner entrada) {
    switch (i) {
        case 1: {
            String nome = entrada.nextLine();
            String dataCompra = entrada.nextLine();
            String ticker = entrada.nextLine();
            double valorInvestido = entrada.nextDouble();
            double precoAtual = entrada.nextDouble();
            entrada.nextLine();
            return new Acoes(nome, dataCompra, valorInvestido, ticker, precoAtual);
        }
        case 2: {
            String nome = entrada.nextLine();
            String dataCompra = entrada.nextLine();
            double taxaCDI = entrada.nextDouble();
            double valorInvestido = entrada.nextDouble();
            entrada.nextLine();
            return new RendaFixa(nome, dataCompra, valorInvestido, taxaCDI);
        }
        default:
            System.out.println("Inválido");
            return null;
    }
}
    
    public static void main(String args[]){

        Scanner entrada = new Scanner(System.in)
        Investimento[] investimento = new Investimento[2];


    }
}