#include<iostream>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include<vector>
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

bool IsVT(char vt, char* VT);
bool IsVN(char vn, char* VN);

vector<char> Stack;
char*bufferPtr;

static int ChkMssg=0;
void printProcess();
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
    strcpy_s(production[0], "S=mABcD");
    strcpy_s(production[1], "A=aA");
    strcpy_s(production[2], "A=#");
    strcpy_s(production[3], "B=b");
    strcpy_s(production[4], "D=d");

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
                          
                            if (productionRule[2] == VT[Col-1]) {
                                ParsingTable[Row][Col] = productionRule;
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
                        CheckRowAndCol(VN[i-1], calc_follow[i][N], Row, Col);
                        productionRule = VN[i];
                        productionRule += "=#";            
                       
                        ParsingTable[Row+1][Col] = productionRule;
                        
                        N++;
                    }
                    
                }

                
            }

           else if(Similar(i)){
                int  N = 1;
                while (calc_first[i][N] != '!')
                {
                    CheckRowAndCol(VN[i], calc_first[i][N], Row, Col);
                    string productionRule;
                    int noOfRule = 0;
                    while (noOfRule < 5) {
                        productionRule = production[noOfRule];
                        if (productionRule[0] != VN[i]) {
                            noOfRule++;
                            continue;
                        }
                        if (productionRule[2] == calc_first[i][N])
                            ParsingTable[Row][Col] = productionRule;

                    }
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

          else{
            ParsingTable[i][j]="!";
          }
        }
    }

    


    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 7; j++) {
          if(ParsingTable[i][j]=="!"){
            continue;
          }
          
          
          if(j==0){
            std::cout << ParsingTable[i][j] << "   \t";
            continue;
          }
              if(i==2 &&j==2){
              std::cout << ParsingTable[i][j] << "  \t\t ";

              }
               else if(i==0){
                             std::cout << ParsingTable[i][j] << "      \t";

               }
            else
            std::cout << ParsingTable[i][j] << "     \t\t ";
        }
        
      
      
        std::cout << endl;
    }

  
  std::printf("\n\nEnter you'r string here to validate it (Note Maxinmum length is "
        "1000 character):-\n\n");
    string buffer;
    std::cin >> buffer;

    int flag = 1; // correct
    
    bufferPtr = &buffer[0];
    Stack.push_back('$'); 

    Stack.push_back('S');

    string ProductionRule;
    while (*bufferPtr != '\0' && !Stack.empty()) {
        if(Stack.back()=='#'){
          Stack.pop_back();
          printProcess();
        }
        if (IsVT(*bufferPtr, VT)  && IsVT(Stack.back(), VT) && *bufferPtr == Stack.back() ) {
            Stack.pop_back();
            bufferPtr++;
            printProcess();
        }

         else if (IsVT(*bufferPtr, VT)  && IsVT(Stack.back(), VT) && *bufferPtr != Stack.back() ) {
            flag= 0;
            printProcess();
            break;
        }

         else if(IsVN(Stack.back(), VN) && IsVT(*bufferPtr, VT)){
             
             CheckRowAndCol(Stack.back(), *bufferPtr,Row, Col);
            
             if(ParsingTable[Row][Col] !="!" && ParsingTable[Row][Col] != ""){
                Stack.pop_back();
            
                ProductionRule=ParsingTable[Row][Col];
                for(int i=ProductionRule.length()-1; i>=2; i--){
                    Stack.push_back(ProductionRule[i]);
                }
               printProcess();
             }
             else{
                flag = 0;
                printProcess();
                break;
             }
          
           }
        
        else {
            flag = 0;
            printProcess();
            break;
        }
    }

    if (flag == 1 && Stack.back() == '$')
        cout<<endl<<endl<<"Accepted (Valid).";
    if (Stack.back() != '$' || flag == 0)
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
            return true;
        }
        N++;
    }

    return false;
}

bool IsVT(char vt, char* VT){
  for(int i=0; i<5; i++){
    if(vt==VT[i])
      return true;
  }
  return false;
}

bool IsVN(char vn, char* VN){
  for(int i=0; i<4;i++){
   if(vn == VN[i]){
     return true;
   } 
  }
  return false;
}

void printProcess(){
  if (!ChkMssg){
    cout<<endl<<endl<<"Printing Process: "<<endl<<endl;
    cout<<"Steps \t\t\t\t\t "<<"Stack \t\t\t\t\t "<<"Buffer"<<endl;
    ChkMssg++;
  }
  
  cout<<ChkMssg<<" \t\t\t\t\t ";
  for(auto i=Stack.cbegin(); i!=Stack.cend(); i++){
    cout<<*i;
  }
  
  cout<<" \t\t\t\t\t ";
  for(char* bufferPrint=bufferPtr; *bufferPrint!='\0'; bufferPrint++){
    cout<<*bufferPrint;
  }
  cout<<"$"<<endl;
  ChkMssg++;
}