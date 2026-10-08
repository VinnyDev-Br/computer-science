import java.text.DecimalFormat;
import java.math.RoundingMode;

public class Exec {
    public static void main(String args[]) {
    //Defina um vetor de figuras chamado figurasde tamanho 3.
    Figura[] figuras = new Figura[3];

    figuras[0] = new Circulo(5.0, "Azul");
    figuras[1] = new Retangulo(4.0, 6.0, "Marrom");
    figuras[2] = new Circulo(6.0, "Prata");
    
    DecimalFormat df = new DecimalFormat("#.##");

    // Define o modo de arredondamento para TRUNCAMENTO (UP)
    df.setRoundingMode(RoundingMode.UP);

    // Implemente o laço para percorrer o vetor fazendo chamadas polimórficas ao método calcularArea, imprimindo o resultado na tela
    for (Figura f : figuras){
        System.out.println(df.format(f.calcularArea()));
    }    
    // utilize df.format(); - Para formatar a saída. O método recebe o resultado de calculararea e devolve o número com duas casas formatado como string.

    }
}

