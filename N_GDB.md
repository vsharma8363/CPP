# GDB - GNU Project Debugger

Stop at a **particular line**
```
(gdb) break main.cpp:5
```

Stop at a **particular function**
```
(gdb) break main
```

**Run** the program
```
(gdb) run
```

Step through the lines
```
(gdb) step
```
^ Using the above, you can press **enter** to repeat the last commands

Back out of a function
```
(gdb) finish
```

Value of variables
```
(gdb) info locals
```