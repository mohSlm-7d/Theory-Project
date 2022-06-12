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

        else if (*bufferPtr == 'm' && Stack.top() != 'S') {
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

    if (flag == 1 && Stack.top() == '$')
        printf("Valid");
    if (Stack.top() != '$' || flag == 0)
        printf("Invalid");
