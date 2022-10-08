import java.util.*;

class TVPair implements Comparable<TVPair> {
    int timestamp;
    String value;

    TVPair(int timestamp, String value) {
        this.timestamp = timestamp;
        this.value = value;
    }

    @Override
    public int compareTo(TVPair o) {
        return this.timestamp - o.timestamp;
    }

    @Override
    public String toString() {
        return "{" +
                "timestamp=" + timestamp +
                ", value='" + value + '\'' +
                '}';
    }
}

class TimeMap {

    Map<String, List<TVPair>> map;

    public TimeMap() {
        map = new HashMap<>();
    }

    private TVPair getPair(String key, int timestamp) {
        List<TVPair> tvPairs = map.get(key);
        TVPair last = new TVPair(-1, "");
        int l = 0;
        int r = tvPairs.size() - 1;
        while (l <= r) {
            int m = (r - l) / 2 + l;
            TVPair curr = tvPairs.get(m);
            int curTimestamp = curr.timestamp;
            if (curTimestamp == timestamp) {
                return tvPairs.get(m);
            } else if (curTimestamp < timestamp) {
                last = last.timestamp < curTimestamp ? curr : last;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return last;
    }

    public void set(String key, String value, int timestamp) {
        if(!map.containsKey(key))
            map.put(key, new ArrayList<>());

            map.get(key).add(new TVPair(timestamp, value));
    }

    public String get(String key, int timestamp) {
        if (!map.containsKey(key) || map.get(key).get(0).timestamp>timestamp)
            return "";
        return getPair(key, timestamp).value;
    }
}

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap obj = new TimeMap();
 * obj.set(key,value,timestamp);
 * String param_2 = obj.get(key,timestamp);
 */
