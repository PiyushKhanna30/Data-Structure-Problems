class Solution {
    public List<List<String>> findDuplicate(String[] paths) {
        Map<String, List<String>> map = new HashMap<>();
        for (String path : paths) {
            String[] dirFile = path.split(" ");
            String directory = dirFile[0];
            for (int i = 1; i < dirFile.length; i++) {
                int startIdx = dirFile[i].indexOf('(');
                int endIdx = dirFile[i].indexOf(')');
                String content = dirFile[i].substring(startIdx + 1, endIdx);
                String filePath = directory + "/" + dirFile[i].substring(0, startIdx);

                map.putIfAbsent(content, new ArrayList<>());
                map.get(content).add(filePath);
            }
        }
        List<List<String>> result = new ArrayList<>();
        map.values().stream().filter(list -> list.size() > 1).forEach(filterList -> result.add(filterList));
//        System.out.println(result);
        return result;
    }
}
