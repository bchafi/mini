Variable | Meaning
$0 | Name of the current script (or shell name).
$1, $2, ..., $N | Positional parameters (arguments given to script or function).
$# | Number of positional parameters.
$@ | All positional parameters, each as a separate word.
$* | All positional parameters, as a single word (depends on IFS).
$? | Exit status of the last command.
$$ | PID (process ID) of the current shell.
$! | PID of the most recently backgrounded command.
$_ | Last argument of the previous command (also sometimes the last command itself).
$- | Current options/flags set for the shell (like -v, -x, etc).
$IFS | Internal Field Separator (default: space, tab, newline).
$PWD | Current working directory.
$OLDPWD | Previous working directory.
$HOME | Home directory path.
$USER | Current username.
$SHELL | Path to the current user's shell.
$PATH | List of directories the shell searches for commands.
$RANDOM | Random integer between 0 and 32767.
$UID | User ID of the current user.
$EUID | Effective user ID.
$GROUPS | List of groups the current user belongs to.
$HOSTNAME | Hostname of the system.
$SECONDS | Number of seconds since shell started.
$LINENO | Current line number in the script.
$PPID | PID of the shell’s parent process.
$BASH_VERSION | Version of Bash being used.
$BASH_SOURCE | Filename of the currently running Bash script.
