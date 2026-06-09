#include <bits/stdc++.h>

using namespace std;

// #define int long long
#define EPS 1e-9

/*
LET X = <ARITHMETIC_STATEMENT>
Assign the result of the arithmetic statement to variable X.

IF <CONDITION> THEN GOTO L
If the boolean given is true, then go to the statement labeled L, where L is a valid label. (If the condition is not true, continue execution to the statement with the next lowest label.)

PRINT <PRINT_STATEMENT>
Produce output, without an appended newline.

PRINTLN <PRINT_STATEMENT>
Produce output, with an appended newline.
*/

/*
<ARITHMETIC_STATEMENT> is one of the following: X, X + Y, X - Y, X * Y, or X / Y. 
Here, X and Y each indicate either a variable or an integer.

<CONDITION> is one of the following: X = Y, X > Y, X < Y, X <> Y, X <= Y, or X >= Y. 
Again, X and Y each indicate either a variable or an integer. Here, <> indicates inequality.

<PRINT_STATEMENT> is either a variable name or a literal string delimited by double quotes. 
Inside the quotes, the string contains only alphanumeric characters (a-z, A-Z, 0-9) and spaces.
*/

enum class CmdType { ASSIGN, PRINT, PRINTLN, IF_GOTO };
enum class OpType { NONE, ADD, SUB, MUL, DIV };
enum class CmpType { EQ, NEQ, LT, GT, LEQ, GEQ };

struct Operand {
    bool isVar;
    int num;
    char var;
};

struct Command {
    CmdType type;

    // --- Used by ASSIGN and IF_GOTO ---
    Operand arg1;
    Operand arg2;

    // --- Used only by ASSIGN ---
    char targetVar; 
    OpType op;

    // --- Used only by IF_GOTO ---
    CmpType cmp;
    int gotoId;
    map<int, Command>::iterator gotoIt;

    // --- Used only by PRINT / PRINTLN ---
    bool isString;
    string printStr; 
    char printVar;
};

