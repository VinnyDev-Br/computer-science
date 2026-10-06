public class Exec {
    
    public static void main(String args[]) {
        final double PRECO_ATUAL = 10.0;
        
        // Criação das instâncias
        Madeira carvalho = new Madeira("Tronco", 10.0, "Carvalho");
        Metal cobre = new Metal("Minério", 5.0, 90);
        
        System.out.println("--- ESTRUTURA E HERANCA ---");
        carvalho.inspecionar();
        cobre.inspecionar();
        
        System.out.println("\n--- TESTE PROCESSAMENTO ---");
        // Teste da lógica de processamento (Método Abstrato)
        System.out.println("Valor Madeira: " + carvalho.processarRecurso(PRECO_ATUAL));
        System.out.println("Valor Metal: " + cobre.processarRecurso(PRECO_ATUAL));
        
        System.out.println("\n--- TESTE INTERFACE ---");
        
        // TESTE DA MADEIRA (É Combustível)
        if (carvalho instanceof Combustivel) {
            Combustivel combustivelMadeira = (Combustivel) carvalho;
            System.out.println("Madeira queima: " + combustivelMadeira.queimar());
        } else {
            System.out.println("Madeira queima: Falha: O item não é um combustível.");
        }
        
        // TESTE DO METAL (NÃO é Combustível)
        if (cobre instanceof Combustivel) {
            Combustivel combustivelMetal = (Combustivel) cobre;
            System.out.println("Metal queima: " + combustivelMetal.queimar());
        } else {
            System.out.println("Metal queima: Falha: O item não é um combustível.");
        }
    }
}