#include<iostream>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include<stack>
using namespace std;

// Functions to calculate Follow
void followfirst(char, int, int);
void follow(char c);

// Function to calculate First
void findfirst(char, int, int);

int Count = 5;
int n = 0;

// Stores the final result
// of the First Sets
char calc_first[5][100];

// Stores the final result
// of the Follow Sets
char calc_follow[5][100];
int m = 0;

// Stores the production rules
char production[5][10];
char f[5], first[5];
int k;
char ck;
int e;

stack<char> Stack;

/*int top = -1;
void push(char c) {
    top++;
    if (top < 1000)
        stack[top] = c;
    else
        printf("Stack overFlow");
}
char pop() {
    if (top == -1)
        throw("Error");

    char temp = stack[top];
    top--;
    return temp;
}*/



void main() {
    int jm = 0;
    int km = 0;
    int i, choice;
    char c, ch;
    int count = 5;

    std::printf("Language:\n\n");
    std::printf("L(G)={m(a)^nbcd| n>=0 }\n\n");

    std::printf("Grammger:\n\n");
    std::printf("S->mABcD\n\n");
    std::printf("A->aA|#\n\n");
    std::printf("B->b\n\n");
    std::printf("D->d\n\n");

    std::printf("-----------------------------------------------\n\n");

    // The Input grammar
    strcpy_s(production[0], "S=mABcD");
    strcpy_s(production[1], "A=aA");
    strcpy_s(production[2], "A=#");
    strcpy_s(production[3], "B=b");
    strcpy_s(production[4], "D=d");

    int kay;
    char* done= new char[count];
    int ptr = -1;

    // Initializing the calc_first array
    for (k = 0; k < count; k++) {
        for (kay = 0; kay < 100; kay++) {
            calc_first[k][kay] = '!';
        }
    }
    int point1 = 0, point2, xxx;

    for (k = 0; k < count; k++) {
        c = production[k][0];
        point2 = 0;
        xxx = 0;

        // Checking if First of c has
        // already been calculated
        for (kay = 0; kay <= ptr; kay++)
            if (c == done[kay])
                xxx = 1;

        if (xxx == 1)
            continue;

        // Function call
        findfirst(c, 0, 0);
        ptr += 1;

        // Adding c to the calculated list
        done[ptr] = c;
        std::printf("\n First(%c) = { ", c);
        calc_first[point1][point2++] = c;

        // Printing the First Sets of the grammar
        for (i = 0 + jm; i < n; i++) {
            int lark = 0, chk = 0;

            for (lark = 0; lark < point2; lark++) {

                if (first[i] == calc_first[point1][lark]) {
                    chk = 1;
                    break;
                }
            }
            if (chk == 0) {

                std::printf("%c, ", first[i]);
                calc_first[point1][point2++] = first[i];
            }
        }
        std::printf("}\n");
        jm = n;
        point1++;
    }
    std::printf("\n");
    std::printf("-----------------------------------------------\n\n");
    char* donee=new char[count];
    ptr = -1;

    // Initializing the calc_follow array
    for (k = 0; k < count; k++) {
        for (kay = 0; kay < 100; kay++) {
            calc_follow[k][kay] = '!';
        }
    }
    point1 = 0;
    int land = 0;
    for (e = 0; e < count; e++) {
        ck = production[e][0];
        point2 = 0;
        xxx = 0;

        // Checking if Follow of ck
        // has already been calculated
        for (kay = 0; kay <= ptr; kay++)
            if (ck == donee[kay])
                xxx = 1;

        if (xxx == 1)
            continue;
        land += 1;

        // Function call
        follow(ck);
        ptr += 1;

        // Adding ck to the calculated list
        donee[ptr] = ck;
        std::printf(" Follow(%c) = { ", ck);
        calc_follow[point1][point2++] = ck;

        // Printing the Follow Sets of the grammar
        for (i = 0 + km; i < m; i++) {
            int lark = 0, chk = 0;
            for (lark = 0; lark < point2; lark++) {
                if (f[i] == calc_follow[point1][lark]) {
                    chk = 1;
                    break;
                }
            }
            if (chk == 0) {
                std::printf("%c, ", f[i]);
                calc_follow[point1][point2++] = f[i];
            }
        }
        std::printf(" }\n\n");
        km = m;
        point1++;
    }
    //printf("hello\n %c \n",production[4][2]);
    /*
    printf("%c\n",first[0]);
    printf("%c\n",first[1]);
    printf("%c\n",first[2]);
    printf("%c\n",first[3]);
    printf("%c\n",first[4]);
    printf("%c\n",first[5]);

    */



  

    char table[5][7];


    char VVN[10]={};
    int index=0;
    bool flag2=1;//found VN
    for(int i=0;i<count;i++){
      for(int j=0;j<10;j++){
        flag2=1;
        if(production[i][j]>='A' && production[i][j]<='Z'){
          for(int k=0;k<=index;k++)
            {if(VVN[k]==production[i][j]){
               flag2=0;
              break;}
              }

            if(flag2==1)
            {
              VVN[index]=production[i][j];
              index++;
            }
        }
      }
    }



    char VVT[10]={};
    int index1=0;
    for(int i=0;i<6;i++){
      for(int j=0;j<10;j++){
        flag2=1;
        if(production[i][j]>='a' && production[i][j]<='z'){
          for(int k=0;k<=index1;k++)
            {if(VVT[k]==production[i][j]){
               flag2=0;
              break;}
              }

            if(flag2==1)
            {
              VVT[index1]=production[i][j];
              index1++;
            }
        }
      }
    }

   // printf("%c \n",VVT[4]);
    for(int i=0,j=1;VVT[i]!='\0';i++,j++)
      table[1][j]=VVT[i];
   table[1][6]='$';

    for(int i=0,j=1;VVN[i]!='\0';i++,j++)
      table[j][0]=VVN[i];
    table[0][0]='V';
    table[0][1]='N';
    table[0][2]='|';
    table[0][3]='V';
    table[0][4]='T';




    for(int i=0;i<5;i++){
      for(int j=0;j<6;j++){
        if(i==0){
          if(j==5)
            break;
          printf("%c ",table[i][j]);
        }
        else{
          printf("%c ",table[i][j]);
        }

      }
      printf("\n");}
    




    

    std::printf("\n\nEnter you'r string here to validate it (Note Maxinmum length is "
        "1000 character):-\n\n");
    string buffer;
    std::cin >> buffer;
    
    int flag = 1; // correct
    
    char* bufferPtr = &buffer[0];
    Stack.push('$');
    Stack.push('S');
    while (*bufferPtr != '\0' && !Stack.empty()) {

        if (*bufferPtr == 'm' && Stack.top() == 'm') {
            Stack.pop();
            bufferPtr++;
        }

        else if (*bufferPtr == 'm' && Stack.top()!= 'S') {
            flag = 0;
            break;
        }
        else if (*bufferPtr == 'm' && Stack.top() == 'S') {
            Stack.pop();
            Stack.push('D');
            Stack.push('c');
            Stack.push('B');
            Stack.push('A');
            Stack.push('m');
        }

        else if (*bufferPtr == 'a' && Stack.top() == 'a') {
            Stack.pop();
            bufferPtr++;
        }
        else if (*bufferPtr == 'a' && Stack.top() != 'A') {
            flag = 0;
            break;
        }
        else if (*bufferPtr == 'a' && Stack.top() == 'A') {
            Stack.pop();
            Stack.push('A');
            Stack.push('a');
        }

        else if (*bufferPtr == 'b' && Stack.top() == 'A') {
            Stack.pop();

        }
        else if (*bufferPtr == 'b' && Stack.top() == 'b') {
            Stack.pop();
            bufferPtr++;
        }

        else if (*bufferPtr == 'b' && Stack.top() != 'B') {
            flag = 0;
            break;

        }

        else if (*bufferPtr == 'b' && Stack.top() == 'B') {
            Stack.pop();
            Stack.push('b');

        }
        else if (*bufferPtr == 'c' && Stack.top() == 'c') {
            Stack.pop();
            bufferPtr++;
        }

        else if (*bufferPtr == 'c' && Stack.top() != 'c') {
            flag = 0;
            break;
        }

        else if (*bufferPtr == 'd' && Stack.top() == 'd') {
            Stack.pop();
            bufferPtr++;
        }

        else if (*bufferPtr == 'd' && Stack.top() != 'D') {
            flag = 0;
            break;
        }

        else if (*bufferPtr == 'd' && Stack.top() == 'D') {
            Stack.pop();
            Stack.push('d');
        }
        else {
            flag = 0;
            break;
        }
    }

    if (flag == 1 && Stack.top()=='$')
        printf("Valid");
    if (Stack.top()!='$' || flag == 0)
        printf("Invalid");
}

