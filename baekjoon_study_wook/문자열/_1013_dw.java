package 문자열;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.regex.Pattern;

public class _1013_dw {
    public static void main(String[] args) throws NumberFormatException, IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
        int n = Integer.parseInt(br.readLine());

		String pattern = "(100+1+|01)+";
        for(int i=0; i<n; i++) {
            String spread = br.readLine();
            if(Pattern.matches(pattern, spread)) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
	}   
}