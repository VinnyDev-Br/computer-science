public class Retangulo extends Figura implements Desenhavel {
    double largura;
    double altura;

    public Retangulo(double largura, double altura, String cor) {
        super(cor);
        this.largura = largura;
        this.altura = altura;
    }

    @Override
    public double calcularArea() {
        return this.largura * this.altura;
    }

    @Override
    public double calcularPerimetro() {
        return 2 * (this.largura + this.altura);
    }

    @Override
    public String desenhar() {
        return "Renderizando retângulo " + this.cor + " de " + this.largura + "x" + this.altura + ".";
    }

    @Override
    public String apresentarDados() {
        return "A figura " + this.cor + " tem área " + calcularArea()
             + " e perímetro " + calcularPerimetro() + ".";
    }
}