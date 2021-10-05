import java.util.*;

class Solution {
    public int[] solution(String[] id_list, String[] report, int k) {
        int[] answer = new int[id_list.length];
        Map<String, Integer> banCount = new HashMap<>(); // 신고당한 횟수
        Map<String, Integer> reportCount = new LinkedHashMap<>(); // 신고 성공 횟수
        Set<String> check = new HashSet<>();    // 동일 신고처리
        for(String re : report) {
            check.add(re);
        }
        List<String> _report = new ArrayList<>(check);

        for(String id : id_list) {
            reportCount.put(id, 0);
        }

        for(String re : _report) {
            String[] spl = re.split(" ");
            String userId = spl[0];
            String banId = spl[1];
            banCount.put(banId, banCount.getOrDefault(banId , 0) + 1);
        }

        List<String> banList = new ArrayList<>();
        for(String banId : banCount.keySet()) {
            if(banCount.get(banId) >= k) {   // 정지 기준 이상
                banList.add(banId);
            }
        }

        for(String re : _report) {
            String[] spl = re.split(" ");
            String userId = spl[0];
            String banId = spl[1];
            if(banList.contains(banId)) {
                reportCount.put(userId, reportCount.get(userId) + 1);
            }
        }

        int idx=0;
        for(String id : reportCount.keySet()) {
            answer[idx++] = reportCount.get(id);
        }
        return answer;
    }
}