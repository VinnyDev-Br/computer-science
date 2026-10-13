import java.util.Scanner;

public class Exec2{
    public static Investimento criarInvestimento(int opc, Scanner entrada){
        switch (opc){
            case 1: {
                String nome = entrada.nextLine();
                String dataCompra = entrada.nextLine();
                double valorInvestido = entrada.nextDouble();
                double taxaCDI = entrada.nextDouble();
                entrada.nextLine(); // Quebra linha
                return new RendaFixa(nome, dataCompra, valorInvestido, taxaCDI);
            }
            case 2: {
                String nome = entrada.nextLine();
                String dataCompra = entrada.nextLine();
                String ticker = entrada.nextLine();
                double precoAtual = entrada.nextDouble();
                double valorInvestido = entrada.nextDouble();   
                entrada.nextLine();
                return new Acoes(nome, dataCompra, valorInvestido, ticker, precoAtual);             
            }
            default:
                System.out.println("Inválido");                
                return null;
        } 
    }

    public static void main(String args[]){
        Scanner entrada = new Scanner(System.in);

        System.out.println("Digite 1-Renda Fixa, 2-Ações");
        int opc = entrada.nextInt();
        entrada.nextLine();

        Investimento e = criarInvestimento(opc, entrada);

        if (e != null){
            double retorno = e.calcularRetorno();           
            if (opc == 1){
                System.out.println("O retorno da Renda fixa foi: " + retorno + "\n");
            }
            else{
                double imposto = e.calcularImposto();
                System.out.println("O retorno da Ação foi: " + retorno + "\n");
                System.out.println("O valor do imposto foi: " + imposto + "\n");
            }
        }

        entrada.close();
    }

    
}