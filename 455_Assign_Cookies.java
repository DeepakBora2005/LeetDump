class Solution {
    public int findContentChildren(int[] g, int[] s) {
        int result = 0;
        Arrays.sort(g);
        Arrays.sort(s);

       for(int i = 0, j = 0; i < g.length && j < s.length; j++) {
            if(g[i] <= s[j]) {
                result++;
                i++;
            }
       }
       
       return result;
    }
}