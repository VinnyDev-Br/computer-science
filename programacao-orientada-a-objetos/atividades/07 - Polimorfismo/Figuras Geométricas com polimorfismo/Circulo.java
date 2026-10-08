public class Circulo extends Figura implements Desenhavel{
    double raio;
    double pi = 3.14159;

    
    public Circulo(double raio,String nome){
        super(nome);
        this.raio = raio;
    }
    
    public double calcularArea(){
        return this.raio * this.raio * pi;
    }
    
    public double calcularPerimetro(){
        return 2*pi*this.raio;
    }
    
    public String desenhar(){
        return "Renderizando círculo "+this.cor+" de raio "+this.raio+".";
    }
    
}