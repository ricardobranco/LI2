#include "interpretador.h"

char *rl_gets (char* prompt)
{
  char *line_read = readline (prompt);

  if (line_read && *line_read)
    add_history (line_read);

  return (line_read);
}

