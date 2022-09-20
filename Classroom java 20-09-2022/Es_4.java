/*
	Stampare a video la seguente figura:
	******
	*****
	****
	***
	**
	*
*/

public class Es_4 {

	public static void main(String[] args) {
		for(int i = 6; i > 0; i--) {
			for(int j = i; j > 0; j--) {
				System.out.print("*");
			}
			System.out.println();
		}
	}

}
