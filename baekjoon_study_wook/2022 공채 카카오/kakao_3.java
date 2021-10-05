import java.util.*;

class Solution {
    // 기본 시간(분)  기본 요금(원)  단위 시간(분)  단위 요금(원)
    public int[] solution(int[] fees, String[] records) {

        Map<Integer, Integer> in = new HashMap<>();     // 입차 시간
        Map<Integer, Integer> total = new TreeMap<>();   // 차번호 당 총시간

        for(String record : records) {
            String[] spl = record.split(" ");
            int time = str2int(spl[0]);
            int carNum = Integer.parseInt(spl[1]);
            String state = spl[2];

            if(state.equals("IN")) {
                in.put(carNum, time);
            } else {
                int t = time - in.get(carNum);
                total.put(carNum, total.getOrDefault(carNum, 0) + t);
                in.remove(carNum);
            }
        }

        // 23:59 에 출차
        for(int carNum : in.keySet()) {
            int t = str2int("23:59") - in.get(carNum);
            total.put(carNum, total.getOrDefault(carNum, 0) + t);
        }

        int[] answer = new int[total.size()];
        int idx = 0;
        for(int carNum : total.keySet()) {
            answer[idx] = fees[1];
            if(total.get(carNum) > fees[0]) {
                answer[idx] += Math.ceil((double)(total.get(carNum)-fees[0])/fees[2]) * fees[3];
            }
            idx++;
            // System.out.println(carNum + " " + total.get(carNum));
        }
        return answer;
    }

    private int str2int(String time) {
        String[] spl = time.split(":");
        int hour = Integer.parseInt(spl[0])*60;
        int minute = Integer.parseInt(spl[1]);
        return hour + minute;
    } 
}