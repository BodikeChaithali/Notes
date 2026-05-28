# Find lines starting with "error"
grep '^error' logfile.txt

# Find phone numbers (10 digits)
grep -E '[0-9]{10}' contacts.txt

# Extract email addresses
grep -E '[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]+' file.txt

# Match blank lines
grep '^$' file.txt

