#ifndef SRC_TOKEN_H_
#define SRC_TOKEN_H_

enum TYPE {
    START,
    NUMBER,
    OPERATOR,
    VARIABLE,
    END
};

enum OPERATOR {
    PLUS = '+',
    MINUS = '-',
    MULTI = '*',
    DIV = '/',
    OPAREN = '(',
    IPAREN = ')',
    SIN = 's',
    COS = 'c',
    TAN = 't',
    CTG = 'g',
    SQRT = 'q',
    LN = 'l',
    NOTHING
};

struct token {
    enum TYPE type;
    double value;
    enum OPERATOR operator;
    int priority;
};

#endif  //  SRC_TOKEN_H_
