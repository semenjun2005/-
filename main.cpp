#include <iostream>
#include <sstream>
#include <cmath>
#include <stack>
using namespace std;

const double Pi = acos(-1); 

double Sin(double x) { 
    return (round(sin((x * Pi) / 180) * 10000000) / 10000000);
}

double Cos(double x) { 
    return (round(cos((x * Pi) / 180) * 10000000) / 10000000);
}

struct Leksema 
{
    char type; 
    double value; 
};

bool Maths(stack <Leksema>& Stack_n, stack <Leksema>& Stack_o, Leksema& item) { 
    
    double a, b, c;
    a = Stack_n.top().value; 
    Stack_n.pop(); 
    switch (Stack_o.top().type) {  
    case '+': 
        b = Stack_n.top().value;
        Stack_n.pop();
        c = a + b;
        item.type = '0';
        item.value = c;
        Stack_n.push(item); 
        Stack_o.pop();
        break;

    case '-':
        b = Stack_n.top().value;
        Stack_n.pop();
        c = b - a;
        item.type = '0';
        item.value = c;
        Stack_n.push(item);
        Stack_o.pop();
        break;

    case '^':
        b = Stack_n.top().value;
        Stack_n.pop();
        c = pow(b, a);
        item.type = '0';
        item.value = c;
        Stack_n.push(item);
        Stack_o.pop();
        break;

    case '*':
        b = Stack_n.top().value;
        Stack_n.pop();
        c = a * b;
        item.type = '0';
        item.value = c;
        Stack_n.push(item);
        Stack_o.pop();
        break;

    case '/':
        b = Stack_n.top().value;
        if (a == 0) {
            cerr << "\nНа 0 делить нельзя!\n";
            return false;
        }
        else {
            Stack_n.pop();
            c = (b / a);
            item.type = '0';
            item.value = c;
            Stack_n.push(item);
            Stack_o.pop();
            break;
        }

    case 's':
        c = Sin(a);
        item.type = '0';
        item.value = c;
        Stack_n.push(item);
        Stack_o.pop();
        break;

    case 'c':
        c = Cos(a);
        item.type = '0';
        item.value = c;
        Stack_n.push(item);
        Stack_o.pop();
        break;

    case 't':
        if (Cos(a) == 0) {
            cerr << "\nНеверный аргумент для тангенса!\n";
            return false;
        }
        else {
            c = Sin(a) / Cos(a);
            item.type = '0';
            item.value = c;
            Stack_n.push(item);
            Stack_o.pop();
            break;

        }
    case 'e':
        c = exp(a);
        item.type = '0';
        item.value = c;
        Stack_n.push(item);
        Stack_o.pop();
        break;
    case 'l':
        if (a < 0) {
            cerr << "\nНеправильный аргумент логарифма!\n";
            return 0;
        }
        else {
            c = log(a);
        item.type = '0';
        item.value = c;
        Stack_n.push(item);
        Stack_o.pop();
        break;
        }
    case 'r':
        if (a < 0) {
            cerr << "\nНеправильный аргумент под корнем!\n";
            return 0;
        }
        else {
            c = sqrt(a);
            item.type = '0';
            item.value = c;
            Stack_n.push(item);
            Stack_o.pop();
            break;
        }
            
    default:
        cerr << "\nОшибка!\n";
        return false;
        break;
    }
    return true;
}

int getPriority(char Ch) { 
    if (Ch == 's' || Ch == 'c' || Ch == 't' || Ch == 'g' || Ch == 'e' || Ch == 'l' || Ch == 'r')return 4;
    if (Ch == '^')return 3;
    if (Ch == '+' || Ch == '-')return 1;
    if (Ch == '*' || Ch == '/')return 2;
    else return 0;
}

