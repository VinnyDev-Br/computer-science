public class Produto{
    String nome;
    String tipo;
    String dataValidade;
    int nota;
    
    public Produto(){
        
    }    
    
    public Produto(String nome, String tipo, String dataValidade, int nota){
        this.nome = nome;
        this.tipo = tipo;
        this.dataValidade = dataValidade;
        this.nota = nota;
    }
    
    public String toString(){
        return nome + "\n" + tipo + "\n" + dataValidade + "\n" + nota;
    }
}