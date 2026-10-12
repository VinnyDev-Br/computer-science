import java.util.Scanner;

public class Quixasinvest {

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
        Scanner entrada = new Scanner(System.in);
        Investimento[] investimentos = new Investimento[2];

        for (int i = 0; i < investimentos.length; i++) {
            System.out.println("Escolha o tipo de investimento (1-Ação, 2-Renda fixa) para a posição " + i + ":");
            int opc = entrada.nextInt();
            entrada.nextLine(); // limpa o \n que sobrou do nextInt

            investimentos[i] = criarInvestimento(opc, entrada);
            if (investimentos[i] == null) {
                break;
            }

            System.out.println("Quantidade de dias do investimento:");
            int dias = entrada.nextInt();
            entrada.nextLine();

            // Chamada polimórfica
            double retorno = investimentos[i].calcularRetorno(dias);
            System.out.println("O retorno obtido foi: " + retorno);

            // Só Acoes é Tributavel
            if (investimentos[i] instanceof Tributavel) {
                Tributavel t = (Tributavel) investimentos[i];
                System.out.println("O imposto sobre o retorno foi: " + t.calcularImposto(retorno));
            }
        }

        entrada.close();
    }
}