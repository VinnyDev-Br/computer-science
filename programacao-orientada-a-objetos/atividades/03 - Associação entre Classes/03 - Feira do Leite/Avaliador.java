public class Avaliador{
    String nome;
    String experiencia;
    
    public Avaliador(){
        
    } 
    
    public Avaliador(String nome, String experiencia){
        this.nome = nome;
        this.experiencia = experiencia;
    }
    
    public String toString(){
        return nome + "\n" + experiencia;
    }
}