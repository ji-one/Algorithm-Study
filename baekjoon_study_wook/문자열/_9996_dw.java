package 문자열;

// 9996 한국이 그리울 땐 서버에 접속하지

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.regex.Pattern;

public class _9996_dw {
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		
		String pattern = br.readLine();
		String[] words = new String[n];
		for(int i=0; i<n; i++) {
			words[i] = br.readLine();
		}
		
		pattern = pattern.replace("*", "\\w*");
		for(String word : words) {
			
			if(Pattern.matches(pattern, word)) {
				System.out.println("DA");
			} else {
				System.out.println("NE");
			}
		}
		
	}
	
}