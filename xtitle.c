/*------------------------------------------------------------------- */
/*                            xtitle.c                                */
/*                                                                    */
/*            Change title bar of X windows compatible title bar.     */
/*                                                                    */
/*                Date: 20 Sep 2024                                   */
/*              Author: ahd@kew.com (Drew Derbyshire)                 */
/*             Address: Kendra Electronic Wonderworks                 */
/*                      Kenmore, WA                                   */
/*------------------------------------------------------------------- */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main(argc, argv) 
	int argc;
	char **argv;
{
  char *terminal_type = getenv("TERM");
  char *home = getenv("HOME");
  char *s = NULL;
  int i;

  if (argc == 1) {
    fprintf(stderr, "%s: Missing title string\n", argv[0]);
    exit(1);
  }

  if (strncmp(terminal_type, "vt10", 4) &&
      strncmp(terminal_type, "vt220", 5) &&
      strncmp(terminal_type, "xterm", 5) &&
      strncmp(terminal_type, "screen", 6)) {
        fprintf(stderr,
                "%s: Terminal type %s not supported.\n",
                argv[0],
                terminal_type);
         exit(1);
  }

  printf("%c]0;", '\033');           /* Begin the seq for title placement */

  for (i = 1; i < argc; i++) {

    if (home != NULL) {

      if (i > 1) {                  /* A space betweem each string */
        putchar(' ');
      }

      /* Only look for home if longer than "~" */
      if (strlen(home) > 1) {
        s = strstr(argv[i], home);
      }

      if (NULL == s) {
        printf("%s", argv[i]);      /* Print original string  */
      } else {

        /* Print ~ for ${HOME}. Assumes argv is writable! */
        *s = '\0';                  /* Truncate string before ${HOME} */
        printf("%s~%s",             /* print prefix, ~, suffix */
               argv[i],
               s + strlen(home));
        }
      }
    }

    /* Terminate the title escape sequence */

    /* Note the 2.11 BSD compiler doesn't support \a, so we use \007 */
    putchar('\007');             

    exit(0);
}
