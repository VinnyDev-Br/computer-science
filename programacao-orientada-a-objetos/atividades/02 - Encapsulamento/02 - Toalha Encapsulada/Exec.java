import java.util.Scanner;

public class Exec {
    public static void main(String args[]) {
        Scanner entrada = new Scanner(System.in);
        
        // CRIE SUA TOALHA AQUI
        String opc = "";
        Toalha t1 = new Toalha();

        while (entrada.hasNextLine()) {
            opc = entrada.nextLine().trim();

            // ecoa o comando
            System.out.println("$" + opc);

            if (opc.equals("criar")) {
                // lê cor e tamanho em linhas separadas
                String cor = entrada.nextLine().trim();
                System.out.println("$" + cor);

                String tamanho = entrada.nextLine().trim();
                System.out.println("$" + tamanho);

                // atribua os valores de cor e tamanho da toalha lidos para o objeto toalha
                t1 = new Toalha(cor, tamanho);
            }
            else if (opc.equals("mostrar")) {
                // MOSTRE SUA TOALHA
                t1.mostrar();
            }
            else if (opc.equals("enxugar")) {
                String qtdStr = entrada.nextLine().trim();
                System.out.println("$" + qtdStr);
                int qtd = Integer.parseInt(qtdStr);
                // ENXUGUE
                t1.enxugar(qtd);
               // MOSTRE SUA TOALHA
               t1.mostrar();
            }
            else if (opc.equals("seca")) {
                // verifique se a toalha está seca ou não (imprima SIM OU NAO)
                if (t1.esta_seco()){
                    System.out.println("SIM");
                }
                else{
                    System.out.println("NAO");
                }
            }
            else if (opc.equals("torcer")) {
                // CHAME O METODO TORCER
                t1.torcer();
                // MOSTRE SUA TOALHA
                t1.mostrar();
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