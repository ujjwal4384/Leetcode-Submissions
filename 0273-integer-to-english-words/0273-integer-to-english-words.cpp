class Solution {
    vector<string> below_20 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

    vector<string> tens = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    
    vector<string> thousands = {"", "Thousand", "Million", "Billion"};

//builds 1 to 999 number
string helper (int num){
    if(num == 0) return "";
    else if(num < 20) return below_20[num] + " ";
    else if(num < 100) return tens[num/10] + " " + helper(num%10);
    else return below_20[num/100] +  " Hundred " + helper(num%100);
    return "";
}
public:
//english words are processed in chunks of three. divide and conquer.
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        int i =0;
        string result = "";
        while(num > 0) {
               if(num%1000 > 0){
                //Helper already provides the space, so just append the thousand suffix + one space
                   result = helper(num%1000) + thousands[i] + " " + result ;
               }
               num /= 1000;
               i++;
        }
        while (result.size() >0 && result.back() == ' ') {
            result.pop_back();
        }
       return result; 
    }
};