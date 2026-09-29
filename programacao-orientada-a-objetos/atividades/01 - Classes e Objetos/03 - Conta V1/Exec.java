import java.util.Scanner;

public class Exec {

    public static void main(String args[]) {
        // Crie um objeto chamado conta a partir da classe Conta
        Conta conta = new Conta();
    
        // Crie um objeto de leitura de dados chamado entrada a partir da classe Scanner
        Scanner entrada = new Scanner(System.in);
        conta.numero = entrada.nextInt();
        entrada.nextLine();
        conta.titular = entrada.nextLine();

        // Faça uma chamada ao método consultar de conta
        conta.consultar();
        // Faça uma chamada ao método depositar
        conta.depositar();
        // Faça uma chamada ao método toString de conta e imprima o resultado
        System.out.println(conta.toString());
        // Faça uma chamada ao método consultar de conta
        conta.consultar();
        // Faça uma chamada ao método depositar
        conta.depositar();
        // Faça uma chamada ao método toString de conta e imprima o resultado
        System.out.println(conta.toString());
        // Faça uma chamada ao método fechar
        conta.fecha();
    }
}