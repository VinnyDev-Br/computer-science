import java.util.Scanner;

public class Exec {

    public static void main(String[] _args) {
       //Crie um objeto chamado animal a partir da classe Animal
        Animal animal  = new  Animal();
        //Crie uma classe um objeto de leitura de dados chamado entrada a partir da classe Scanner
        Scanner entrada = new Scanner(System.in);
        animal.especie = entrada.nextLine();
        animal.barulho = entrada.nextLine();
        
        
        //Faça uma chamada ao método fazerBarulho de animal
        animal.fazerbarulho();
        //Faça uma chamada ao método envelhecer
        animal.envelhecer();
        //Faça uma chamada ao método toString de animal. Lembre-se de colcar o comando de impressão de dados na tela
        System.out.println(animal.toString());
        //Faça uma chamada ao método envelhecer
        animal.envelhecer();
        //Faça uma chamada ao método toString de animal. Lembre-se de colcar o comando de impressão de dados na tela
        System.out.println(animal.toString());
        //Faça uma chamada ao método morrer
        animal.morrer();
    }
}