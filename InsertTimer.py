import re
import sys

# Read file
fileName = sys.argv[1]
file = open(fileName, "r")
fileText = file.read()
file.close()
print(fileText)

# Insert class construct with regex
reg = '([a-zA-Z_][a-zA-Z0-9_]*)([\n\r\s]+)([a-zA-Z_][a-zA-Z0-9_]*)::([a-zA-Z_][a-zA-Z0-9_]*)\((.*)\)([\n\r\s]+)\{'
newFileContent = re.sub(reg, r'\1\2\3::\4(\5)\n{Timer("\3::\4");', fileText)

print(newFileContent)

# Save new file
file = open(sys.argv[1], "w+")
file.seek(0)
file.write(newFileContent)
file.close()