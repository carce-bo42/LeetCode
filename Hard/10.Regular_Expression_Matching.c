/* https://leetcode.com/problems/regular-expression-matching/description/ */

#include <stdbool.h>

bool isMatch(char * s, char * p){

    while (*s != 0 && *p != 0) {

        if ((*p == '.' || *s == *p) && *(p + 1) != '*') {
            s++;
            p++;
            continue;
        }

        // Normal asterisk matching, *s == *p
        if ((*s == *p) && *(p + 1) == '*') {
            char match = *p;
            p+=2;
            while (*s != 0 && *s == match) {
                if (isMatch(s, p)) {
                    return true;
                }
                s++;
            }
        }

        // complex asterisk matching, any matches.
        if ((*p == '.') && *(p + 1) == '*') {
            p+=2;
            if (*p == 0) {
                return true;
            // Find the stop-matching sequence:
            } else {
                while (*s != 0) {
                    if (isMatch(s, p)) {
                        return true;
                    }
                    s++;
                }
            }
        }

        if (*s != 0 && *p != 0 && *s != *p) {
            // If its a dummy expresion (zero matches of preceding character)
            if (*(p + 1) == '*') {
                p+=2;
                continue;
            } else if (*p == '*') {
                return isMatch(s, p + 1);
            } else if (*p == '.') {
                s++;
                p++;
                continue;
            } else {
                return false;
            }
        }
    }

    // Zero matching patterns at end of p after s has finished.
    while (*p != 0 && *(p + 1) == '*') {
        p += 2;
    }

    if (*p != 0 || *s != 0) {
        return false;
    }

    return true;
}