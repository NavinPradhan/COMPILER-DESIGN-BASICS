#include <iostream>
#include <sstream>
#include <vector>
#include <cctype>

struct Token
{
    std::string type;
    std::string value;
};

std::vector<Token> tokenize(const std::string &code)
{
    std::vector<Token> tokens;
    std::istringstream stream(code);
    std::string word;

    while (stream >> word)
    {
        if (std::isdigit(word[0]))
            tokens.push_back({"NUMBER", word});
        else if (word == "+" || word == "-")
            tokens.push_back({"OPERATOR", word});
        else
            tokens.push_back({"IDENTIFIER", word});
    }
    return tokens;
}

int main()
{
    std::string input = "x = 10 + 20";
    auto tokens = tokenize(input);

    for (const auto &token : tokens)
        std::cout << token.type << ": " << token.value << "\n";

    return 0;
}
bool isValidExpression(const std::vector<Token> &tokens)
{
    return tokens.size() == 5 &&
           tokens[0].type == "IDENTIFIER" &&
           tokens[1].value == "=" &&
           tokens[2].type == "NUMBER" &&
           tokens[3].type == "OPERATOR" &&
           tokens[4].type == "NUMBER";
}
void generateIntermediateCode(const std::vector<Token> &tokens)
{
    std::cout << "t1 = " << tokens[2].value << " " << tokens[3].value << " " << tokens[4].value << "\n";
    std::cout << tokens[0].value << " = t1\n";
}
int main()
{
    std::string input = "x = 10 + 20";
    auto tokens = tokenize(input);

    if (isValidExpression(tokens))
    {
        generateIntermediateCode(tokens);
    }
    else
    {
        std::cout << "Syntax Error!\n";
    }
    return 0;
}
