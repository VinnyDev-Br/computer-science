import java.util.Scanner;


public class Exec{
   public static Recurso criaRecurso(int i){
           switch(i){
                case 1: 
	               //retorne um objeto do tipo Madeira com os valores "Tronco", 10.0, "Carvalho"
	               return new Madeira("Tronco", 10.0, "Carvalho");
                default:
	               //retorne um objeto do tipo Metal com os valores "Minério", 5.0, 90
	               return new Metal("Minério", 5.0, 90);
            }
   }


    public static void main(String args[]){
          int opc = -1;
          Scanner entrada = new Scanner(System.in);

          opc = entrada.nextInt();

          Recurso r = criaRecurso(opc);
          // complemente esta linha com uma chamada ao cria recurso e o retorno atribuindo a r
          //faça a chamada polimórfica a processar recurso passando o valor 10 como parâmetro.
          System.out.println(r.processarRecurso(10));
    }
}
