public class Pessoa{
    String nome;
    String endereco;
    int idade;
    String cpf;
    char sexo;
    
    public Pessoa(String nome, String endereco, int idade, String cpf, char sexo){
        this.nome = nome;
        this.endereco = endereco;
        this.idade = idade;
        this.cpf = cpf;
        this.sexo = sexo;
    }
    
    public String andar(){
        return "Pessoa " + this.nome +  " está andando.";
    }
    
    public String imprimirValores(){
        return "Pessoa: " + this.nome + ", Idade: " + this.idade + ", CPF: " + this.cpf;
    }
}   