#include <iostream>
#include <string>
#include <stack>
#include <vector>

class ParsingBoolenExpression_1106
{
public:
    bool parseBoolExpr(std::string expression)
    {
        return evaluate(expression) == 't';
    }

private:
    // Perform logical operations
    char operation(std::vector<char> &tf, char op)
    {
        bool res; // Initialize res based on the operation

        switch (op)
        {
        case '&': // Logical AND
            res = true;
            for (char c : tf)
            {
                if (c == 'f')
                    res = res && false; // If any 'f', result will be false
                else
                    res = res && true; // Otherwise true
            }
            break;

        case '|': // Logical OR
            res = false;
            for (char c : tf)
            {
                if (c == 'f')
                    res = res || false; // If 'f', continue with false
                else
                    res = res || true; // If 't', result will be true
            }
            break;

        case '!':               // Logical NOT
            if (tf.size() == 1) // NOT only applies to one boolean
            {
                res = (tf[0] == 'f'); // NOT 'f' is true, NOT 't' is false
            }
            else
            {
                std::cerr << "Error: NOT operation expects exactly one input.\n";
                return 'e'; // Error
            }
            break;

        default:
            std::cerr << "Error: Invalid operation.\n";
            return 'e'; // Error
        }

        return res ? 't' : 'f'; // Convert boolean result to 't' or 'f'
    }

    // Evaluate the expression
    char evaluate(const std::string &expression)
    {
        std::stack<char> ops; // Stack for operators and parentheses
        // std::stack<char> vals; // Stack for values ('t' or 'f')
        int cnt = 0;
        for (int i = 0; i < expression.length(); i++)
        {
            char current = expression[i];

            if (current == '(')
            {
                ops.push(current); // Push '(' to indicate a new sub-expression
            }
            else if (current == 't' || current == 'f')
            {
                ops.push(current); // Push boolean values onto the stack
            }
            else if (current == ')')
            {
                // Handle the sub-expression inside parentheses
                std::vector<char> temp;
                while (!ops.empty() && (ops.top() == 't' || ops.top() == 'f') && ops.top() != '(')
                {
                    temp.push_back(ops.top());
                    ops.pop();
                }

                // Pop '('

                ops.pop();

                // Pop the operator and perform the operation
                if (!ops.empty() && (ops.top() == '&' || ops.top() == '|' || ops.top() == '!'))
                {
                    char op = ops.top();
                    ops.pop();

                    // Perform the operation and push the result back to stack
                    ops.push(operation(temp, op));
                }
            }
            else if (current == '&' || current == '|' || current == '!')
            {
                // Handle operators: Push onto ops stack
                ops.push(current);
            }
        }

        // The final result will be at the top of the value stack
        return ops.top();
    }
};

int main()
{
    ParsingBoolenExpression_1106 p1;
    std::cout << p1.parseBoolExpr("&(|(f))") << std::endl;    // Expected output: 0 (false)
    std::cout << p1.parseBoolExpr("|(f,f,f,t)") << std::endl; // Expected output: 1 (true)
    std::cout << p1.parseBoolExpr("!(f)") << std::endl;       // Expected output: 1 (true)
    std::cout << p1.parseBoolExpr("!(t)") << std::endl;       // Expected output: 0 (false)
    std::cout << p1.parseBoolExpr("!(&(f,t))") << std::endl;  // Expected output: 1 (true)
    std::cout << p1.parseBoolExpr("|(f,&(t,t))") << std::endl; // Expected output: 1 (true)
    // ops = (&(|
    // val = ttf
    return 0;
}

static const int hansil = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();