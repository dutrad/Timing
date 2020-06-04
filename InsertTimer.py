import re
import sys

# Read file
fileName = sys.argv[1]
file = open(fileName, "r")
fileText = file.read()
file.close()

# Insert class construct with regex
reg = '([a-zA-Z_][a-zA-Z0-9_]*)::(\~|)([a-zA-Z_][a-zA-Z0-9_]*)\((.*)\)(\n|)\{'
newFileContent = re.sub(reg, r'\1::\2(\3){\nTimer("\1::\2");', fileText)

# Save new file
file = open(sys.argv[1], "w+")
file.seek(0)
file.write(newFileContent)
file.close()