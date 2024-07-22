text="hello"

file_no1="hello.txt"
file_no2="hello2.txt"

touch $file_no1 

echo $text > $file_no1

ln $file_no1 $file_no2
