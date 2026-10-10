import java.text.DecimalFormat;
import java.math.RoundingMode;

public class Exec {
    public static void main(String args[]) {
        // --- SETUP ---
        final String DATA_VENDA = "2025-11-24";
        
         //Defina um vetor do tipo venda chamado carrinho, de tamanho 3.
        Venda[] carrinho = new Venda[3];
        // 2. Criação Polimórfica: Carrega o carrinho com diferentes tipos de venda
        carrinho[0] = new VendaLocal(100.00, DATA_VENDA);       // Venda Local (100 * 1.05 = 105.0)
        carrinho[1] = new VendaInternacional(80.00, DATA_VENDA); // Venda Internacional (80 * 0.25 = 20.0)
        carrinho[2] = new VendaLocal(50.00, DATA_VENDA);        // Venda Local (50 * 1.05 = 52.5)

        // --- FORMATADOR (Mantido do seu código original) ---
        DecimalFormat df = new DecimalFormat("#.##"); 
        df.setRoundingMode(RoundingMode.UP); // Modo de arredondamento

        System.out.println("--- CARRINHO DE COMPRAS ---");
        // Implemente o laço para percorrer o vetor fazendo chamadas polimórficas ao método calcularValorFinal. 
        //Imprima o valor de cada chamada polimórfica e guarde a soma dos resultados em um atributo chamado totalGeral
        int i = 0;
        double totalGeral = 0.0;
        
        do {
            System.out.println("Item " + (i+1) +": "+df.format(carrinho[i].calcularValorFinal()));
            totalGeral += carrinho[i].calcularValorFinal();
            i++;
        } while (i < 3);
        
        // O código abaixo deve ficar fora do laço
        System.out.println("--------------------");
        System.out.println("Total Geral Bruto: " + df.format(totalGeral));
    }
}