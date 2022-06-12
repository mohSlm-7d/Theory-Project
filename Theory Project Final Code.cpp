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
char Follow[5], first[5];
int k;
char ck;
int e;



void CheckRowAndCol(char Vn, char Vt, int& Row, int& Col);
bool Similar(int i);
bool EpsilonExist(int i);

stack<char> Stack;



int main() {
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
    strcpy(production[0], "S=mABcD");
    strcpy(production[1], "A=aA");
    strcpy(production[2], "A=#");
    strcpy(production[3], "B=b");
    strcpy(production[4], "D=d");

    int kay;
    char* done = new char[count];
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
    char* donee = new char[count];
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
                if (Follow[i] == calc_follow[point1][lark]) {
                    chk = 1;
                    break;
                }
            }
            if (chk == 0) {
                std::printf("%c, ", Follow[i]);
                calc_follow[point1][point2++] = Follow[i];
            }
        }
        std::printf(" }\n\n");
        km = m;
        point1++;
    }
    

    char VN[4] = { 'S', 'A', 'B', 'D' };
    char VT[5] = { 'm', 'a', 'b', 'c', 'd' };
    string ParsingTable[5][7];
    int VTCount = 0;
    int VNCount = 0;

    int Row, Col;

    for (int i = 0; i < 5; i++) {
        
        for (int j = 0; j < 7; j++) {
            if (i == 0 && j == 0) {
                ParsingTable[i][j] = "VN\\VT";
                continue;
            }

            if (i == 0 && j < 6) {
                ParsingTable[i][j] = VT[VTCount];
                VTCount++;
                continue;
            }
            if (i == 0 && j == 6) {
                ParsingTable[i][j] = "$";
                continue;
            }

            if (j == 0 && i < 5) {
                ParsingTable[i][j] = VN[VNCount];
                VNCount++;
                continue;
            }

            if (!Similar(i)) {
                int N = 1;
                while (calc_first[i - 1][N] != '!')
                {
                    CheckRowAndCol(VN[i - 1], calc_first[i - 1][N], Row, Col);
                    string productionRule;
                    int noOfRule = 0;
                    while (noOfRule < 5) {
                        productionRule = production[noOfRule];
                        if (productionRule[0] == VN[i-1]) {

                            //std::cout << "productionRule:::   " << productionRule << endl << endl;

                            if (productionRule[2] == VT[Col-1]) {
                                ParsingTable[Row][Col] = productionRule;
                                //cout << endl << endl << endl << endl << "HER HERE BROOOO!";
                                break;
                            }
                            
                        }
                        noOfRule++;
                    }
                    N++;
                }
                
                
                if (EpsilonExist(i)) {
                    int N = 1;
                    string productionRule;
                    
                    while (calc_follow[i][N] != '!')
                    {
                        cout << "N=" << N;
                        
                        CheckRowAndCol(VN[i-1], calc_follow[i][N], Row, Col);
                        
                        std::cout << endl << endl << VT[Col - 1];
                        if (VT[Col - 1] == 'b')
                            cout << endl << endl << endl << endl << "i: " << i << endl;
                        productionRule = VN[i];
                        productionRule += "=#";
                        
                        
                       
                        ParsingTable[Row+1][Col] = productionRule;

                        
                        N++;
                    }
                    
                }

                
            }

           else {
                int  N = 1;
                while (calc_first[i][N] != '!')
                {
                    std::cout << endl << endl << "N= " << N;
                    CheckRowAndCol(VN[i], calc_first[i][N], Row, Col);
                    string productionRule;
                    int noOfRule = 0;
                    while (noOfRule < 5) {
                        std::cout << "NOOFRULE: " << noOfRule;
                        productionRule = production[noOfRule];
                        if (productionRule[0] != VN[i]) {
                            noOfRule++;
                            continue;
                        }
                        if (productionRule[2] == calc_first[i][N])
                            ParsingTable[Row][Col] = productionRule;

                    }
                    std::cout << "NOOFRULE: " << noOfRule;
                    N++;
                }
                N = 1;
               while (calc_follow[i][N] != '!')
                {
                    CheckRowAndCol(VN[i], calc_follow[i][N], Row, Col);
                    string productionRule = VN[i] + "=#";
                    ParsingTable[Row][Col] = productionRule;
                    N++;
                }
            }
           
        }
    }

    


    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 7; j++) {
          if(j==0){
            std::cout << ParsingTable[i][j] << "\t";
            continue;
          }
            std::cout << ParsingTable[i][j] << ", ";
        }
        std::cout << endl;
    }

    /*std::printf("\n\nEnter you'r string here to validate it (Note Maxinmum length is "
        "1000 character):-\n\n");
    char* buffer = new char[1000];
    std::cin >> buffer;

    int flag = 1; // correct

    char* bufferPtr = &buffer[0];
    Stack.push('$');
    Stack.push('S');

    string ProductionRule;
    int loc = 0;*/

  std::printf("\n\nEnter you'r string here to validate it (Note Maxinmum length is "
        "1000 character):-\n\n");
    string buffer;
    std::cin >> buffer;

    int flag = 1; // correct
    
    char* bufferPtr = &buffer[0];
    Stack.push('$');
    Stack.push('S');

    string ProductionRule;
    while (*bufferPtr != '\0' && !Stack.empty()) {
        if(Stack.top()=='#'){
          Stack.pop();
        }
        if (*bufferPtr == 'm' && Stack.top() == 'm') {
            Stack.pop();
            bufferPtr++;
        }

        else if (*bufferPtr == 'm' && Stack.top() != 'S') {
            flag = 0;
            break;
        }
        else if (*bufferPtr == 'm' && Stack.top() == 'S') {
            CheckRowAndCol(Stack.top(), *bufferPtr,Row, Col);
            Stack.pop();
            
            ProductionRule=ParsingTable[Row][Col];
            for(int i=ProductionRule.length()-1; i>=2; i--){
                Stack.push(ProductionRule[i]);
              }
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
            CheckRowAndCol(Stack.top(), *bufferPtr,Row, Col);
            Stack.pop();
            
            ProductionRule=ParsingTable[Row][Col];
            for(int i=ProductionRule.length()-1; i>=2; i--){
                Stack.push(ProductionRule[i]);
            }
        }
        else if (*bufferPtr == 'b' && Stack.top() == 'A') {
            CheckRowAndCol(Stack.top(), *bufferPtr,Row, Col);
            Stack.pop();
            
            ProductionRule=ParsingTable[Row][Col];
            for(int i=ProductionRule.length()-1; i>=2; i--){
                Stack.push(ProductionRule[i]);
            }
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
            CheckRowAndCol(Stack.top(), *bufferPtr,Row, Col);
            Stack.pop();
            
            ProductionRule=ParsingTable[Row][Col];
            for(int i=ProductionRule.length()-1; i>=2; i--){
                Stack.push(ProductionRule[i]);
              }
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
             CheckRowAndCol(Stack.top(), *bufferPtr,Row, Col);
             Stack.pop();
            
             ProductionRule=ParsingTable[Row][Col];
             for(int i=ProductionRule.length()-1; i>=2; i--){          
                Stack.push(ProductionRule[i]);      
             }
        }
        else {
            flag = 0;
            break;
        }
    }

    if (flag == 1 && Stack.top() == '$')
        cout<<endl<<endl<<"Accepted (Valid).";
    if (Stack.top() != '$' || flag == 0)
        cout<<endl<<endl<<"Invalid (syntax error).";
  
  return 0;
}

