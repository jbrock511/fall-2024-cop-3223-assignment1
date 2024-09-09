echo "Checking implementation..."

# Check if the correct number of arguments is given
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <file_path> <substring>"
    exit 1
fi

# Assign arguments to variables
file_path=$1
substring=$2

# Check if the file exists
if [ ! -f "$file_path" ]; then
    echo "File not found!"
    exit 1
fi

# Read the file and check for the substring
if grep -q "$substring" "$file_path"; then
    echo "Test Case Passed"
    exit 0
else
    echo "Test case Failed"
    exit 1
fi