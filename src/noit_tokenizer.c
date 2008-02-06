/* Generated by re2c 0.12.3 on Tue Feb  5 23:39:54 2008 */
#line 1 "noit_tokenizer.re"
#include <stdlib.h>
#include <string.h>

struct token {
  char *token;
  const char *start;
  const char *end;
  const char *next;
  enum { NT_IDENT, NT_DQSTRING, NT_SPACE, NT_UNKNOWN, NT_EOF } type;
};
#define SET_TOKEN(t,a) (t)->next = (a)

static void c_unescape(char *p, char *only) {
  char *bt = p;
#define ASSIGN(a) *(bt++) = (a)
  while(p[0] != '\0') {
    if(p[0] == '\\' && p[1] != '\0' && (!only || p[1] == *only)) {
      switch(p[1]) {
        case ' ': ASSIGN(' '); p+=2; break;
        case '"': ASSIGN('"'); p+=2; break;
        case 'n': ASSIGN('\n'); p+=2; break;
        case 'r': ASSIGN('\r'); p+=2; break;
        case 't': ASSIGN('\t'); p+=2; break;
        case 'a': ASSIGN('\a'); p+=2; break;
        case 'b': ASSIGN('\b'); p+=2; break;
        case 'v': ASSIGN('\v'); p+=2; break;
        case 'f': ASSIGN('\f'); p+=2; break;
        case '0': ASSIGN('\0'); p+=2; break;
        case '\\': ASSIGN('\\'); p+=2; break;
        default: ASSIGN(*p); p++; ASSIGN(*p); p++; break;
      }
    }
    else {
      ASSIGN(*p); p++;
    }
  }
  *bt = '\0';
}

