package 문자열;
// 2671 잠수함식별

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.regex.Pattern;

public class _2671_dw {
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String sound = br.readLine();
		String pattern = "(100+1+|01)+";
		if(Pattern.matches(pattern, sound)) {
			System.out.println("SUBMARINE");
		} else {
			System.out.println("NOISE");
		}
	}
	
}