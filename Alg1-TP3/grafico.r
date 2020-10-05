Script started on 2019-05-21 22:20:01-03:00 [TERM="xterm-256color" TTY="/dev/pts/1" COLUMNS="158" LINES="16"]

^[[A
]0;joaocouto@JoaoCouto-SpectreLinux: ~/git/Lala[01;32mjoaocouto@JoaoCouto-SpectreLinux[00m:[01;34m~/git/Lala[00m$ 
]0;joaocouto@JoaoCouto-SpectreLinux: ~/git/Lala[01;32mjoaocouto@JoaoCouto-SpectreLinux[00m:[01;34m~/git/Lala[00m$ ./tp2 tests/teste5.txt
Segmentation fault (core dumped)
]0;joaocouto@JoaoCouto-SpectreLinux: ~/git/Lala[01;32mjoaocouto@JoaoCouto-SpectreLinux[00m:[01;34m~/git/Lala[00m$ ./tp2 tests/teste5.txtmake[K./tp2 tests/teste5.txtmake[K./tp2 tests/teste5.txtcidades4.txt5.txtmake[K./tp2 tests/cidades5.txt4.txt[2Pteste5.txtmake[K./tp2 tests/teste5.txtmake[K./tp2 tests/teste5.txt[Kchmod +x analise.sh
]0;joaocouto@JoaoCouto-SpectreLinux: ~/git/Lala[01;32mjoaocouto@JoaoCouto-SpectreLinux[00m:[01;34m~/git/Lala[00m$ ./analise.sh
make: option requires an argument -- 'C'
Usage: make [options] [target] ...
Options:
  -b, -m                      Ignored for compatibility.
  -B, --always-make           Unconditionally make all targets.
  -C DIRECTORY, --directory=DIRECTORY
                              Change to DIRECTORY before doing anything.
  -d                          Print lots of debugging information.
  --debug[=FLAGS]             Print various types of debugging information.
  -e, --environment-overrides
                              Environment variables override makefiles.
  --eval=STRING               Evaluate STRING as a makefile statement.
  -f FILE, --file=FILE, --makefile=FILE
                              Read FILE as a makefile.
  -h, --help                  Print this message and exit.
  -i, --ignore-errors         Ignore errors from recipes.
  -I DIRECTORY, --include-dir=DIRECTORY
                              Search DIRECTORY for included makefiles.
  -j [N], --jobs[=N]          Allow N jobs at once; infinite jobs with no arg.
  -k, --keep-going            Keep going when some targets can't be made.
  -l [N], --load-average[=N], --max-load[=N]
                              Don't start multiple jobs unless load is below N.
  -L, --check-symlink-times   Use the latest mtime between symlinks and target.
  -n, --just-print, --dry-run, --recon
                              Don't actually run any recipe; just print them.
  -o FILE, --old-file=FILE, --assume-old=FILE
                              Consider FILE to be very old and don't remake it.
  -O[TYPE], --output-sync[=TYPE]
                              Synchronize output of parallel jobs by TYPE.
  -p, --print-data-base       Print make's internal database.
  -q, --question              Run no recipe; exit status says if up to date.
  -r, --no-builtin-rules      Disable the built-in implicit rules.
  -R, --no-builtin-variables  Disable the built-in variable settings.
  -s, --silent, --quiet       Don't echo recipes.
  -S, --no-keep-going, --stop
                              Turns off -k.
  -t, --touch                 Touch targets instead of remaking them.
  --trace                     Print tracing information.
  -v, --version               Print the version number of make and exit.
  -w, --print-directory       Print the current directory.
  --no-print-directory        Turn off -w, even if it was turned on implicitly.
  -W FILE, --what-if=FILE, --new-file=FILE, --assume-new=FILE
                              Consider FILE to be infinitely new.
  --warn-undefined-variables  Warn when an undefined variable is referenced.

This program built for x86_64-pc-linux-gnu
Report bugs to <bug-make@gnu.org>
]0;joaocouto@JoaoCouto-SpectreLinux: ~/git/Lala[01;32mjoaocouto@JoaoCouto-SpectreLinux[00m:[01;34m~/git/Lala[00m$ ./analise.shchmod +x analise.sh
]0;joaocouto@JoaoCouto-SpectreLinux: ~/git/Lala[01;32mjoaocouto@JoaoCouto-SpectreLinux[00m:[01;34m~/git/Lala[00m$ chmod +x analise.sh[7P./analise.sh
make: Entering directory '/home/joaocouto/git/Lala'
gcc  -Wall -std=c99   -c main.c -o main.o
[01m[Kmain.c:[m[K In function ‘[01m[Kmain[m[K’:
[01m[Kmain.c:39:7:[m[K [01;35m[Kwarning: [m[Kvariable ‘[01m[Kresult[m[K’ set but not used [[01;35m[K-Wunused-but-set-variable[m[K]
   int [01;35m[Kresult[m[K;
       [01;35m[K^~~~~~[m[K
gcc  -Wall -std=c99   -c mediana.c -o mediana.o
gcc  -Wall -std=c99   -c distance.c -o distance.o
gcc  -Wall -std=c99   -c quicksort.c -o quicksort.o
gcc  -Wall -std=c99   -c unionFind.c -o unionFind.o
gcc  -Wall -std=c99   -c leitura.c -o leitura.o
gcc  -Wall -std=c99   -c camerini.c -o camerini.o
gcc  -Wall -std=c99   main.o mediana.o distance.o quicksort.o unionFind.o leitura.o camerini.o -o tp2 -lm
rm *.o
make: Leaving directory '/home/joaocouto/git/Lala'
]0;joaocouto@JoaoCouto-SpectreLinux: ~/git/Lala[01;32mjoaocouto@JoaoCouto-SpectreLinux[00m:[01;34m~/git/Lala[00m$ ./analise.shchmod +x analise.sh
]0;joaocouto@JoaoCouto-SpectreLinux: ~/git/Lala[01;32mjoaocouto@JoaoCouto-SpectreLinux[00m:[01;34m~/git/Lala[00m$ chmod +x analise.sh[7P./analise.sh
make: Entering directory '/home/joaocouto/git/Lala'
gcc  -Wall -std=c99   -c main.c -o main.o
[01m[Kmain.c:[m[K In function ‘[01m[Kmain[m[K’:
[01m[Kmain.c:39:7:[m[K [01;35m[Kwarning: [m[Kvariable ‘[01m[Kresult[m[K’ set but not used [[01;35m[K-Wunused-but-set-variable[m[K]
   int [01;35m[Kresult[m[K;
       [01;35m[K^~~~~~[m[K
gcc  -Wall -std=c99   -c mediana.c -o mediana.o
gcc  -Wall -std=c99   -c distance.c -o distance.o
gcc  -Wall -std=c99   -c quicksort.c -o quicksort.o
gcc  -Wall -std=c99   -c unionFind.c -o unionFind.o
gcc  -Wall -std=c99   -c leitura.c -o leitura.o
gcc  -Wall -std=c99   -c camerini.c -o camerini.o
gcc  -Wall -std=c99   main.o mediana.o distance.o quicksort.o unionFind.o leitura.o camerini.o -o tp2 -lm
rm *.o
make: Leaving directory '/home/joaocouto/git/Lala'
./analise.sh: line 6: Rscript: command not found
]0;joaocouto@JoaoCouto-SpectreLinux: ~/git/Lala[01;32mjoaocouto@JoaoCouto-SpectreLinux[00m:[01;34m~/git/Lala[00m$ ./analise.shchmod +x analise.sh
]0;joaocouto@JoaoCouto-SpectreLinux: ~/git/Lala[01;32mjoaocouto@JoaoCouto-SpectreLinux[00m:[01;34m~/git/Lala[00m$ chmod +x analise.sh[7P./analise.sh
make: Entering directory '/home/joaocouto/git/Lala'
gcc  -Wall -std=c99   -c main.c -o main.o
[01m[Kmain.c:[m[K In function ‘[01m[Kmain[m[K’:
[01m[Kmain.c:39:7:[m[K [01;35m[Kwarning: [m[Kvariable ‘[01m[Kresult[m[K’ set but not used [[01;35m[K-Wunused-but-set-variable[m[K]
   int [01;35m[Kresult[m[K;
       [01;35m[K^~~~~~[m[K
gcc  -Wall -std=c99   -c mediana.c -o mediana.o
gcc  -Wall -std=c99   -c distance.c -o distance.o
gcc  -Wall -std=c99   -c quicksort.c -o quicksort.o
gcc  -Wall -std=c99   -c unionFind.c -o unionFind.o
gcc  -Wall -std=c99   -c leitura.c -o leitura.o
gcc  -Wall -std=c99   -c camerini.c -o camerini.o
gcc  -Wall -std=c99   main.o mediana.o distance.o quicksort.o unionFind.o leitura.o camerini.o -o tp2 -lm
rm *.o
make: Leaving directory '/home/joaocouto/git/Lala'
./analise.sh: line 6: Rscript: command not found
]0;joaocouto@JoaoCouto-SpectreLinux: ~/git/Lala[01;32mjoaocouto@JoaoCouto-SpectreLinux[00m:[01;34m~/git/Lala[00m$ ./analise.shchmod +x analise.sh
]0;joaocouto@JoaoCouto-SpectreLinux: ~/git/Lala[01;32mjoaocouto@JoaoCouto-SpectreLinux[00m:[01;34m~/git/Lala[00m$ chmod +x analise.sh[7P./analise.sh
make: Entering directory '/home/joaocouto/git/Lala'
gcc  -Wall -std=c99   -c main.c -o main.o
[01m[Kmain.c:[m[K In function ‘[01m[Kmain[m[K’:
[01m[Kmain.c:39:7:[m[K [01;35m[Kwarning: [m[Kvariable ‘[01m[Kresult[m[K’ set but not used [[01;35m[K-Wunused-but-set-variable[m[K]
   int [01;35m[Kresult[m[K;
       [01;35m[K^~~~~~[m[K
gcc  -Wall -std=c99   -c mediana.c -o mediana.o
gcc  -Wall -std=c99   -c distance.c -o distance.o
gcc  -Wall -std=c99   -c quicksort.c -o quicksort.o
gcc  -Wall -std=c99   -c unionFind.c -o unionFind.o
gcc  -Wall -std=c99   -c leitura.c -o leitura.o
gcc  -Wall -std=c99   -c camerini.c -o camerini.o
gcc  -Wall -std=c99   main.o mediana.o distance.o quicksort.o unionFind.o leitura.o camerini.o -o tp2 -lm
rm *.o
make: Leaving directory '/home/joaocouto/git/Lala'
./analise.sh: line 6: Rscript: command not found
]0;joaocouto@JoaoCouto-SpectreLinux: ~/git/Lala[01;32mjoaocouto@JoaoCouto-SpectreLinux[00m:[01;34m~/git/Lala[00m$ ./analise.shchmod +x analise.sh
]0;joaocouto@JoaoCouto-SpectreLinux: ~/git/Lala[01;32mjoaocouto@JoaoCouto-SpectreLinux[00m:[01;34m~/git/Lala[00m$ chmod +x analise.sh[7P./analise.sh
make: Entering directory '/home/joaocouto/git/Lala'
gcc  -Wall -std=c99   -c main.c -o main.o
[01m[Kmain.c:[m[K In function ‘[01m[Kmain[m[K’:
[01m[Kmain.c:39:7:[m[K [01;35m[Kwarning: [m[Kvariable ‘[01m[Kresult[m[K’ set but not used [[01;35m[K-Wunused-but-set-variable[m[K]
   int [01;35m[Kresult[m[K;
       [01;35m[K^~~~~~[m[K
gcc  -Wall -std=c99   -c mediana.c -o mediana.o
gcc  -Wall -std=c99   -c distance.c -o distance.o
gcc  -Wall -std=c99   -c quicksort.c -o quicksort.o
gcc  -Wall -std=c99   -c unionFind.c -o unionFind.o
gcc  -Wall -std=c99   -c leitura.c -o leitura.o
gcc  -Wall -std=c99   -c camerini.c -o camerini.o
gcc  -Wall -std=c99   main.o mediana.o distance.o quicksort.o unionFind.o leitura.o camerini.o -o tp2 -lm
rm *.o
make: Leaving directory '/home/joaocouto/git/Lala'
./analise.sh: line 6: Rscript: command not found
]0;joaocouto@JoaoCouto-SpectreLinux: ~/git/Lala[01;32mjoaocouto@JoaoCouto-SpectreLinux[00m:[01;34m~/git/Lala[00m$ ./analise.shchmod +x analise.sh
]0;joaocouto@JoaoCouto-SpectreLinux: ~/git/Lala[01;32mjoaocouto@JoaoCouto-SpectreLinux[00m:[01;34m~/git/Lala[00m$ chmod +x analise.sh[7P./analise.sh
make: Entering directory '/home/joaocouto/git/Lala'
gcc  -Wall -std=c99   -c main.c -o main.o
[01m[Kmain.c:[m[K In function ‘[01m[Kmain[m[K’:
[01m[Kmain.c:39:7:[m[K [01;35m[Kwarning: [m[Kvariable ‘[01m[Kresult[m[K’ set but not used [[01;35m[K-Wunused-but-set-variable[m[K]
   int [01;35m[Kresult[m[K;
       [01;35m[K^~~~~~[m[K
gcc  -Wall -std=c99   -c mediana.c -o mediana.o
gcc  -Wall -std=c99   -c distance.c -o distance.o
gcc  -Wall -std=c99   -c quicksort.c -o quicksort.o
gcc  -Wall -std=c99   -c unionFind.c -o unionFind.o
gcc  -Wall -std=c99   -c leitura.c -o leitura.o
gcc  -Wall -std=c99   -c camerini.c -o camerini.o
gcc  -Wall -std=c99   main.o mediana.o distance.o quicksort.o unionFind.o leitura.o camerini.o -o tp2 -lm
rm *.o
make: Leaving directory '/home/joaocouto/git/Lala'
./analise.sh: line 6: Rscript: command not found
]0;joaocouto@JoaoCouto-SpectreLinux: ~/git/Lala[01;32mjoaocouto@JoaoCouto-SpectreLinux[00m:[01;34m~/git/Lala[00m$ ./analise.shchmod +x analise.sh
]0;joaocouto@JoaoCouto-SpectreLinux: ~/git/Lala[01;32mjoaocouto@JoaoCouto-SpectreLinux[00m:[01;34m~/git/Lala[00m$ chmod +x analise.sh[7P./analise.sh
make: Entering directory '/home/joaocouto/git/Lala'
gcc  -Wall -std=c99   -c main.c -o main.o
[01m[Kmain.c:[m[K In function ‘[01m[Kmain[m[K’:
[01m[Kmain.c:39:7:[m[K [01;35m[Kwarning: [m[Kvariable ‘[01m[Kresult[m[K’ set but not used [[01;35m[K-Wunused-but-set-variable[m[K]
   int [01;35m[Kresult[m[K;
       [01;35m[K^~~~~~[m[K
gcc  -Wall -std=c99   -c mediana.c -o mediana.o
gcc  -Wall -std=c99   -c distance.c -o distance.o
gcc  -Wall -std=c99   -c quicksort.c -o quicksort.o
gcc  -Wall -std=c99   -c unionFind.c -o unionFind.o
gcc  -Wall -std=c99   -c leitura.c -o leitura.o
gcc  -Wall -std=c99   -c camerini.c -o camerini.o
gcc  -Wall -std=c99   main.o mediana.o distance.o quicksort.o un