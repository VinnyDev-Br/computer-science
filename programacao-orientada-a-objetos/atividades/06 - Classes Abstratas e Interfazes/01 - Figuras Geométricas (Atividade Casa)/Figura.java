public abstract class Figura{
    public String cor;
    
    public Figura(String cor){
        this.cor = cor;
    }
    
    public abstract double calcularArea();
    
    public abstract double calcularPerimetro();
    
    public String apresentarDados(){
        return "A figura " + this.cor + " tem área A e perímetro P.";
    }
}