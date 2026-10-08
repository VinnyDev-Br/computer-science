public class Retangulo extends Figura implements Desenhavel{
    double largura;
    double altura;
    
    public Retangulo(double largura,double altura,String nome){
        super(nome);
        this.largura = largura;
        this.altura = altura;
    }
    
    public double calcularArea(){
        return this.largura * this.altura;
    }
    
    public double calcularPerimetro(){
        return 2*(this.altura + this.largura);
    }
    
    public String desenhar(){
        return "Renderizando retângulo "+this.cor+" de " + this.largura + "x" +this.altura+".";
    }
    
}