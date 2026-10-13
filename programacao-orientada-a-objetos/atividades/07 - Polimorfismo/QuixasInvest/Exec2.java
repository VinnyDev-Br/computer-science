import java.util.Scanner;

public class Exec2 {

    public static Investimento criarInvestimento(int tipo, Scanner entrada) {
        switch (tipo) {
            case 1: {
                System.out.println("Nome, data da compra, ticker, valor investido e preço atual:");
                String nome = entrada.nextLine();
                String dataCompra = entrada.nextLine();
                String ticker = entrada.nextLine();
                double valorInvestido = entrada.nextDouble();
                double precoAtual = entrada.nextDouble();
                entrada.nextLine();
                return new Acoes(nome, dataCompra, valorInvestido, ticker, precoAtual);
            }
            case 2: {
                System.out.println("Nome, data da compra, taxa CDI (%) e valor investido:");
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

    public static void main(String[] args) {
        try (Scanner entrada = new Scanner(System.in)) {
            Investimento[] investimentos = new Investimento[2];

            for (int i = 0; i < investimentos.length; i++) {
                System.out.println("Escolha o tipo (1-Ações, 2-Renda Fixa) para a posição " + i + ":");
                int opc = entrada.nextInt();
                entrada.nextLine();

                investimentos[i] = criarInvestimento(opc, entrada);
                if (investimentos[i] == null) {
                    break;
                }

                System.out.println("Quantidade de dias:");
                int dias = entrada.nextInt();
                entrada.nextLine();

                double retorno = investimentos[i].calcularRetorno(dias);
                System.out.println("O retorno foi: " + retorno);

                if (investimentos[i] instanceof Tributavel) {
                    double imposto = ((Tributavel) investimentos[i]).calcularImposto(retorno);
                    System.out.println("O valor do imposto foi: " + imposto);
                }
            }
        }
    }
}