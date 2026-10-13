import java.util.Scanner;

public class Exec1 {

    // Método auxiliar: retorna a instância conforme o tipo escolhido
    public static Investimento criarInvestimento(int tipo, Scanner entrada) {
        switch (tipo) {
            case 1: {
                System.out.println("Nome, data da compra, ticker, valor investido e preço atual:");
                String nome = entrada.nextLine();
                String dataCompra = entrada.nextLine();
                String ticker = entrada.nextLine();
                double valorInvestido = entrada.nextDouble();
                double precoAtual = entrada.nextDouble();
                entrada.nextLine(); // limpa o buffer
                return new Acoes(nome, dataCompra, valorInvestido, ticker, precoAtual);
            }
            case 2: {
                System.out.println("Nome, data da compra, taxa CDI (%) e valor investido:");
                String nome = entrada.nextLine();
                String dataCompra = entrada.nextLine();
                double taxaCDI = entrada.nextDouble();
                double valorInvestido = entrada.nextDouble();
                entrada.nextLine(); // limpa o buffer
                return new RendaFixa(nome, dataCompra, valorInvestido, taxaCDI);
            }
            default:
                System.out.println("Inválido");
                return null;
        }
    }

    public static void main(String[] args) {
        try (Scanner entrada = new Scanner(System.in)) {
            System.out.println("Digite 1-Ações, 2-Renda Fixa");
            int opc = entrada.nextInt();
            entrada.nextLine();

            Investimento e = criarInvestimento(opc, entrada);

            if (e != null) {
                System.out.println("Quantidade de dias:");
                int dias = entrada.nextInt();
                entrada.nextLine();

                double retorno = e.calcularRetorno(dias);
                System.out.println("O retorno foi: " + retorno);

                if (e instanceof Tributavel) {
                    double imposto = ((Tributavel) e).calcularImposto(retorno);
                    System.out.println("O valor do imposto foi: " + imposto);
                }
            }
        }
    }
}