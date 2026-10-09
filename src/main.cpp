#include <cstring>
#include <iostream>
#include <set>
#include <stack>

// #define SPACE ' '
// #define TAB '\t'
// #define NEWLINE '\n'
// #define CR '\r'
// #define NULLLEN 4
// #define UNDEFINEDLEN 9
// #define TRUELEN 4
// #define FALSELEN 5

// checks by ascii table only. does not really return type of token!
#define IS_DIGIT(x) (x) >= 48 && (x) <= 57
// all printable symbols
#define IS_PSYM(c) (c) >= 33 && (c) <= 126
#define IS_KEYSTART(c) (c == 'n' || c == 'u' || c == 't' || c == 'f')

struct warena {};

struct wjsonnode {};

struct wtoken {
  enum wtokentype : int { NONE, NUMBER, BOOLEAN, QUOTE, STRING, COMMA, FILL };
  wtoken() = default;
  ~wtoken() = default;
  int offset{0};
  wtokentype type{wtokentype::NONE};
};

int main(int argc, char **argv) {

  if (argc != 2) {
    std::cout << "argc is " << argc;
    return -1;
  }

  if (argv[1][0] == '\0') {
    printf("empty string");
    return -1;
  }

  // tokens
  constexpr char t_NULL[] = "null";
  constexpr char t_UNDEFINED[] = "undefined";
  constexpr char t_TRUE[] = "true";
  constexpr char t_FALSE[] = "false";
  constexpr char t_COMMA = ',';
  constexpr char t_LPAREN = '(';
  constexpr char t_RPAREN = ')';
  constexpr char t_LBRACKET = '[';
  constexpr char t_RBRACKET = '[';
  constexpr char t_LBRACE = '{';
  constexpr char t_RBRACE = '}';
  constexpr char t_QUOTE = '"';

  // @TODO: Compare vs unordered_set
  std::set<char> CHARS{
      t_COMMA,    t_LPAREN, t_RPAREN, t_LBRACKET,
      t_RBRACKET, t_LBRACE, t_RBRACE, t_QUOTE,
  };
  std::set<const char *> KEYWORDS{t_NULL, t_UNDEFINED, t_TRUE, t_FALSE};

  std::stack<char> used_tokens;

  int offset = 0;
  char c = 0;
  while ((c = argv[1][offset++])) {
    if (used_tokens.empty()) {
      switch (c) {
      case SPACE:
      case TAB:
      case NEWLINE:
      case CR:
        break;
      case t_LBRACE:
      case t_LBRACKET:
      case t_QUOTE:
        used_tokens.push(c);
        break;
      default:
        printf("character %c at position %d is not allowed", c, offset);
        return -1;
      }

      // resulting json is number or not valid
      // if (IS_DIGIT(c)) {
      // }

      // else if (IS_KEYSTART(c)) {
      //   // char buf[] = ;
      //   if (!strcmp(t_NULL, &c)) {
      //   };
      // }
    }
  }

  // printf("json: %s", );
}
