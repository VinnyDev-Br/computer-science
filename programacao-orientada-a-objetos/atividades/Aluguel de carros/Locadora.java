public final class Locadora{
    public static int totalCarrosAlugados = 0;
    
    private Locadora(){
        
    }
    
    public static void registrarAluguel(){
        totalCarrosAlugados++;
    }
    
    public static void registrarDevolucao(){
        if (totalCarrosAlugados > 0) 
            totalCarrosAlugados--;
    }
    
    public static int getTotalAlugados() {
        return totalCarrosAlugados;
    }
}