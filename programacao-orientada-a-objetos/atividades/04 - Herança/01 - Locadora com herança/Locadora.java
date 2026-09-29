public class Locadora{
    Veiculo v1;
    Veiculo v2;
    Veiculo v3;
    
    public Locadora(){
        v1 = null;
        v2 = null;
        v3 = null;
    }
    
    public boolean cadastrarVeiculo(Veiculo novoVeiculo){
        if (v1 == null){
            v1 = novoVeiculo;
            return true;
        }
       else if (v2 == null){
            v2 = novoVeiculo;
            return true;
            
        }
       else if (v3 == null){
            v3 = novoVeiculo;
            return true;
        }
        else
            return false;
    }
    

    
    public boolean alugarVeiculo(String placa, String nome, int idade){
        
        if (v1.placa.equals(placa)){
            return v1.alugar(nome, idade);
        }
        else if (v2.placa.equals(placa)){
            return v2.alugar(nome, idade);
        }
        else if (v3.placa.equals(placa)){
            return v3.alugar(nome, idade);
        }
        
        return false;
    }
    
    
    public boolean devolverVeiculo(String placa){
        if (v1.placa.equals(placa)){
            return v1.devolver();
        }
        else if (v2.placa.equals(placa)){
            return v2.devolver();
        }
        else if (v3.placa.equals(placa)){
            return v3.devolver();
        }

        return false;
    }    
    
    public void listarVeiculos(){
        if(v1 == null)
            System.out.println("empty slot");
        else 
            System.out.println(v1.toString());
        
        if(v2 == null)
            System.out.println("empty slot");
        else 
            System.out.println(v2.toString());

        if(v3 == null)
            System.out.println("empty slot");
        else 
            System.out.println(v3.toString());

    }
    
    public int contarAlugados(){
        int total = 0;
        if (v1 != null && !v1.disponivel){ total +=1; }
        if (v2 != null && !v2.disponivel){ total +=1; }
        if (v3 != null && !v3.disponivel){ total +=1; }
        
        return total;

    }
}