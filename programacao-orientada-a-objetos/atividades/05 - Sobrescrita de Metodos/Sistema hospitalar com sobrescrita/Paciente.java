public class Paciente extends Pessoa{
    String doenca;
    String medicacao;
    
    public Paciente(String nome, String endereco, int idade, String cpf, char sexo, String doenca, String medicacao){
        super(nome, endereco, idade, cpf, sexo);
        this.doenca = doenca;
        this.medicacao = medicacao;
    }
    
    
    public String sentirDor(){
        return "Paciente " + this.nome + " está sentindo dor devido a " + this.doenca + ".";

    }
    
    public String terAlta(){
        return "Paciente " + this.nome + " recebeu alta";
    }    
    
    public String imprimirValores(){
        return super.imprimirValores() + ", Doenca: " + this.doenca + ", Medicacao: " + this.medicacao;
    }
}