# $1 is the first arg to the function
# with awk, prints the first field, the inode
get_inode() {
    ls -i "$1" | awk '{print $1}'
}

inode1=$(get_inode hello.txt)

