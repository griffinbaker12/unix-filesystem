# $1 is the first arg to the function
# with awk, prints the first field, the inode
get_inode() {
    ls -i "$1" | awk '{print $1}'
}

inode1=$(get_inode $1)
inode2=$(get_inode $2)

echo "Inode of $1: $inode1."
echo "Inode of $2: $inode2."

if [ "$inode1" == "$inode2" ]; then
    echo "Both files have the same inode: $inode1."
else
    echo "The files have differnt inode numbers."
fi
