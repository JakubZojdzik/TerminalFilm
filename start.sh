python3 main.py &>/dev/null &
first = ps ax | grep -o "./a.out" | wc -l
./a.out
while :
do
    ./a.out
    # if [ps ax | grep -o "./a.out" | wc -l = first]
    # then
    #     ./a.out
    # fi
    # echo "dzialam"
done


#ps ax | grep -o "./a.out" | wc -l
#gnome-terminal -x -c "./a.out; bash"