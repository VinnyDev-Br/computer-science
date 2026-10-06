public class Metal extends Recurso {
    
    double pureza;
    
    public Metal(String nome, double peso, int pureza){
        super(nome, peso);
        this.pureza = pureza;
    }
    
    
    public double processarRecurso(double precoMercado){

        return this.peso*(this.pureza/100)*precoMercado;
    }
}