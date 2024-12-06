/* https://leetcode.com/problems/wildcard-matching/description/ */

#include <stdbool.h>
#include <stddef.h>

typedef enum {
    ALWAYS_FALSE = -1,
    TRUE = 0,
    FALSE = 1
} res;

// If the number of chars between '*' surpasses the number of chars left in the string s,
// it is nonsense to keep looking.
// Since we have trimmed all possible duplicates of asterisks, counting how many non-asterisk
// chars does the string p have is all we need.
bool match_is_impossible(char *s, char *p) {

    size_t p_char_len = 0;
    while (*p != 0) {
        if (*p != '*') {
            p_char_len++;
        }
        p++;
    }
    return p_char_len > strlen(s);
}


int internal_isMatch(char * s, char * p){

    if (match_is_impossible(s, p)) {
        return ALWAYS_FALSE;
    }

    while (*s != 0 && *p != 0) {

        if (*p == '?' || *s == *p) {
            s++;
            p++;
            continue;
        }

        if (*s != *p) {
            if (*p == '*') {
                while (*p == '*')
                    p++;
                if (*p == 0) {
                    return TRUE;
                }
                while (*s != 0) {
                    int res = internal_isMatch(s, p);
                    if (res == TRUE) {
                        return TRUE;
                    } else if (res == ALWAYS_FALSE) {
                        return ALWAYS_FALSE;
                    }
                    s++;
                }
            } else {
                return FALSE;
            }
        }
    }

    while (*p == '*') {
        p++;
    }

    if (*p != 0 || *s != 0) {
        return FALSE;
    }
    return TRUE;
}

bool isMatch(char *s, char *p) {

    int result = FALSE;

    result = internal_isMatch(s, p);
    if (result == TRUE) {
        return true;
    } else {
        return false;
    }
}