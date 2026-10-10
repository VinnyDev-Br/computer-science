import java.util.Scanner;

public class Exec {
    
    
    public static Treino criaTreino(Scanner entrada, int tipo) {
        
        int duracaoMinutos = entrada.nextInt();
        
        //cria corrida
        if (tipo == 1) { 
            // leia a distância, instancie um objeto do tipo corrida e o retorne
            double distanciaKm = entrada.nextDouble();
            return new Corrida(duracaoMinutos, distanciaKm);
            
        } else if (tipo == 2) { // Cria Musculacao
            // leia o peso levantado, instancie um objeto do tipo Musculacao e o retorne
            double pesoTotalLevantado = entrada.nextDouble();
            return new Musculacao(duracaoMinutos, pesoTotalLevantado);
            
        } else {
            System.out.println("Opção inválida.");
            return null;
        }
    }

    public static void main(String args[]) {
        Scanner entrada = new Scanner(System.in);
        int opc = -1;
        
        // 1. Leitura da opção
        opc = entrada.nextInt();

        Treino t = criaTreino(entrada, opc);

        if (t != null) {
            
            int caloriasQueimadas = t.obterTotalCalorias();// faça a chamada ao método obterTotalCalorias do treino
            
            System.out.println("--- RESULTADO ---");
            System.out.println("Tipo: " + t.getClass().getSimpleName()); 
            System.out.println("Duração: " + t.dM + " minutos"); 
            System.out.println("Total de Calorias: " + caloriasQueimadas);
        }

        entrada.close();
    }
}