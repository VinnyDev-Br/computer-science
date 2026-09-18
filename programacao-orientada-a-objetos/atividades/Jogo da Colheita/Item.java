public class Item{
    String nomeItem;
    int valorVenda;
    
    public Item(){
        
    }
    
    public Item(String nomeItem, int valorVenda){
        this.nomeItem = nomeItem;
        this.valorVenda = valorVenda;
    }
    
    
    public String getNome(){
        return this.nomeItem;
    }
    
    public int getValorVenda(){
        return this.valorVenda;
    }
    
    public String toString(){
        return (this.nomeItem == null) ? "empty" : this.nomeItem + ":" + this.valorVenda;
    }
}