void follow(char c) {
    int i, j;

    // Adding "$" to the follow
    // set of the start symbol
    if (production[0][0] == c) {
        f[m++] = '$';
    }
    for (i = 0; i < 10; i++) {
        for (j = 2; j < 10; j++) {
            if (production[i][j] == c) {
                if (production[i][j + 1] != '\0') {
                    // Calculate the first of the next
                    // Non-Terminal in the production
                    followfirst(production[i][j + 1], i, (j + 2));
                }

                if (production[i][j + 1] == '\0' && c != production[i][0]) {
                    // Calculate the follow of the Non-Terminal
                    // in the L.H.S. of the production
                    follow(production[i][0]);
                }
            }
        }
    }
}

void findfirst(char c, int q1, int q2) {
    int j;

    // The case where we
    // encounter a Terminal
    if (!(isupper(c))) {
        first[n++] = c;
    }
    for (j = 0; j < Count; j++) {
        if (production[j][0] == c) {
            if (production[j][2] == '#') {
                if (production[q1][q2] == '\0')
                    first[n++] = '#';
                else if (production[q1][q2] != '\0' && (q1 != 0 || q2 != 0)) {
                    // Recursion to calculate First of New
                    // Non-Terminal we encounter after epsilon
                    findfirst(production[q1][q2], q1, (q2 + 1));
                }
                else
                    first[n++] = '#';
            }
            else if (!isupper(production[j][2])) {
                first[n++] = production[j][2];
            }
            else {
                // Recursion to calculate First of
                // New Non-Terminal we encounter
                // at the beginning
                findfirst(production[j][2], j, 3);
            }
        }
    }
}

void followfirst(char c, int c1, int c2) {
    int k;

    // The case where we encounter
    // a Terminal
    if (!(isupper(c)))
        f[m++] = c;
    else {
        int i = 0, j = 1;
        for (i = 0; i < Count; i++) {
            if (calc_first[i][0] == c)
                break;
        }

        // Including the First set of the
        // Non-Terminal in the Follow of
        // the original query
        while (calc_first[i][j] != '!') {
            if (calc_first[i][j] != '#') {
                f[m++] = calc_first[i][j];
            }
            else {
                if (production[c1][c2] == '\0') {
                    // Case where we reach the
                    // end of a production
                    follow(production[c1][0]);
                }
                else {
                    // Recursion to the next symbol
                    // in case we encounter a "#"
                    followfirst(production[c1][c2], c1, c2 + 1);
                }
            }
            j++;
        }
    }
}
