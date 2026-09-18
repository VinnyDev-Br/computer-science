import java.util.Scanner;

public class Exec {
    public static void main(String args[]) {
        Scanner entrada = new Scanner(System.in);
        ContaBancaria conta = null; 
        String opc = "";

        String nome = entrada.nextLine();
        String cpf = entrada.nextLine();
        
        String saldoStr = entrada.nextLine();
        double saldo = Double.parseDouble(saldoStr);
        String especialStr = entrada.nextLine();
        
        boolean ehEspecial = false;
        if(especialStr.equals("S"))
            ehEspecial = true;
        
        Correntista correntista = new Correntista(nome, cpf);
                
        // Usa o objeto correntista no construtor da ContaBancaria
        conta = new ContaBancaria(correntista, saldo, ehEspecial);
        
        String valorStr = entrada.nextLine();
        
        double valor = Double.parseDouble(valorStr);
        conta.depositar(valor);
        System.out.println(conta); 
        
        valorStr = entrada.nextLine();
        valor = Double.parseDouble(valorStr);
        conta.sacar(valor);
        System.out.println(conta); 
        
        entrada.close();
    }
}