public class Pessoa{
    String nome;
    int idade;
    
    
    public Pessoa(){
        
    }
    
    public Pessoa(String nome, int idade){
        this.nome = nome;
        this.idade = idade;
    }
    
    public String getNome(){
        return this.nome;
    }
    
    public int getIdade(){
        return this.idade;
    }
    
    public String toString(){
        return "(" + this.nome + ":" + this.idade + ")";
    }
}