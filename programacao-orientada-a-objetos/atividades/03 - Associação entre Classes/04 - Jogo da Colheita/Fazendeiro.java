public class Fazendeiro{
    String nome;
    int dinheiro;
    Item item1;
    Item item2;
    Item item3;

    
    public Fazendeiro(){
        
    }
    
    public Fazendeiro(String nome){
        this.nome = nome;
        this.dinheiro = 100;
        this.item1 = null;
        this.item2 = null;
        this.item3 = null;
        
    }
    
    public boolean colher(Item item){
        if (item1 == null){
            item1 = item;
            return true;
        }
        else if (item2 == null){
            item2 = item;
            return true;
        }
        else if (item3 == null){
            item3 = item;
            return true;
        }
        else
            return false;
    }
    
    public boolean vender(String nomeItem){
        if (item1 != null && item1.nomeItem.equals(nomeItem)){
            this.dinheiro += item1.valorVenda;
            item1 = null;
            return true;
        }
        else if (item2 != null && item2.nomeItem.equals(nomeItem)){
            this.dinheiro += item2.valorVenda;
            item2 = null;            
            return true;
        }
        else if (item3 != null && item3.nomeItem.equals(nomeItem)){
            this.dinheiro += item3.valorVenda;
            item3 = null;            
            return true;
        }
        else{
            return false;
        }
    }
    
    public String toString(){
        String s1 = (item1 == null) ? "empty" : item1.toString();
        String s2 = (item2 == null) ? "empty" : item2.toString();
        String s3 = (item3 == null) ? "empty" : item3.toString();

        return "Nome: " + this.nome + ", Dinheiro: " + this.dinheiro + ", Inventario: [" + s1 + ", " + s2 + ", " + s3 + "]";
    }
}