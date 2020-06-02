import re


reg = '([a-zA-Z_][a-zA-Z0-9_]*)([\n\r\s]+)([a-zA-Z_][a-zA-Z0-9_]*)::([a-zA-Z_][a-zA-Z0-9_]*)\((.*)\)([\n\r\s]+)\{'

m = re.sub(reg, r'\1\2\3::\4(\5)\n{Timer("\3::\4");', fileText)