void solve()
{
    map<int, Command> cmdMap;
    vector<int> varMap(26, 0);

    int id;
    while (cin >> id) {
        string cmd;
        getline(cin >> ws, cmd);

        Command command;
        stringstream ss(cmd);
        string kw;
        ss >> kw;
        if (kw[0] == 'L') {
            command.type = CmdType::ASSIGN;
            ss >> command.targetVar;

            string garb;
            ss >> garb;

            string varOrInt1, op, varOrInt2;
            ss >> varOrInt1;
            ss >> op;
            ss >> varOrInt2;

            if ('A' <= varOrInt1[0] && varOrInt1[0] <= 'Z') {
                command.arg1.isVar = true;
                command.arg1.var = varOrInt1[0];
            }
            else {
                command.arg1.isVar = false;
                command.arg1.num = stoi(varOrInt1);
            }

            if (op.size() == 1) {
                if ('A' <= varOrInt2[0] && varOrInt2[0] <= 'Z') {
                    command.arg2.isVar = true;
                    command.arg2.var = varOrInt2[0];
                }
                else {
                    command.arg2.isVar = false;
                    command.arg2.num = stoi(varOrInt2);
                }
                if (op == "+") {
                    command.op = OpType::ADD;
                }
                else if (op == "-") {
                    command.op = OpType::SUB;
                }
                else if (op == "*") {
                    command.op = OpType::MUL;
                }
                else if (op == "/") {
                    command.op = OpType::DIV;
                }
            }
            else {
                command.op = OpType::NONE;
            }
        }
        else if (kw[0] == 'P') {
            if (kw.size() > 5) {
                command.type = CmdType::PRINTLN;
            }
            else {
                command.type = CmdType::PRINT;
            }
            ss >> ws;
            string toPrint;
            getline(ss, toPrint);
            if ('A' <= toPrint[0] && toPrint[0] <= 'Z') {
                command.printVar = toPrint[0];
                command.isString = false;
            }
            else if (toPrint[0] == '"') {
                command.printStr = toPrint.substr(1, toPrint.size() - 2);
                command.isString = true;
            }
        }
        else if (kw[0] == 'I') {
            command.type = CmdType::IF_GOTO;
            string varOrInt1;
            ss >> varOrInt1;
            if ('A' <= varOrInt1[0] && varOrInt1[0] <= 'Z') {
                command.arg1.isVar = true;
                command.arg1.var = varOrInt1[0];
            }
            else {
                command.arg1.isVar = false;
                command.arg1.num = stoi(varOrInt1);
            }

            string cmp;
            ss >> cmp;
            if (cmp == "<=") {
                command.cmp = CmpType::LEQ;
            }
            else if (cmp == ">=") {
                command.cmp = CmpType::GEQ;
            }
            else if (cmp == "<") {
                command.cmp = CmpType::LT;
            }
            else if (cmp == ">") {
                command.cmp = CmpType::GT;
            }
            else if (cmp == "=") {
                command.cmp = CmpType::EQ;
            }
            else if (cmp == "<>") {
                command.cmp = CmpType::NEQ;
            }

            string varOrInt2;
            ss >> varOrInt2;
            if ('A' <= varOrInt2[0] && varOrInt2[0] <= 'Z') {
                command.arg2.isVar = true;
                command.arg2.var = varOrInt2[0];
            }
            else {
                command.arg2.isVar = false;
                command.arg2.num = stoi(varOrInt2);
            }

            string gotoIdStr;
            ss >> gotoIdStr; ss >> gotoIdStr; ss >> gotoIdStr;
            command.gotoId = stoi(gotoIdStr);
        }

        cmdMap[id] = command;
    }

    for (auto it = cmdMap.begin(); it != cmdMap.end(); ++it) {
    if (it->second.type == CmdType::IF_GOTO) {
        it->second.gotoIt = cmdMap.find(it->second.gotoId);
    }
}

    for (auto it = cmdMap.begin(); it != cmdMap.end(); ) {
        int currId = it->first;
        const Command& currCmd = it->second;
        if (currCmd.type == CmdType::ASSIGN) {
            int val1 = (currCmd.arg1.isVar) ? varMap[currCmd.arg1.var - 'A'] : currCmd.arg1.num;
            if (currCmd.op == OpType::NONE) {
                varMap[currCmd.targetVar - 'A'] = val1;
            }
            else {
                int val2 = (currCmd.arg2.isVar) ? varMap[currCmd.arg2.var - 'A'] : currCmd.arg2.num;
                if (currCmd.op == OpType::ADD) {
                    varMap[currCmd.targetVar - 'A'] = val1 + val2;
                }
                if (currCmd.op == OpType::MUL) {
                    varMap[currCmd.targetVar - 'A'] = val1 * val2;
                }
                if (currCmd.op == OpType::DIV) {
                    varMap[currCmd.targetVar - 'A'] = val1 / val2;
                }
                if (currCmd.op == OpType::SUB) {
                    varMap[currCmd.targetVar - 'A'] = val1 - val2;
                }
            }
        }
        else if (currCmd.type == CmdType::IF_GOTO) {
            int val1 = (currCmd.arg1.isVar) ? varMap[currCmd.arg1.var - 'A'] : currCmd.arg1.num;
            int val2 = (currCmd.arg2.isVar) ? varMap[currCmd.arg2.var - 'A'] : currCmd.arg2.num;
            if (currCmd.cmp == CmpType::EQ && val1 == val2) {
                it = currCmd.gotoIt;
                continue;
            }
            if (currCmd.cmp == CmpType::GEQ && val1 >= val2) {
                it = currCmd.gotoIt;
                continue;
            }
            if (currCmd.cmp == CmpType::GT && val1 > val2) {
                it = currCmd.gotoIt;
                continue;
            }
            if (currCmd.cmp == CmpType::LEQ && val1 <= val2) {
                it = currCmd.gotoIt;
                continue;
            }
            if (currCmd.cmp == CmpType::LT && val1 < val2) {
                it = currCmd.gotoIt;
                continue;
            }
            if (currCmd.cmp == CmpType::NEQ && val1 != val2) {
                it = currCmd.gotoIt;
                continue;
            }
        }
        else if (currCmd.type == CmdType::PRINT || currCmd.type == CmdType::PRINTLN) {
            string toPrint = currCmd.isString ? currCmd.printStr : to_string(varMap[currCmd.printVar - 'A']);
            cout << toPrint;
            if (currCmd.type == CmdType::PRINTLN) {
                cout << '\n';
            }   
        }
        ++it;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
