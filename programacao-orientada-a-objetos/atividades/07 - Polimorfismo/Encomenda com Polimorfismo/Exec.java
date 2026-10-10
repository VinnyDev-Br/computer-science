import java.util.Scanner;

public class Exec {

    public static Encomenda criarEncomenda(int opc, Scanner entrada) {
        switch (opc) {
            case 1: {
                String codigo = entrada.next();
                double peso = entrada.nextDouble();
                boolean urgente = entrada.nextBoolean();
                return new Carta(codigo, peso, urgente);
            }
            case 2: {
                String codigo = entrada.next();
                double peso = entrada.nextDouble();
                double largura = entrada.nextDouble();
                double altura = entrada.nextDouble();
                double profundidade = entrada.nextDouble();
                return new Pacote(codigo, peso, largura, altura, profundidade);
            }
            default:
                return null;
        }
    }

    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in);

        int opc = entrada.nextInt();
        Encomenda e = criarEncomenda(opc, entrada);

        if (e != null) {
            double custoFinal = e.calcularCustoEnvio();
            System.out.println(e.toString());
            System.out.println("Custo de Envio: " + custoFinal);
        }

        entrada.close();
    }
}