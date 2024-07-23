# both a tool and programming language specifically designed for text processing
# (cli) tool in the sense that you can call it from the cli
# PL in the sense that you can write scripts witin action blocks
# you write awk programs within the single quotes after the awk command
# default behavior
# reads input files line by line
# executes commands enclosed in curly braces
# can specify a pattern before the braces to only execute commands that match that pattern
# automatically splits each line into files (by default, separated by white space)
# access these fields using $1, $2, $3
# $0 represents the whole line
# commands separated by ";" are run for each input line
# END (action) block is executed once after all the lines have been processed

print_new_line() {
    echo "\n"
}

# print specific columns (1 and 3)
awk '{print $1, $3}' data.txt

# don't use parens to call a fn
print_new_line

# print entire line
awk '{print $0}' data.txt

print_new_line

# sum all #s in numbers.txt
awk '{sum += $1} END {print "Sum:", sum}' numbers.txt

print_new_line

# filter rows based on condition
awk 'NR > 1 && $2 > 27' data.txt
awk '{rn += 1} END {print "Number of rows:", rn}' data.txt
# better way to do the above
awk '{count++} END {print "Number of rows:", count}' data.txt

print_new_line

awk '{gsub("NewYork", "NY"); print}' data.txt

print_new_line

awk -F ',' 'NR > 1 {print $1, "is", $2, "years old"}' csv.txt
# filter rows based on condition (with action block to show syntactical diff)
# the syntax is condition {action} when you specify an action block (in the curly braces)
awk 'NR > 1 && $2 > 27 {print}' csv.txt

print_new_line

# WOW
# variables are created on the fly when first used and automtically initialized depending on the type
awk '
BEGIN {print "Start processing"}
NR > 1 {
    sum += $2
    if ($2 > max) max = $2
}
END {
    print "Sum:", sum
    print "Max:", max
}
' data.txt

