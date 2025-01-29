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
cc -Wall -Wextra -Werror -o ft_print_memory ft_print_memory.c main.c
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
longest_test="$> ./ft_print_memory \"$'Bonjour les aminches\t\n\tc\a est fou\ttout\tce qu on peut faire avec\t\n\tprint_memory\n\n\n\tlol.lol\n '\" 92 | cat -e"
# Add some padding for better visuals and generate the separator
separator=$(generate_separator $((${#longest_test} + 2)))

# Function to run a test and check the result
run_test() {
	local input=$1
	local size=$2
	local expected_content=$3

	echo "$separator"
	#echo "$> ./ft_print_memory \"$input\" $size"
	printf "$> ./ft_print_memory \"%q\" $size | cat -e\n" "$input"

	# Create a temporary file for the input
	input_file=$(mktemp)
	echo -e "$input" > "$input_file"

	# Run the test and capture the output
	output=$(./ft_print_memory "$(cat "$input_file")" "$size" | cat -te)

	# Clean up the temporary file
	rm "$input_file"

	# Extract addresses and content
	addresses=$(echo "$output" | awk '{print $1}')
	content=$(echo "$output" | awk '{print substr($0, 17)}')

	# Check addresses
	address_check_passed=true
	previous_address=""
	for address in $addresses; do
		# Check if the address is in hexadecimal format and has the correct length
		if ! [[ $address =~ ^[0-9a-f]{16}:$ ]]; then
			address_check_passed=false
			break
		fi

		# Check if the address increments by 16 bytes
		if [[ -n $previous_address ]]; then
			expected_address=$(printf "%016x" $((0x$previous_address + 16)))
			if [[ $address != "$expected_address:" ]]; then
				address_check_passed=false
				break
			fi
		fi

		previous_address=${address%:}
	done

	# Compare content using diff
	diff_output=$(diff <(echo "$content") <(echo "$expected_content"))
	if [ -z "$diff_output" ] && $address_check_passed; then
		echo -e "${GREEN}Test passed${NC}"
		#echo -e "-> Actual output:\n$output"
		return 0
	else
		echo -e "${RED}Test failed${NC}"
		echo -e "-> Expected output:\n$expected_content"
		echo -e "-> Actual output:\n$output"
		if ! $address_check_passed; then
			echo -e "${RED}Address format or increment check failed${NC}"
		fi
		if [ -n "$diff_output" ]; then
			echo "Differences:"
			echo "$diff_output"
		fi
		return 1
	fi
}

# Run tests
all_tests_passed=true

# Define the expected output for the given input and size
expected_content=$(printf ": 426f 6e6a 6f75 7220 6c65 7320 616d 696e Bonjour les amin$\n: 6368 6573 090a 0963 0720 6573 7420 666f ches...c. est fo$\n: 7509 746f 7574 0963 6520 7175 206f 6e20 u.tout.ce qu on $\n: 7065 7574 2066 6169 7265 2061 7665 6309 peut faire avec.$\n: 0a09 7072 696e 745f 6d65 6d6f 7279 0a0a ..print_memory..$\n: 0a09 6c6f 6c2e 6c6f 6c0a 2000           ..lol.lol. .$")

# Use printf to handle special characters and pass the input correctly
input=$(printf 'Bonjour les aminches\t\n\tc\x07 est fou\ttout\tce qu on peut faire avec\t\n\tprint_memory\n\n\n\tlol.lol\n ')

run_test "$input" 92 "$expected_content" || all_tests_passed=false

# Final result
echo "$separator"
if $all_tests_passed; then
	echo -e "${GREEN}All tests passed: OK${NC}"
else
	echo -e "${RED}Some tests failed: KO${NC}"
fi
echo "$separator"

# Clean up compiled files
rm ft_print_memory