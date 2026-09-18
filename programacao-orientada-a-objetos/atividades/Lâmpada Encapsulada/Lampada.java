public class Lampada{
    private boolean estado;
    private int contador;
    
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
    
    public int getContador(){
        return this.contador;
    }
    public boolean getEstado(){
        return this.estado;
    }
    
}