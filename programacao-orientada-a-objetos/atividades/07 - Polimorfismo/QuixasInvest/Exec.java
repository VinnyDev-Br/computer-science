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

        int opc = -1;

        for (int i = 0; i < 2; i++){
            System.out.println("Escolha o tipo de investimento 1-Ação 2-Renda fixa para a posição: "+i);
            opc = entrada.nextInt();
            investimento[i] = criarInvestimento(opc, entrada);

            if (investimento[i] == null) {break;}


            double retorno = investimento[i].calcularRetorno();
            int dias = entrada.nextInt();

            
            if (opc == 1){
                System.out.println("O retorno Obtido foi: " + investimento[i].calcularRetorno(dias) + "/n");
                System.out.println("O imposto sobre o valor foi: "+ investimento.calcularImposto(retorno) + "/n");
            } // Ação
            else {
                System.out.println("O retorno Obtido foi: " + investimento[i].calcularRetorno(dias) + "/n");
            } // Renda fixa

        } 


        entrada.close();
    }


    
}