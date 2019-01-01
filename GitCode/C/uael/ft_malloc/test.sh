#!/bin/bash

echo "Compilation de la librairie"
set -x
export HOSTTYPE=Testing
make re
ls -l libft_malloc.so
set +x

PS1="malloc test (Ctlr+D to quit)> " bash --norc
echo "Export de function"
set -x
nm libft_malloc.so | grep -E 'free|alloc'
set +x

PS1="malloc test (Ctlr+D to quit)> " bash --norc
echo "Tests de fonctionnalite 0/1"
set -x
cat test/test0.c
gcc -o build/test0 test/test0.c
/usr/bin/time -l ./build/test0
set +x

PS1="malloc test (Ctlr+D to quit)> " bash --norc
set -x
cat test/test1.c
gcc -o build/test1 test/test1.c
/usr/bin/time -l ./build/test1
set +x

get-pr () {
  ./run.sh /usr/bin/time -l $1 2>&1 \
  | grep -E '[0-9]+  page reclaims' \
  | sed -E 's/[^0-9]*([0-9]+).*/\1/'
}

PS1="malloc test (Ctlr+D to quit)> " bash --norc
echo "Tests de fonctionnalite 0/1 (libft_malloc.so)"
set -x
./run.sh /usr/bin/time -l ./build/test0
./run.sh /usr/bin/time -l ./build/test1
set +x
echo "Test pages difference (1 - 0) ..."
for i in {0..100};
  do a=$(bc <<< "`get-pr ./build/test1` - `get-pr ./build/test0`");
  echo -n "$a -> ";
  [[ "$a" > 272 ]] && echo "KO" || echo "OK";
done > diff-pr.txt
echo "Entre 255 et 272 "`cat diff-pr.txt | grep OK | wc -l`"% du temps"

PS1="malloc test (Ctlr+D to quit)> " bash --norc
echo "Les zones pre-alloues"
echo "Oui :3"

PS1="malloc test (Ctlr+D to quit)> " bash --norc
echo "Tests de free"
set -x
cat test/test2.c
gcc -o build/test2 test/test2.c
./run.sh /usr/bin/time -l ./build/test2
set +x
[[ `get-pr ./build/test2` < `get-pr ./build/test1` ]] & echo "OK" || echo "KO!"

PS1="malloc test (Ctlr+D to quit)> " bash --norc
echo "Qualite du free"
echo "Test pages difference (2 - 0) ..."
for i in {0..100};
  do a=$(bc <<< "`get-pr ./build/test2` - `get-pr ./build/test0`");
  echo -n "$a -> ";
  [[ "$a" > 3 ]] && echo "KO" || echo "OK";
done > diff-pr-2.txt
echo "Entre 1 et 3 "`cat diff-pr-2.txt | grep OK | wc -l`"% du temps"

PS1="malloc test (Ctlr+D to quit)> " bash --norc
echo "Test de realloc"
set -x
cat test/test3.c
gcc -o build/test3 test/test3.c
./run.sh ./build/test3
set +x

PS1="malloc test (Ctlr+D to quit)> " bash --norc
echo "Test de realloc ++"
set -x
cat test/test3_bis.c
gcc -o build/test3_bis test/test3_bis.c
./run.sh ./build/test3_bis
set +x

PS1="malloc test (Ctlr+D to quit)> " bash --norc
echo "Gestion des erreurs"
set -x
cat test/test4.c
gcc -o build/test4 test/test4.c
./run.sh ./build/test4
set +x

PS1="malloc test (Ctlr+D to quit)> " bash --norc
echo "Test de show_alloc_mem"
set -x
cat test/test5.c
gcc -o build/test5 test/test5.c -Iinclude -L. -lft_malloc
./build/test5
set +x

echo "We are done here, thanks to both side of this evaluation, xo xo"
