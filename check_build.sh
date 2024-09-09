echo "Checking Compilation..."

output=$(./fracturing < test_inputs.txt)

if [ $? -eq 0 ] ; then
  echo "Pass: Program exited zero"
else
  echo "Fail: Program did not exit zero"
  exit 1
fi

echo "Build succeeded."
echo

exit 0