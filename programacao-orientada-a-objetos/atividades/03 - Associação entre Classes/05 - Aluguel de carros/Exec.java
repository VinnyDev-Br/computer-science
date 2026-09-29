import java.util.Scanner;

public class Exec {
    public static void main(String args[]) {
        Scanner entrada = new Scanner(System.in);
        Carro carro = null; 

        while (entrada.hasNextLine()) {
            String line = entrada.nextLine().trim();
            if (line.isEmpty()) continue;
            
            String[] par = line.split(" ");
            String cmd = par[0];

            System.out.println(line);

            if (cmd.equals("$criar_carro")) {
                // $criar_carro PLACA
                String placa = par[1];
                carro = new Carro(placa);
            }
            else if (carro == null) {
                System.out.println("fail: carro nao criado");
            }
            else if (cmd.equals("$alugar")) {
                // $alugar NOME IDADE
                String nome = par[1];
                int idade = Integer.parseInt(par[2]);
                Pessoa pessoa = new Pessoa(nome, idade);
                
                boolean sucesso = carro.alugar(pessoa);
                System.out.println(sucesso ? "aluguel: ok" : "aluguel: falha");
            }
            else if (cmd.equals("$devolver")) {
                // $devolver
                boolean sucesso = carro.devolver();
                System.out.println(sucesso ? "devolucao: ok" : "devolucao: falha");
            }
            else if (cmd.equals("$show")) {
                System.out.println(carro);
            }
            else if (cmd.equals("$total_alugados")) {
                // Deve chamar o método estático
                System.out.println("Total: " + Locadora.getTotalAlugados());
            }
            else if (cmd.equals("$end")) {
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