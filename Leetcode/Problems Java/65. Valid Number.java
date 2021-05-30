class Solution {
    public boolean isNumber(String s) {
        boolean isDigit = false, isDot = false, isE = false;
        int plusMinusCount = 0;
        for(int i=0;i<s.length();i++){
            char ch = s.charAt(i);
            
            if(Character.isDigit(ch)){
                isDigit = true;
            }
            else if(ch == '+' || ch == '-'){
                if(plusMinusCount == 2 ){
                    return false;
                }
                else if(i>0 && (s.charAt(i-1)!='e' && s.charAt(i-1)!='E')){
                    return false;
                }
                else if(i == s.length()-1){
                    return false;
                }
                plusMinusCount+=1;
            }
            else if(ch == '.'){
                if(i == s.length()-1 && !isDigit){
                    return false;
                }
                else if(isDot || isE){
                    return false;
                }
                isDot = true;
            }
            else if(ch == 'e' || ch=='E'){
                if(isE || !isDigit || i == s.length()-1){
                    return false;
                }
                isE = true;
            }
            else {
                return false;
            }
        }
        return true;
    }
}


import java.util.regex.*;
class Solution {
    public boolean isNumber(String s) {
        String regex = "^[+-]?(((\\d+\\.\\d*)|(\\.\\d+))|(\\d+))([eE][+-]?\\d+)?$";
        return Pattern.matches(regex,s);
    }
}