int main()
{
    setlocale(LC_ALL, "rus");
    while (true) {
        system("cls");
        cout << "Пример ввода выражений:\n";
        cout << "+\n-\n/\n*\n^\nsin()\ncos\ntg()\nln()\nsqrt()\n";
        cout << "Введите выражение: ";
        std::string str;
        getline(cin, str);
        stringstream sstr{ str };

        char Ch; 
        double value;
        bool flag = true; 
        stack<Leksema> Stack_n; 
        stack<Leksema> Stack_o; 
        Leksema item; 
        while (true) {
            Ch = sstr.peek(); 
            if (Ch == '\377')break;
            if (Ch == ' ') { 
                sstr.ignore();
                continue;
            }
            if (Ch == 'l' || Ch == 't') {
                char method[2];
                for (int i = 0; i < 2; i++) {
                    Ch = sstr.peek();
                    method[i] = Ch;
                    sstr.ignore();
                }
                if (method[0] == 'l' && method[1] == 'n') { 
                    item.type = 'l';
                    item.value = 0;
                    Stack_o.push(item); 
                    continue;
                }
                if (method[0] == 't' && method[1] == 'g') {
                    item.type = 't';
                    item.value = 0;
                    Stack_o.push(item);
                    continue;
                }
            }
            if (Ch == 's') {
                char method[4];
                for (int i = 0; i < 2; i++) {
                    Ch = sstr.peek();
                    method[i] = Ch;
                    sstr.ignore();
                }
                if (method[1] == 'q') {
                    for (int i = 2; i < 4; i++) {
                        Ch = sstr.peek();
                        method[i] = Ch;
                        sstr.ignore();
                    }
                    if (method[0] == 's' && method[1] == 'q' && method[2] == 'r' && method[3] == 't') {
                        item.type = 'r';
                        item.value = 0;
                        Stack_o.push(item);
                        continue;
                    }
                }
                if (method[1] == 'i') {
                    Ch = sstr.peek();
                    method[2] = Ch;
                    sstr.ignore();
                    if (method[0] == 's' && method[1] == 'i' && method[2] == 'n') {
                        item.type = 's';
                        item.value = 0;
                        Stack_o.push(item);
                        continue;
                    }
                }
            }
            if (Ch == 'c' || Ch == 'e') {
                char method[3];
                for (int i = 0; i < 3; i++) {
                    Ch = sstr.peek();
                    method[i] = Ch;
                    sstr.ignore();
                }
                if (method[0] == 'c' && method[1] == 'o' && method[2] == 's') { 
                    item.type = 'c';
                    item.value = 0;
                    Stack_o.push(item);
                    continue;
                }
                if (method[0] == 'c' && method[1] == 't' && method[2] == 'g') { 
                    item.type = 'g';
                    item.value = 0;
                    Stack_o.push(item); 
                    continue;
                }
                if (method[0] == 'e' && method[1] == 'x' && method[2] == 'p') { 
                    item.type = 'e';
                    item.value = 0;
                    Stack_o.push(item); 
                    continue;
                }
            }
            if (Ch == 'p') {
                item.type = '0';
                item.value = Pi;
                Stack_n.push(item);
                flag = 0;
                sstr.ignore();
                continue;
            }
            if (Ch >= '0' && Ch <= '9' || Ch == '-' && flag == 1) {
                sstr >> value;
                item.type = '0';
                item.value = value;
                Stack_n.push(item);
                flag = 0;
                continue;
            }
            if (Ch == '+' || Ch == '-' && flag == 0 || Ch == '*' || Ch == '/' || Ch == '^') { 
                if (Stack_o.size() == 0) { 
                    item.type = Ch;
                    item.value = 0;
                    Stack_o.push(item); 
                    sstr.ignore();
                    continue;
                }
                if (Stack_o.size() != 0 && getPriority(Ch) >
                    getPriority(Stack_o.top().type)) { 
                    item.type = Ch;
                    item.value = 0;
                    Stack_o.push(item);
                    sstr.ignore();
                    continue;
                }
                if (Stack_o.size() != 0 && getPriority(Ch) <=
                    getPriority(Stack_o.top().type)) {
                    if (Maths(Stack_n, Stack_o, item) == false) {
                        system("pause");
                        return 0;
                    }
                    continue;
                }
            }
            if (Ch == '(') {
                item.type = Ch;
                item.value = 0;
                Stack_o.push(item);
                sstr.ignore();
                continue;
            }
            if (Ch == ')') {
                while (Stack_o.top().type != '(') {
                    if (Maths(Stack_n, Stack_o, item) == false) {
                        system("pause");
                        return 0;
                    }
                    else continue;
                }
                Stack_o.pop();
                sstr.ignore();
                continue;
            }
            else {
                cout << "\nНеверно введено выражение!\n";
                system("pause");
                return 0;
            }
        }
        while (Stack_o.size() !=
            0) { 
            if (Maths(Stack_n, Stack_o, item) == false) { 
                system("pause");
                return 0;
            }
            else continue; 
        }
        cout << "Ответ: " << Stack_n.top().value << endl; 
        system("pause");
    }
    return 0;
}
