// Scrivere un programma che stampi le tabellina del numero dato come argomento

import java.util.Scanner;

public class Es_3 {

	public static void main(String[] args) {
		System.out.print("Inserisci un numero: ");
		Scanner input = new Scanner(System.in);
		int num = input.nextInt();
		input.close();
		
		for(int i = 1; i <= 10; i++) {
			System.out.println(num + "*" + i + ": " + num*i);
		}
	}

}
