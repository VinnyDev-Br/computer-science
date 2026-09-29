public class Toalha{
    String cor;
    String tamanho;
    int umidade;
    
    public Toalha(){
        
    }
    
    public Toalha(String cor, String tamanho){
        this.cor = cor;
        this.tamanho = tamanho;
        this.umidade = 0;
    }
    
    public void mostrar(){
        System.out.println(this.cor + " " + this.tamanho + " " + this.umidade);
    }
    
    public void enxugar(int value){
        if((this.umidade + value) > getMaxUmidade()){
            this.umidade = getMaxUmidade();
            return;
        }
        this.umidade += value;
    }
    
    public void torcer(){
        this.umidade = 0;
    }
    
    public int getMaxUmidade(){
        switch (this.tamanho){
            case "P":
                return 10;
            case "M":
                return 20;
            case "G":
                return 30;
        }
        return 0;
    }
    
    public boolean esta_seco(){
        if (this.umidade == 0){
            return true;
        }
        
        return false;
    }
    
}