#define BAIL_UNKNOWN do { t->type = NT_UNKNOWN; return -1; } while(0)
static int token_scan(struct token *t)
{
  t->start = t->end = t->next;

 mainpattern:

#line 50 "noit_tokenizer.c"
	{
		unsigned char yych;

		yych = (unsigned char)*t->next;
		switch(yych) {
		case 0x00:	goto yy10;
		case 0x09:
		case 0x0A:
		case 0x0D:
		case ' ':	goto yy2;
		case '"':	goto yy4;
		case '\'':	goto yy6;
		default:	goto yy8;
		}
yy2:
		++t->next;
		yych = (unsigned char)*t->next;
		goto yy17;
yy3:
#line 53 "noit_tokenizer.re"
		{ t->token = NULL;
                      t->end = t->next;
                      t->type = NT_SPACE;
                      return 1; }
#line 75 "noit_tokenizer.c"
yy4:
		++t->next;
#line 57 "noit_tokenizer.re"
		{ t->type = NT_DQSTRING;
                      if(t->start != t->end) {
                        t->start++;
                        t->end = t->next - 1;
                        t->token = malloc(t->end-t->start + 1);
                        strlcpy(t->token, t->start, t->end-t->start + 1);
                        c_unescape(t->token, NULL);
                        return 1;
                      }
                      else
                        goto dqstring;
                    }
#line 91 "noit_tokenizer.c"
yy6:
		++t->next;
#line 69 "noit_tokenizer.re"
		{ t->type = NT_IDENT;
                      if(t->start != t->end) {
                        t->start++;
                        t->end = t->next - 1;
                        t->token = malloc(t->end-t->start + 1);
                        strlcpy(t->token, t->start, t->end-t->start + 1);
                        return 1;
                      }
                      else
                        goto sqstring;
                    }
#line 106 "noit_tokenizer.c"
yy8:
		++t->next;
		yych = (unsigned char)*t->next;
		goto yy13;
yy9:
#line 81 "noit_tokenizer.re"
		{ char only = ' ';
                      t->end = t->next;
                      t->type = NT_IDENT;
                      t->token = malloc(t->end-t->start + 1);
                      strlcpy(t->token, t->start, t->end-t->start + 1);
                      c_unescape(t->token, &only);
                      return 1;
                    }
#line 121 "noit_tokenizer.c"
yy10:
		++t->next;
#line 89 "noit_tokenizer.re"
		{ t->token = NULL;
                      t->type = NT_EOF;
                      return 0;
                    }
#line 129 "noit_tokenizer.c"
yy12:
		++t->next;
		yych = (unsigned char)*t->next;
yy13:
		switch(yych) {
		case 0x00:
		case 0x09:
		case 0x0A:
		case 0x0D:
		case ' ':	goto yy9;
		case '\\':	goto yy14;
		default:	goto yy12;
		}
yy14:
		++t->next;
		yych = (unsigned char)*t->next;
		switch(yych) {
		case 0x00:
		case 0x09:
		case 0x0A:
		case 0x0D:	goto yy9;
		case '\\':	goto yy14;
		default:	goto yy12;
		}
yy16:
		++t->next;
		yych = (unsigned char)*t->next;
yy17:
		switch(yych) {
		case 0x09:
		case 0x0A:
		case 0x0D:
		case ' ':	goto yy16;
		default:	goto yy3;
		}
	}
#line 94 "noit_tokenizer.re"


 sqstring:

#line 171 "noit_tokenizer.c"
	{
		unsigned char yych;
		yych = (unsigned char)*t->next;
		switch(yych) {
		case 0x00:	goto yy23;
		case '\'':	goto yy20;
		default:	goto yy21;
		}
yy20:
#line 98 "noit_tokenizer.re"
		{ t->end = t->next;
                      goto mainpattern; }
#line 184 "noit_tokenizer.c"
yy21:
		++t->next;
		yych = (unsigned char)*t->next;
		switch(yych) {
		case 0x00:
		case '\'':	goto yy20;
		default:	goto yy21;
		}
yy23:
		++t->next;
#line 100 "noit_tokenizer.re"
		{ BAIL_UNKNOWN; }
#line 197 "noit_tokenizer.c"
	}
#line 101 "noit_tokenizer.re"


 dqstring:

#line 204 "noit_tokenizer.c"
	{
		unsigned char yych;
		yych = (unsigned char)*t->next;
		switch(yych) {
		case 0x00:	goto yy33;
		case '"':	goto yy29;
		case '\\':	goto yy27;
		default:	goto yy31;
		}
yy27:
		yych = (unsigned char)*++t->next;
		switch(yych) {
		case 0x00:	goto yy28;
		case '"':
		case '0':
		case '\\':
		case 'a':
		case 'b':
		case 'f':
		case 'n':
		case 'r':
		case 't':
		case 'v':	goto yy37;
		default:	goto yy35;
		}
yy28:
yy29:
		++t->next;
#line 109 "noit_tokenizer.re"
		{ t->end = t->next--;
                      goto mainpattern;
                    }
#line 237 "noit_tokenizer.c"
yy31:
		++t->next;
#line 112 "noit_tokenizer.re"
		{ goto dqstring; }
#line 242 "noit_tokenizer.c"
yy33:
		++t->next;
#line 113 "noit_tokenizer.re"
		{ BAIL_UNKNOWN; }
#line 247 "noit_tokenizer.c"
yy35:
		++t->next;
#line 108 "noit_tokenizer.re"
		{ goto dqstring; }
#line 252 "noit_tokenizer.c"
yy37:
		++t->next;
#line 106 "noit_tokenizer.re"
		{ goto dqstring; }
#line 257 "noit_tokenizer.c"
	}
#line 114 "noit_tokenizer.re"

}

int noit_tokenize(const char *input, char **vector, int *cnt) {
  struct token t;
  int i = 0;

  SET_TOKEN(&t, input);
  while(token_scan(&t) != -1) {
    switch(t.type) {
      case NT_IDENT:
      case NT_DQSTRING:
        if(i<*cnt) vector[i] = t.token;
        i++;
        break;
      case NT_SPACE:
        break;
      case NT_EOF:
        if(i<*cnt) *cnt = i;
        return i;
      case NT_UNKNOWN:
        /* UNREACHED */
        goto failure;
    }
  }
 failure:
  if(i<*cnt) *cnt = i;
  return input - t.next;
}
