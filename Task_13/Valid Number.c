bool isNumber(char *s) {
    bool digit = false, eE = false, sign = false, dot = false;

    for (int i = 0; i < strlen(s); i++) {
        char arr = s[i];

        /* is digit */
        if (arr >= '0' && arr <= '9') {
            digit = true;
        /* check for eE */
        }
        else if (arr == 'e' || arr == 'E') {
            if (eE || !digit ) {
                return false;
            } 
            else {
                eE = true, sign = false, digit = false, dot = false;
            }
        /* check for sign */    
        } 
        else if (arr == '+' || arr == '-') {
            if (sign || digit || dot) {
                return false;
            } else {
                sign = true;
            }
        }
        /* check for dot */
        else if (arr == '.') {
            if (dot || eE) {
                return false;
            }
             else {
                dot = true;
            }
        /* something else */ 
        } 
        else {
            return false;
        }
    }

    return digit;    
}