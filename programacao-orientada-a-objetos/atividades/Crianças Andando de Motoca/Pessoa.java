public class Pessoa{
    int age; 
    String name;
    
    public Pessoa(){
        
    }
    
    public Pessoa(int age, String name){
        this.age = age;
        this.name = name;
    }
    
    public int getAge(){
        return this.age;
    }
    
    public String getName(){
        return this.name;
    }
    
    public String toString(){
        return this.name + ":" + this.age;
    }
}