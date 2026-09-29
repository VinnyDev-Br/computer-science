public class Forma{
    String nome;
    double area;
    double perimetro;
    
    public Forma(String nome){
        this.nome = nome;
    }
    
    public String toString(){
        return this.nome + " A=" + this.area + ", P=" + this.perimetro;
        
    }
}