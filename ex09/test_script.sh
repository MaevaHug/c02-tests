#!/bin/bash

# Colors for output
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # No Color

# Run norminette check
echo "Running norminette check..."
output=$(norminette -R CheckForbiddenSourceHeader 2>&1)
if [ $? -ne 0 ]; then
	echo "$output" | grep -E --color=always "Error|Warning|Norme"
	echo -e "${RED}Norminette check failed${NC}"
#	exit 1
else
	echo -e "${GREEN}Norminette check passed${NC}"
fi

# Compile the files
echo "Compiling files..."
cc -Wall -Wextra -Werror -o ft_strcapitalize ft_strcapitalize.c main.c
if [ $? -ne 0 ]; then
	echo -e "${RED}Compilation failed${NC}"
	exit 1
else
	echo -e "${GREEN}Compilation succeded${NC}"
fi

# Function to generate a separator line of a given length
generate_separator() {
	local length=$1
	local separator=""
	for ((i=0; i<length; i++)); do
		separator="${separator}="
	done
	echo "$separator"
}

# Assign the longest test to a variable
longest_test="$> ./ft_strcapitalize \"salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un\""
# Add some padding for better visuals and generate the separator
separator=$(generate_separator $((${#longest_test} + 2)))

# Function to run a test and check the result
run_test() {
	local input=$1
	local expected=$2

	echo "$separator"
	echo "$> ./ft_strcapitalize \"$input\""

	output=$(./ft_strcapitalize "$input")

	if [ "$output" == "$expected" ]; then
		echo -e "${GREEN}Test passed${NC}"
		#echo -e "-> Actual output:\n\"$output\""
		return 0
	else
		echo -e "${RED}Test failed${NC}"
		echo -e "-> Expected output:\n\"$expected\""
		echo -e "-> Actual output:\n\"$output\""
		return 1
	fi
}

# Run tests
all_tests_passed=true

run_test "hello world" "Hello World" || all_tests_passed=false
run_test "HELLO WORLD" "Hello World" || all_tests_passed=false
run_test "hello123 world" "Hello123 World" || all_tests_passed=false
run_test "123hello world" "123hello World" || all_tests_passed=false
run_test "hello-world" "Hello-World" || all_tests_passed=false
run_test "" "" || all_tests_passed=false
run_test "a" "A" || all_tests_passed=false
run_test "a b c" "A B C" || all_tests_passed=false
run_test "a1b2c3" "A1b2c3" || all_tests_passed=false
run_test "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un" "Salut, Comment Tu Vas ? 42mots Quarante-Deux; Cinquante+Et+Un" || all_tests_passed=false

# Final result
echo "$separator"
if $all_tests_passed; then
	echo -e "${GREEN}All tests passed: OK${NC}"
else
	echo -e "${RED}Some tests failed: KO${NC}"
fi
echo "$separator"

# Clean up compiled files
rm ft_strcapitalize