void follow(char c) {
    int i, j;

    // Adding "$" to the follow
    // set of the start symbol
    if (production[0][0] == c) {
        Follow[m++] = '$';
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
        Follow[m++] = c;
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
                Follow[m++] = calc_first[i][j];
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

void CheckRowAndCol(char Vn, char Vt, int& Row, int& Col) {

    switch (Vn) {
    case'S':
        Row = 1;
        break;
    case'A':
        Row = 2;
        break;
    case 'B':
        Row = 3;
        break;
    case'D':
        Row = 4;
        break;
    }

    switch (Vt) {
    case'm':
        Col = 1;
        break;
    case'a':
        Col = 2;
        break;
    case 'b':
        Col = 3;
        break;
    case'c':
        Col = 4;
        break;
    case'd':
        Col = 5;
        break;
    case'$':
        Col = 6;
        break;
    }

 
}

bool Similar(int i) {
    //std::cout << "HELLLLO In Similar()";
    int j = 0, M = 1;
    while (calc_first[i][j] != '!') {
        if (calc_follow[i][M] == '!') {
            j++;
            k = 0;
            continue;
        }
        if (calc_first[i][j] == calc_follow[i][M])
            return true;
        M++;
    }

    return false;
}

bool EpsilonExist(int i) {
   
    int N = 1;
    while (calc_first[i][N] != '!') {
        if (calc_first[i][N] == '#') {
            std::cout << "EpsilonExist()";
            return true;
        }
        N++;
    }

    return false;
}
