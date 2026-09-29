public class Lampada{
    boolean estado;
    int contador;
    
    public Lampada(){
        
    }
    
    public Lampada(boolean estado, int contador){
        this.estado = false;
        this.contador = 0;
    }
    
    public void mudarEstado(){
        if (this.estado){
            this.estado = false;
        } else{
            this.estado = true;
            this.contador += 1;
        }
    }
    
}