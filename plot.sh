echo "[`python main.py | grep loss | cut -d'-' -f3 | cut -d':' -f2 | sed ':a;N;$!ba;s/\n/,/g'`]" | octave plot_error.m
