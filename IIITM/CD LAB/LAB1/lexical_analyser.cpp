#include <bits/stdc++.h>
using namespace std;
vector<string> keywords = {"Prog", "Integer", "Begin", "read", "if", "then", "else",
                           "endif", "while", "do", "endwhile", "write", "end"};
vector<string> operators = {"<", ">", "<=", ">=", "==", "!=", ":=", "+", "-", "*", "/", "="};
vector<char> delimiters = {';', ',', '(', ')', '{', '}'};

// function for finding the type of token
bool isDelimiter(char c)
{
    return find(delimiters.begin(), delimiters.end(), c) != delimiters.end();
}

bool isOperatorStart(char c)
{
    for (string op : operators)
    {
        if (op[0] == c)
            return true;
    }
    return false;
}

bool isKeyword(const string &token)
{
    return find(keywords.begin(), keywords.end(), token) != keywords.end();
}

bool isOperator(const string &token)
{
    return find(operators.begin(), operators.end(), token) != operators.end();
}

map<string, int> counts;
set<string> Keywords, Identifiers, Operators, Integers;
set<char> Delimiters;
string token = "";

void tokenise(string &token){
        if (!token.empty()){
                if (isKeyword(token)){
                    counts["Keywords"]++;
                    Keywords.insert(token);
                }
                else if (isdigit(token[0])){
                    counts["Integers"]++;
                    Integers.insert(token);
                }
                else{
                    counts["Identifiers"]++;
                    Identifiers.insert(token);
                }
                token = "";
            }
            return;
}

int main()
{
    cout << "Enter your program (type ### in a new line to end input):" << endl;
    string line, program;
    while (getline(cin, line))
    {
        if (line == "###")
            break;
        program += line + "\n";
    }

    for (size_t i = 0; i < program.length(); ++i){
        char c = program[i];
        if (isspace(c)) {
            tokenise(token);
            continue;
        }

        else if (isDelimiter(c)){
            tokenise(token);
            counts["Delimiters"]++;
            Delimiters.insert(c);
            continue;
        }
        else if (isOperatorStart(c)){
            tokenise(token);
            string op(1, c);
            if (i + 1 < program.length()){
                op += program[i + 1];
                if (isOperator(op)){
                    counts["Operators"]++;
                    Operators.insert(op);
                    i++;
                    continue;
                }
                op = op.substr(0, 1);
            }
            if (isOperator(op)){
                counts["Operators"]++;
                Operators.insert(op);
            }
            continue;
        }

        else if(token.empty() and isdigit(c)){
            int j=i+1;
            string num(1,c);
            while(j<program.length() and isdigit(program[j])){
                num+=program[j];
                i++;
                j++;
            }
            counts["Integers"]++;
            Integers.insert(num);
            continue;
        }
        token += c;
    }
    if (!token.empty()){
        tokenise(token);
    }

    cout << "\nToken Analysis Results:\n";
    cout << "========================\n";
    cout << "Keywords: " << counts["Keywords"] << endl;
    for (auto kw : Keywords)cout << kw << " ";

    cout << "\n\nIdentifiers: " << counts["Identifiers"] << endl;
    for (auto id : Identifiers)cout << id << " ";

    cout << "\n\nIntegers: " << counts["Integers"] << endl;
    for (auto num : Integers)cout << num << " ";

    cout << "\n\nOperators: " << counts["Operators"] << endl;
    for (auto op : Operators)cout << op << " ";

    cout << "\n\nDelimiters: " << counts["Delimiters"] << endl;
    for (auto d : Delimiters)cout << d << " "; 
    cout << endl;

    cout << "2023IMT-025 BRIJESH SINGH";
    return 0;
}