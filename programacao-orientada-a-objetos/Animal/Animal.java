public class Animal{
    String species;
    int age;
    String noise;
    
    public Animal(String species, String noise){
        this.species = species;
        this.noise = noise;
        this.age = 0;
    }
    
    public String toString(){
        return this.species + " " + this.age + " " + this.noise;
    }
    
    public void ageBy(int value){
        if ((this.age + value) >= 4){
            System.out.println("warning: " + this.species + " morreu");
            this.age = 4;
        }
        else
            this.age += value;
        
    }
    
    
    public String makeNoise(){
        switch (this.age){
            case 0:
                return "---";
            case 4:
                return "RIP";  
            default:
                return this.noise;
        }
    }
}