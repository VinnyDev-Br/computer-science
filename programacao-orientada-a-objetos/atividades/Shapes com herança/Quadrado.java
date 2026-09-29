public class Quadrado extends Forma{
    double lado;
    
    public Quadrado(double lado){
        super("Quadrado:");
        this.lado = lado;
        super.area = CalculaArea();
        super.perimetro = calcularPerimetro();        
    }
    
     public double CalculaArea(){
        return this.lado * this.lado;
    }
    
    public double calcularPerimetro(){
        return 4 *this.lado;
    }
}   