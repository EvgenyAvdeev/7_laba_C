#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int counter(char* s) {
    size_t len = strlen(s);
    return len;
}
int check(char* s) {
    int flag = 0;
    char sim[] =  "!@#$%^&*()-_`~/?{}[]|:;',=+\\ёйцукенгшщзхъфывапролджэячсмитьбюЁЙЦУКЕНГШЩЗХЪФЫВАПРОЛДЖЭЯЧСМИТЬБЮ\t<>üöäß0§ÜÖÄ";
    size_t len = strlen(s);
    size_t len_sim = strlen(sim);
    for (int i = 0; i < len_sim; i++) {
        for (int j = 0; j < len; j++) {
            if (sim[i] == s[j]) {
                flag = 1;
                break;
            }
        }
        if (flag == 1) {
            break;
        }
    }
    return flag;
}



void del_point(char* s) {
    char* point_word = strstr(s, ".");
    int ind = point_word - s;
    size_t len = strlen(s);
    for (int i = ind; i < len; i++) {
        s[i] = NULL;
    }
}
void mod(char* s) {
    size_t len = strlen(s);
    for (int i = len-1; i > 0; i--) {
        char c = s[i];
        s[i] = s[i - 1];
        s[i - 1] = c;
    }
}
void main() {
    int word_count = 0, char_count;
	char* str[400];
	char* sep = " ";
    printf("Input string: ");
    gets(str);
    char* point = strstr(str, ".");
    int flag = check(str);
    if (flag == 1) {
        printf("\nThe string contains forbidden characters\n");
        exit(1);
    }
    if (point) {
        char* out_copy[400];
        strcpy(out_copy, str);
        del_point(out_copy);
         

        char* prev[10];
        char* prev_prev[10];
        int i = 0;
        char* istr;
        char* copy[400];
        strcpy(copy, str);
        istr = strtok(str, sep);
        while (istr != NULL)
        {
            prev_prev[0] = prev[0];
            prev[0] = istr;
            char* point_word = strstr(istr, ".");
            if (point_word) {
                del_point(*prev);
                size_t len = strlen(*prev);
                if (len == 0) {
                    prev[0] = prev_prev[0];
                }
                break;
            }
            char_count = counter(istr);
            if (char_count > 10) {
                printf("\nA word can have a maximum of 10 characters\n");
                exit(1);
            }
            word_count++;
            istr = strtok(NULL, sep);
        }
        if (word_count > 30 || word_count < 1) {
            printf("\nThe number of words entered does not satisfy the condition\n");
            exit(1);
        }

        istr = strtok(copy, sep);
        printf("\n---------------------------------\nWords other than the last one:\n");
        while (istr != NULL)
        {
            char* point_word = strstr(istr, ".");
            if (point_word) {
                break;
            }
            int flag = strcmp(istr, *prev);
            if (flag != 0) {
                mod(istr);
                printf("%s\n", istr);
            }
            istr = strtok(NULL, sep);
        }
        printf("\n---------------------------------\n\nOur original string: %s.\n", out_copy);
    }
    else {
        printf("Dot not found");
    }
}
