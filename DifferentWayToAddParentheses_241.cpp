#include <iostream>
#include <vector>
#include <string>
using namespace std;
class DifferentWayToAddParenthesis_241
{
public:
    vector<int> diffWaysToCompute(string expression)
    {
        // If the expression is just a number, return the number
        vector<int> res;
        bool isNumber = true;

        // Loop through the expression
        for (int i = 0; i < expression.length(); i++)
        {
            char c = expression[i];
            // If we find an operator, split the expression into two parts
            if (c == '+' || c == '-' || c == '*')
            {
                isNumber = false;
                // Recursively compute the results for the left and right subexpressions
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));

                // Combine the results from the left and right subexpressions
                for (int l : left)
                {
                    for (int r : right)
                    {
                        /* if (c == '+')
                        {
                            res.push_back(l + r);
                        }
                        else if (c == '-')
                        {
                            res.push_back(l - r);
                        }
                        else if (c == '*')
                        {
                            res.push_back(l * r);
                        } */
                        switch (c)
                        {
                        case '+':
                            res.push_back(l + r);
                            break;
                        case '-':
                            res.push_back(l - r);
                            break;
                        case '*':
                            res.push_back(l * r);
                            break;
                        }
                    }
                }
            }
        }

        // If the expression is a number, convert and return it as a result
        if (isNumber)
        {
            res.push_back(stoi(expression));
        }

        return res;
    }
};
int main()
{
    DifferentWayToAddParenthesis_241 solver;
    string expression = "2-1-1";

    vector<int> result = solver.diffWaysToCompute(expression);

    cout << "Possible results from different groupings: " << endl;
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
static const int hansil = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

/*
Concept	        Counts	                                Example (n = 3)
Permutations	All possible arrangements of objects	        [A, B, C], [B, A, C], etc. (n! = 6 for n=3)
Combinations	Selection of subsets without regard to order	Choosing 2 from [A, B, C]: [A, B], [A, C], etc.
Catalan numbers	Specific recursive structures like valid parentheses, binary trees	Valid balanced parentheses: 5 for n=3
*/