#include <stdio.h>
#include <string.h>

int bigJudgeDigit(long int, long int);
int smallJudgeDigit(long int, long int);
int judgeDigit(long int);
void print(long int, long int, char, int);
long int power(long int, int); 

int main(void){
    int t, i;
    printf("How many times:");
    scanf("%d", &t);
    if(t > 1000){
        printf("Exception!\n");
        return -1;
    }
    printf("PLease enter the equation in these form:\nnum1+num2\nnum1-num2\nnum1*num2\n");
    while(t != 0){
        long int n1, n2;
        char op;
        printf("Equation:");
        scanf("%ld%c%ld", &n1, &op, &n2);
        // if(n1 > __INT_MAX__ || n2 > __INT_MAX__){
        //     printf("Invalible number!(bigger than %d)\n", __INT_MAX__);
        //     return -1;
        // }
        if('+' == op){
            print(n1, n2, '+', 1);
        }
        if('-' == op){
            print(n1, n2, '-', 2);
        }
        if('*' == op){
            long int product = n1 * n2;
            char space[500] = "";
            char space2[500] = "";
            long int bigDigitCount = bigJudgeDigit(n1, n2);
            long int smallDigitCount = smallJudgeDigit(n1, n2);
            int diffDigit = judgeDigit(product) - bigDigitCount;
            for(i = 0; i < diffDigit; i++){
                strcat(space2, " ");
            }
            for(i = 0; i < bigDigitCount - smallDigitCount; i++){
                strcat(space, " ");
            }
            if(judgeDigit(n1) > judgeDigit(n2)){
                printf(" %s%ld\n", space2, n1);
                printf("*%s%s%ld\n",space2, space, n2);
            }else if(judgeDigit(n1) < judgeDigit(n2)){
                printf(" %s%s%ld\n", space2, space, n1);
                printf("*%s%ld\n", space2, n2);
            }else{
                printf(" %s%ld\n", space2, n1);
                printf("*%s%ld\n", space2, n2);
            }
            for(i = 0; i < judgeDigit(product) + 1; i++){
                printf("-");
            }
            printf("\n");
            int n[500];    //n2 array
            long int result[500];
            n[0] = n2 % 10;
            result[0] = n[0] * n1;
            for(i = 1; i < judgeDigit(n2); i++){
                n[i] = n2 / (long int)(power(10, i)) % 10;
                result[i] = n[i] * n1;
            }
            char space3[500] = "";
            for(i = 0; i < judgeDigit(product) - judgeDigit(result[0]); i++){
                strcat(space3, " ");
            }
            char space4[500] = "";
            for(i = 0; i < judgeDigit(n2); i++){
                if(result[i] == 0 || result[i] == 1){
                    int j;
                    for(j = 0; j < judgeDigit(product) - i - 1; j++){
                        strcat(space4, " ");
                    }
                    space3[judgeDigit(product) - judgeDigit(result[0]) - i] = '\0';
                    printf(" %s%ld\n", space4, result[i]);
                }else{
                    space3[judgeDigit(product) - judgeDigit(result[0]) - i] = '\0';  
                    printf(" %s%ld\n", space3, result[i]);
                }
            }
            if(judgeDigit(n2) == 1){
                
            }else{
                for(i = 0; i < judgeDigit(product) + 1; i++){
                    printf("-");
                }
                printf("\n");
                printf(" %ld\n", product);
            }
        }
        t--;
    }
    return 0;
}

int judgeDigit(long int num){
    int count = 0;
    while(num != 0){
        num /= 10;
        ++count;
    }
    return count;
}

int bigJudgeDigit(long int n1, long int n2){
    int count1 = 0, count2 = 0;
    while(n1 != 0){
        n1 /= 10;
        ++count1;
    }
    while(n2 != 0){
        n2 /= 10;
        ++count2;
    }
    if(count1 > count2) return count1;
    else if(count2 > count1) return count2;
    else return count1;
}

int smallJudgeDigit(long int n1, long int n2){
    int count1 = 0, count2 = 0;
    while(n1 != 0){
        n1 /= 10;
        ++count1;
    }
    while(n2 != 0){
        n2 /= 10;
        ++count2;
    }
    if(count1 < count2) return count1;
    else if(count2 < count1) return count2;
    else return count1;
}

void print(long int n1, long int n2, char op, int whichOp){
    long int bigDigitCount = bigJudgeDigit(n1, n2);
    long int smallDigitCount = smallJudgeDigit(n1, n2);
    long int diffDigitCount = bigDigitCount - smallDigitCount;
    char space[200] = "";
    int i;
    for(i = 0; i < diffDigitCount; i++){
            strcat(space, " ");
    }
    if(judgeDigit(n1) > judgeDigit(n2)){
        printf(" %ld\n", n1);
        printf("%c%s%ld\n", op, space, n2);
    }else if(judgeDigit(n2) > judgeDigit(n1)){
        printf(" %s%ld\n", space, n1);
        printf("%c%ld\n", op, n2);
    }else{
        printf(" %ld\n", n1);
        printf("%c%ld\n", op, n2);
    }
    for(i = 0; i < bigDigitCount + 1; i++){
        printf("-");
    }
    printf("\n");
    if(whichOp == 1){
        int sumDigit = judgeDigit((n1 + n2));
        if(sumDigit == bigDigitCount){
            printf(" ");
        }else if(sumDigit > bigDigitCount){

        }
        printf("%ld\n\n\n", (n1 + n2));
    }
    if(whichOp == 2){
        int diffDigit = judgeDigit((n1 - n2));
        if(diffDigit == bigDigitCount && (n1 - n2) > 0){
            printf(" ");
        }else if(diffDigit < bigDigitCount){
            for(i = 0; i < bigDigitCount - diffDigit; i++){
                strcat(space, " ");
            }
        }
        printf("%s%ld\n\n", space, (n1 - n2));
    }
}

long int power(long int base, int power){
    int i;
    long int result = 1;
    for(i = 0; i < power; i++){
        result *= base;
    }
    return result;
}
