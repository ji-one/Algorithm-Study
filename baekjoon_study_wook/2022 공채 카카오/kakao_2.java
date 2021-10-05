public class kakao_2 {
    class Solution {
        public int solution(int n, int k) {
            int answer = 0;
            String n2k = Integer.toString(n, k);
    
    
            String prime = "";
            for(int i=0; i<n2k.length(); i++) {
                char num = n2k.charAt(i);
                if(num == '0') {
                    if(isPrime(prime)) {
                        answer++;
                    }
                    prime = "";
                } else {
                    prime += num;
                }
            }
            if(isPrime(prime)) {
                answer++;
            }
            return answer;
        }
    
        private boolean isPrime(String num) {
            if(num.equals("") || num.equals("1") ) return false;
    
            long n = Long.parseLong(num);
    
            for(int i=2; i<=Math.sqrt(n); i++) {
                if(n%i == 0) {
                    return false;
                }
            }
            return true;
        }
    }
}
