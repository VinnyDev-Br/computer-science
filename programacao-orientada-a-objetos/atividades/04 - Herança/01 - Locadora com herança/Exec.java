public class Exec {
    public static void main(String args[]) {
        // Cria a locadora com 3 slots nulos
        Locadora manager = new Locadora(); 

        // Dados a serem usados no aluguel
        String nome_jovem = "Ana"; int idade_jovem = 17;
        String nome_ok = "Beto"; int idade_ok = 30;
        String nome_idoso = "Celso"; int idade_idoso = 55;

        System.out.println("--- INICIAL ---");
        manager.listarVeiculos();
        System.out.println("Total Alugados: " + manager.contarAlugados());

        System.out.println("\n--- CADASTRO E LIMITE ---");
        // Cadastra 3 veículos (deve ocupar os 3 slots)
        System.out.println("Cadastrar C1 (SED-1111): " + manager.cadastrarVeiculo(new Carro("SED-1111")));
        System.out.println("Cadastrar C2 (HET-2222): " + manager.cadastrarVeiculo(new Carro("HET-2222")));
        System.out.println("Cadastrar M1 (JET-3333): " + manager.cadastrarVeiculo(new Moto("JET-3333")));
        
        // Tenta cadastrar o 4º veículo (deve falhar)
        System.out.println("Cadastrar M2 (JET-4444): " + manager.cadastrarVeiculo(new Moto("JET-4444")));
        manager.listarVeiculos();

        System.out.println("\n--- TESTE ALUGUEL MOTO (JET-3333) ---");
        System.out.println("Alugar Celso (55): " + manager.alugarVeiculo("JET-3333", nome_idoso, idade_idoso)); // Falha moto (50)
        System.out.println("Alugar Beto (30): " + manager.alugarVeiculo("JET-3333", nome_ok, idade_ok)); // Sucesso

        System.out.println("\n--- TESTE DEVOLUCAO ---");
        boolean dev_c1 = manager.devolverVeiculo("SED-1111"); 
        System.out.println("devolucao: " + dev_c1); 

       
        boolean dev_m1 = manager.devolverVeiculo("JET-3333");
        System.out.println("devolucao: " + dev_m1); 

        
        manager.listarVeiculos(); 
        System.out.println("Total Alugados: " + manager.contarAlugados());
    }
}