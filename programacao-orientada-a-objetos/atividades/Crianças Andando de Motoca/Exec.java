import java.util.*;

public class Exec {

    // Inicializa o scanner de forma estática
    static Scanner scanner = new Scanner(System.in);
    

    public static void main(String[] args) {
        // CRIE SUA MOTO AQUI
        Motoca motoca = new Motoca();

        while (true) {
            var line = scanner.nextLine();
            System.out.println("$" + line);

            var par = line.split(" ");
            var cmd = par[0];

            if (cmd.equals("end")) {
                break;
            } else if (cmd.equals("init")) {
                int power = par.length > 1 ? Integer.parseInt(par[1]) : 1;
                // CRIE SUA MOTO AQUI passando a potência recebida em power
                motoca = new Motoca(power);
            } else if (cmd.equals("show")) {
                // MOSTRE SUA MOTO AQUI - use o método toString
                System.out.println(motoca.toString());
            } else if (cmd.equals("enter")) {
                // $enter name age
                var name = par[1];
                var age = Integer.parseInt(par[2]);
                
                // CRIE UM OBJETO PESSOA AQUI
                Pessoa pessoa = new Pessoa(age, name);
                 // DEPOIS INSIRA NA MOTO
                motoca.inserir(pessoa);
            } else if (cmd.equals("leave")) {
                // RETIRE A PESSOA DA MOTO
                 Pessoa p = motoca.remover();
                if (p != null) { 
                    // Imprime a Pessoa removida (ex: heitor:6)
                    System.out.println(p.toString());
                    
                    // MOSTRE A PESSOA RETIRADA AQUI  - use o método toString 
                }
            } else if (cmd.equals("buy")) {
                // $buy time
                var time = Integer.parseInt(par[1]);
                // COMPRE TEMPO
                motoca.buyTime(time);
            } else if (cmd.equals("drive")) {
                // $drive time
                var time = Integer.parseInt(par[1]);
                // DIRIJA A MOTO
                motoca.drive(time);
            } else if (cmd.equals("honk")) {
                // $honk
                // BUZINE a moto
                motoca.honk();
            } else {
                System.out.println("fail: comando invalido");
            }
        }
    }
}