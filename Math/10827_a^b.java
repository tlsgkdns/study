import java.util.Scanner;
import java.math.BigDecimal;

public class Main {
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		String a = sc.next();
		int b = sc.nextInt();
		BigDecimal bd = new BigDecimal(a);
		System.out.println(bd.pow(b).toPlainString());
	}
}

// https://www.acmicpc.net/problem/10827