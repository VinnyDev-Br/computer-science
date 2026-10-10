public abstract class Treino{
    public int dM;
    static int caloriasBase = 100;
    
    public Treino(int dM){
        this.dM = dM;
    }
    
    public abstract int calcularCaloriasQueimadas();
    
    public int obterTotalCalorias(){
        return caloriasBase + calcularCaloriasQueimadas();
    }
}