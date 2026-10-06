import java.text.DecimalFormat;
import java.text.DecimalFormatSymbols;
import java.util.Locale;

public class Circulo extends Figura implements Desenhavel {
    double raio;
    double PI = 3.14159;

    public Circulo(double raio, String cor) {
        super(cor);
        this.raio = raio;
    }

    @Override
    public double calcularArea() {
        return PI * raio * raio;
    }

    @Override
    public double calcularPerimetro() {
        return 2 * PI * raio;
    }

    @Override
    public String desenhar() {
        return "Renderizando círculo " + this.cor + " de raio " + this.raio + ".";
    }

    @Override
    public String apresentarDados() {
        return "A figura " + this.cor + " tem área " + calcularArea()
             + " e perímetro " + calcularPerimetro() + ".";
    }
}