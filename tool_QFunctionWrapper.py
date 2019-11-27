#
# Rules to build QFunctionWrapper class and export it (and its header) as 
# a tool
#
import os

tools = Split("""
    doxygen
    qt5
    qtcore
""")
env = Environment(tools=['default'] + tools)

# The object file and header file live in this directory.
tooldir = env.Dir('.').srcnode().abspath    # this directory
includeDir = tooldir

sources = Split('''
QFunctionWrapper.cpp
''')

headers = Split('''
QFunctionWrapper.h
''')
lib = env.Library('qfunctionwrapper', sources)

dox = env.Apidocs(sources + headers)
Default(dox)

# By default, env.Apidocs() will put its generated documentation in a directory
# named the same as this one.
doxdir = os.path.basename(tooldir)
    
def QFunctionWrapper(env):
    env.AppendUnique(CPPPATH = [includeDir])
    env.AppendUnique(LIBS = [lib])
    env.AppendDoxref(doxdir)
    env.Require(tools)

Export('QFunctionWrapper')
