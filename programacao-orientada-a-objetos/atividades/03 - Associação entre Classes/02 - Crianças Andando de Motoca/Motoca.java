public class Motoca{
    int potencia;
    int time;
    Pessoa pessoa;
    
    
    public Motoca(int potencia){
        this.potencia = potencia;
    }

    
    public Motoca(){
        this.potencia = 1;
        this.time = 0;
        this.pessoa = null;
    }
    
    public boolean inserir(Pessoa pessoa){
        if (this.pessoa != null){
            System.out.println("fail: busy motorcycle");
            return false;
        }
        
        this.pessoa = pessoa;
        
        return true;
    }
    
    public String toString(){
        return "power:" + this.potencia + ", time:" + this.time + ", person:" + ((this.pessoa != null) ? "(" + this.pessoa.toString() + ")": "(empty)");
    }
    
    public Pessoa remover(){
        
        Pessoa p = this.pessoa;
        
        if (this.pessoa == null){
            System.out.println("fail: empty motorcycle");
            return null;
        }
        
        this.pessoa = null;
        return p;
        
    }
    
    public void buyTime(int time){
        this.time += time;
    }
    
    public void drive(int time){
        if (this.time == 0)
            System.out.println("fail: buy time first");
        
        else if (this.pessoa == null)
            System.out.println("fail: empty motorcycle");
        
        else if (this.pessoa.age > 10)
            System.out.println("fail: too old to drive");
        
        else if (this.time - time <= 0){
            System.out.println("fail: time finished after " + Math.abs(this.time - time) + " minutes");
            this.time = 0;}
        else{
            this.time -= time;
        }
    }
    
    public void honk(){
        String buzina = "";
        
        buzina += "P";
        
        for (int i = 0; i < this.potencia; i++){
            buzina += "e";
        }
        
        buzina += "m";
        
        System.out.println(buzina);
    }
}