public class Correntista{
    private String nome;
    private String cpf;
    
    public Correntista(){
        
    }
    
    public Correntista(String nome, String cpf){
        this.nome = nome;
        this.cpf = cpf;
    }
    
    public String getNome(){
        return this.nome;
    }
    
    public void setCpf(){
        this.cpf = cpf.replaceAll("[^0-9]", "");
    }
    
    public String getCpf(){
        return this.cpf;
    }
}