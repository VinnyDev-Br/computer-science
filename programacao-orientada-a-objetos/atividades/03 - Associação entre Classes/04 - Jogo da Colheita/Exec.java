import java.util.Scanner;

public class Exec {
    public static void main(String args[]) {
        Scanner entrada = new Scanner(System.in);
        Fazendeiro fazendeiro = null; 

        while (entrada.hasNextLine()) {
            String line = entrada.nextLine().trim();
            if (line.isEmpty()) continue;
            
            String[] par = line.split(" ");
            String cmd = par[0];

            System.out.println(line);

            if (cmd.equals("$criar")) {
                
                String nome = par[1];
                //INSTANCIE O FAZENDEIRO AQUI E ATRIBUA A REFERÊNCIA fazendeiro
                fazendeiro = new Fazendeiro(nome);
            }
            else if (fazendeiro == null) {
                System.out.println("fail: fazendeiro nao criado");
            }
            else if (cmd.equals("$show")) {
                System.out.println(fazendeiro.toString());
            }
            else if (cmd.equals("$colher")) {
                
                String nomeItem = par[1];
                int valor = Integer.parseInt(par[2]);
                // INSTANCIE UM ITEM PASSANDO NOMEITEM E VALOR PARA ELE. CHAME A REFERÊNCIA DE item 
                Item item = new Item(nomeItem, valor);
                boolean sucesso = fazendeiro.colher(item);
                System.out.println(sucesso ? "colheita: ok" : "colheita: inventario cheio");
            }
            else if (cmd.equals("$vender")) {
                
                String nomeItem = par[1];
                boolean sucesso = fazendeiro.vender(nomeItem);//COMPLEMENTE ESTA LINHA FAZENDO UMA CHAMADA A VENDER, PASSANDO NOMEITEM
                System.out.println(sucesso ? "venda: ok" : "venda: item nao encontrado");
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