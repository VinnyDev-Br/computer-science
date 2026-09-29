public class Exec{
    public static void main(String args[]){

        RoboSimples total = new RoboSimples("Total"); 
        RoboSimples chico = new RoboSimples("Chico");
        RoboSimples semNome = new RoboSimples();

        total = new RoboSimples("Total", 20, 10, 'S'); 

        total.mover(10); 

        chico.mover(5);         
        chico.mudarDirecao('L'); 
        chico.mover();          

        // ALUNO, COMPLEMENTE O CÓDIGO AQUI: MANIPULE O ROBÔ SEM NOME FAZENDO-O MOVER, MUDAR DE DIREÇÃO PARA O, MOVER 8 POSIÇÕES
        semNome.mover();
        semNome.mudarDirecao('O');
        semNome.mover(8);
        
        System.out.println(total);
        System.out.println(chico);
        System.out.println(semNome);
    }
}