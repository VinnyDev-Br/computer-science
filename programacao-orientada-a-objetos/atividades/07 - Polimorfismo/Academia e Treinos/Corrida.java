public class Corrida extends Treino{
    double distanciaKm;
    
    public Corrida(int dM, double distanciaKm){
        super(dM);
        this.distanciaKm = distanciaKm;
    }
    
    @Override
    public int calcularCaloriasQueimadas(){
        return (int)(this.distanciaKm * 50);
    }
}