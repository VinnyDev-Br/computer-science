public class Retangulo extends Forma    {
    double altura;
    double largura;
    
    public Retangulo(double altura, double largura){
        super("Retângulo:");
        this.altura = altura;
        this.largura = largura;
        super.area = calculaArea();
        super.perimetro = calculaPerimetro();
    }
    
    public double calculaArea(){
        return this.largura * this.altura;
    }
    
    public double calculaPerimetro(){
        return 2*(this.altura + this.largura);
    }
    
}