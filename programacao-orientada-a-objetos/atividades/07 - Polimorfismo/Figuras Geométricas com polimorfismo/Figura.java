public abstract class Figura{
    String cor;
    
    public Figura(String cor){
        this.cor = cor;
    }
    
    public abstract double calcularArea();
    
    public abstract double calcularPerimetro();
    
    public String apresentarDados(){
        return "A figura "+this.cor+" tem área "+calcularArea()+" e perímetro "+calcularPerimetro()+".";
    }
}