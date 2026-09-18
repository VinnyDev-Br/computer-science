import java.util.Scanner;

public class Exec {
    public static void main(String args[]) {
        Scanner entrada = new Scanner(System.in);
        ContaBancaria conta = new ContaBancaria(); 
        String opc = "";

        while (entrada.hasNextLine()) {
            opc = entrada.nextLine().trim();

            // 1. Ecoa o comando (Importante para o EXPECTED)
            System.out.println("$" + opc);

            if (opc.equals("criar")) {
                // Leitura dos 4 parâmetros para criar o Correntista e a Conta
                
                String nome = entrada.nextLine().trim();
                System.out.println("$" + nome);
                
                String cpf = entrada.nextLine().trim();
                System.out.println("$" + cpf);
                
                String saldoStr = entrada.nextLine().trim();
                System.out.println("$" + saldoStr);
                double saldo = Double.parseDouble(saldoStr);
                
                String especialStr = entrada.nextLine().trim();
                System.out.println("$" + especialStr);
                boolean ehEspecial = especialStr.equalsIgnoreCase("S");
                
                // CRIAÇÃO DOS OBJETOS (Composição)
                Correntista correntista = new Correntista(nome, cpf);
                
                // Usa o objeto correntista no construtor da ContaBancaria
                conta = new ContaBancaria(correntista, saldo, ehEspecial);
            }
            else if (conta == null) {
                System.out.println("ERRO: Conta ainda não foi criada. Use 'criar'.");
            }
            else if (opc.equals("mostrar")) {
                // Chama o toString() da ContaBancaria
                System.out.println(conta); 
            }
            else if (opc.equals("depositar")) {
                String valorStr = entrada.nextLine().trim();
                System.out.println("$" + valorStr);
                double valor = Double.parseDouble(valorStr);
                conta.depositar(valor);
                // Exibe o estado da conta após a operação para verificação do teste
                System.out.println(conta); 
            }
            else if (opc.equals("sacar")) {
                String valorStr = entrada.nextLine().trim();
                System.out.println("$" + valorStr);
                double valor = Double.parseDouble(valorStr);
                conta.sacar(valor);
                // Exibe o estado da conta após a operação para verificação do teste
                System.out.println(conta); 
            }
            else if (opc.equals("end") || opc.equals("sair")) {
                System.out.println("$end");
                break;
            }
            else {
                System.out.println("comando invalido");
            }
        }
        entrada.close();
    }
}