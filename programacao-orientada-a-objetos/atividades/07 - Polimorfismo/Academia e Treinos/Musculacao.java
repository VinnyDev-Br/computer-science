public class Musculacao extends Treino{
    
    double pesoTotalLevantado;

    public Musculacao(int dM, double pesoTotalLevantado){
        super(dM);
        this.pesoTotalLevantado = pesoTotalLevantado;
    }
    
    @Override
    public int calcularCaloriasQueimadas(){
        return (int)(this.pesoTotalLevantado/10);
    }
}