#include <iostream>

using namespace std;

bool lastEntryIsOperation = false;
int counter = 0;
int pfcounter = 0;

class Stack
{
    string *storage;
    int size;
    int top;
public:
    Stack(int sizeInput)
    {
        size = sizeInput;
        storage = new string[size];
        top = -1;
    }

    void push(string x)
    {
        if (top == size)
        {
            cout << "stack is full!";
        } else
        {
            top++;
            storage[top] = x;
        }
    }

    string pop()
    {
        if (top == -1)
        {
            cout << "stack is empty! null will be returned\n";
            return "empty";
        } else
        {
            string returnValue = storage[top];
            top--;
            return returnValue;
        }
    }

    string getTopElement()
    {
        return storage[top];
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        return false;
    }
};

bool isUnaryFunction(string input)
{
    int c = 0;
    for (int i = 0; i < input.length(); i++)
    {
        if ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z'))
        {
            c++;
        } else
        {
            return false;
        }
    }
    if (c == input.length())
    {
        return true;
    }
    return false;
}

int getPrecedence(string input)
{
    if (isUnaryFunction(input))
    {
        return 0;
    } else if (input == "-u")
    {
        return 0;
    } else if (input == "^")
    {
        return 2;
    } else if (input == "*" || input == "/" || input == "%")
    {
        return 3;
    } else if (input == "+" || input == "-")
    {
        return 4;
    } else return 5;
}

bool isOperand(string input)
{
    int count = 0;
    for (int i = 0; i < input.length(); i++)
    {
        if ((input[i] >= '0' && input[i] <= '9') || input[i] == '.')
        {
            count++;
        }
    }
    if (count == input.length())
    {
        return true;
    } else
    {
        return false;
    }
}

bool isOperator(string input)
{
    if (input == "+" || input == "-" || input == "*" || input == "/" || input == "%" || input == "^" || input == "-u")
    {
        return true;
    } else if (isUnaryFunction(input))
    {
        return true;
    }
    return false;
}

void parser(string *input, string expression)
{

    for (int i = 0; i < expression.length(); i++)
    {
        if (counter == 0 && expression[i] == '-')
        {
            string temp;
            temp = "-u";
            lastEntryIsOperation = true;
            input[counter] = temp;
            counter++;
        } else if (expression[i] == '-' && lastEntryIsOperation)
        {
            if (expression[i] == '-')
            {
                string temp;
                temp = "-u";
                input[counter] = temp;
                counter++;
            }
            lastEntryIsOperation = true;
        } else if ((expression[i] == '(') || (expression[i] == ')') || (expression[i] == '*')
                   || (expression[i] == '+') || (expression[i] == '/') || (expression[i] == '-')
                   || (expression[i] == '%') || (expression[i] == '^'))
        {
            string temp;
            temp.push_back(expression[i]);
            input[counter] = temp;
            if (expression[i] != ')')
            {
                lastEntryIsOperation = true;
            } else
            {
                lastEntryIsOperation = false;
            }
            counter++;
        } else if (('a' <= expression[i] && 'z' >= expression[i]) ||
                   ('A' <= expression[i] && 'Z' >= expression[i]))
        {
            string temp;
            temp.push_back(expression[i]);
            int j = 1;
            while (('a' <= expression[i + j] && 'z' >= expression[i + j]) ||
                   ('A' <= expression[i + j] && 'Z' >= expression[i + j]))
            {
                temp.push_back(expression[i + j]);
                j++;
            }
            i += (j - 1);
            input[counter] = temp;
            lastEntryIsOperation = true;
            counter++;
        } else if (('0' <= expression[i] && '9' >= expression[i]) || expression[i] == '.')
        {
            string temp;
            temp.push_back(expression[i]);
            int j = 1;
            while (('0' <= expression[i + j] && '9' >= expression[i + j]) || expression[i + j] == '.')
            {
                temp.push_back(expression[i + j]);
                j++;
            }
            i += (j - 1);
            input[counter] = temp;
            lastEntryIsOperation = false;
            counter++;
        }
    }
    cout << " parser: ";
    for (int i = 0; i < counter; i++)
    {
        cout << input[i] << " ";
    }
    cout << "\n";
}

void postfixToinfix(string *postfixExpression)
{
    string result;
    Stack operands(pfcounter);
    for (int i = 0; i < pfcounter; i++)
    {
        if (isOperator(postfixExpression[i]))
        {
            if (postfixExpression[i] == "+" || postfixExpression[i] == "-" || postfixExpression[i] == "^" ||
                postfixExpression[i] == "*" || postfixExpression[i] == "/" || postfixExpression[i] == "%")
            {
                result += "(" + operands.pop() + postfixExpression[i] + operands.pop() + ")";
                operands.push(result);
                result.clear();
            } else if (isUnaryFunction(postfixExpression[i]))
            {
                if (isOperand(operands.getTopElement()))
                {
                    result += "(" + postfixExpression[i] + "(" + operands.pop() + "))";
                } else
                {
                    result += "(" + postfixExpression[i] + operands.pop() + ")";
                }

                operands.push(result);
                result.clear();
            } else if (postfixExpression[i] == "-u")
            {
                result += "(-" + operands.pop() + ")";
                operands.push(result);
                result.clear();
            }
        } else if (isOperand(postfixExpression[i]))
        {
            operands.push(postfixExpression[i]);
        } else
        {
            cout << "NOT OPERATOR, NOT OPERAND" << "\n";
        }
    }
    cout << "\ninfix: " << operands.pop() << "\n";
}

void infixToPostfix(string *tokens, string *postfixExpression)
{
    Stack operators(counter);
    for (int i = 0; i < counter; i++)
    {
        if (isOperand(tokens[i]))
        {
            postfixExpression[pfcounter] = tokens[i];
            pfcounter++;
        } else if (isOperator(tokens[i]))
        {
            if (tokens[i] == "^" || tokens[i] == "-u" || isUnaryFunction(tokens[i]))
            {
                while (!operators.isEmpty() &&
                       (getPrecedence(operators.getTopElement()) < getPrecedence(tokens[i]))
                       && (operators.getTopElement() != "("))
                {
                    postfixExpression[pfcounter] = operators.pop();
                    pfcounter++;
                }
                operators.push(tokens[i]);
            } else
            {
                while (!operators.isEmpty() &&
                       (getPrecedence(operators.getTopElement()) <= getPrecedence(tokens[i]))
                       && (operators.getTopElement() != "("))
                {
                    postfixExpression[pfcounter] = operators.pop();
                    pfcounter++;
                }
                operators.push(tokens[i]);
            }

        } else if (tokens[i] == "(")
        {
            operators.push(tokens[i]);
        } else if (tokens[i] == ")")
        {
            while (!operators.isEmpty() && operators.getTopElement() != "(")
            {
                postfixExpression[pfcounter] = operators.pop();
                pfcounter++;
            }
            operators.pop();
        }
    }
    while (!operators.isEmpty())
    {
        postfixExpression[pfcounter] = operators.pop();
        pfcounter++;
    }
    cout << " postfix: ";
    for (int i = 0; i < pfcounter; i++)
    {
        cout << postfixExpression[i];
    }
    cout << "\n";
}

int main()
{
    cout << "Welcome. Insert your expression and press Enter.\n";
    string inputString;
    cin >> inputString;
    size_t expressionsLength;
    expressionsLength = inputString.length();
    string tokens[expressionsLength];
    parser(tokens, inputString);
    string postfixExpression[counter + 1]; //+1 : in case of memory leak.
    infixToPostfix(tokens, postfixExpression);
    postfixToinfix(postfixExpression);
    return 0;
}
