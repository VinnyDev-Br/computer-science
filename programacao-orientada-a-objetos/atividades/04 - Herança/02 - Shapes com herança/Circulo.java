public class Circulo extends Forma{
    double raio;
    double pi = 3.14159;
    
    public Circulo(double raio){
        super("Círculo:");
        this.raio = raio;
        super.area = getArea();
        super.perimetro = getPerimetro();
    }
    
    public double getArea(){
        return this.raio * this.raio * pi;
    }
    public double getPerimetro(){
        return 2*this.pi*this.raio;
    }

}