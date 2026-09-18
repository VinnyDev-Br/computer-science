public class EmpresaParticipante{
    String nome;
    String cidade;
    Produto p1 = new Produto();
    Produto p2 = new Produto();
    Produto p3 = new Produto();
    
    public EmpresaParticipante(){
        
    }
    
    public EmpresaParticipante(String nome, String cidade, Produto p1, Produto p2, Produto p3){
        this.nome = nome;
        this.cidade = cidade;
        this.p1 = p1;
        this.p2 = p2;
        this.p3 = p3;
}
    
    public String toString(){
        return nome + "\n" + cidade;
    }
}