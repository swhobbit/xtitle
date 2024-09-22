# `xtitle` - change title bar and icon text of a xterm compatible window

## SYNOPSIS

xtitle text ...

## Description
`xtitle` prints on standard out its arguments of text
strings wrapped in an escape sequence to change both the window
and icon title. The program code is deliberately simplistic to
build under vintage BSD systems.

xtitle performs one edit to the text as the program echoes it: it replaces
the first reference to the user's home directory in each argument
with the literal **~**.

### Example

For example, the following alias when set in `tcsh` as a pre-prompt
command will update window title to the specified information before
every tcsh command prompt:

```csh
   alias precmd xtitle ${user}@`hostname`:${tty} '${cwd}'
```

*Note:* As specified, the first (unquoted) argument is immediately
evaluated by the shell when the alias is set; only the quoted
current directory is resolved every time the command runs.

## AUTHOR

[(Drew Derbyshire (ahd@kew.com))](https://github.com/swhobbit), [Kendra Electronic Wonderworks](https://www.kew.com)

### Copyright

xtitle by (C) 2024 by Kendra Electronic Wonderworks is licensed under Creative Commons Attribution-ShareAlike 4.0 International

## BUGS

The program is a simplistic translation to C of a years-old shell
script which sadly is not supported on vintage BSD systems.

The terminal types supported (`vt10*`, `vt220`, `xterm*`, and `screen*`)
are hardcoded in the program.

That both the icon and title are updated is hardcoded in the program.

Shells which do not provide the ability to run a command before every prompt
require an alias for the `cd` command, or even harder contortions
if no alias facility exists in the user's preferred shell.
