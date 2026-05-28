Dict={
    "table" : ["a piece of furniture", "list of facts & figures"],
    "cat" : "a small animal"
}
print(Dict)
# List of subjects
subjects = [
    "python", "java", "C++", "python", "javascript",
    "java", "python", "java", "C++", "C"
]

# Use a set to get unique subjects
unique_subjects = set(subjects)

# Number of classrooms is equal to number of unique subjects
classroom_count = len(unique_subjects)

print("Number of classrooms needed:", classroom_count)
