class Solution {
    public int superpalindromesInRange(String left, String right) {
        Long l = Long.parseLong(left);
        Long r = Long.parseLong(right);
        int result = 0;
        List<Long> palindromes = new ArrayList<>();
        for(long i = 0; i < 10; i++) {
            palindromes.add(i);
        }
        for(long i = 1; i < 10000; i++) {
            String left_part = Long.toString(i);
            StringBuilder right_part = new StringBuilder(left_part).reverse();
            palindromes.add(Long.parseLong(left_part + right_part));
            for(int j = 0; j < 10; j++) {
                palindromes.add(Long.parseLong(left_part + j + right_part));
            }
        }
        
        for(Long p: palindromes) {
            Long n = p*p;
            if(n >= l && n <= r && isPalindrome(Long.toString(n))) {
                result++;
            }
        }
        return result;
    }
    
    public boolean isPalindrome(String s) {
        int l = 0;
        int r = s.length() - 1;
        while(l < r) {
            if(s.charAt(l) != s.charAt(r))
                return false;
            l++;
            r--;
        }
        return true;
    }
}