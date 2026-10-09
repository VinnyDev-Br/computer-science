public class Metal extends Recurso {
    double pureza;
    
    public Metal(String nome, double peso, double pureza){
        super(nome,peso);
        this.pureza = pureza;
    }
    
    public double processarRecurso(double precoMercado){
        return this.peso * (this.pureza/100) * precoMercado;
    }
}