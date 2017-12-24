import json
from pprint import pprint
from optparse import OptionParser

globalBaseIterator = 'i'
globalClassAccess = "::"

def getType(data, key, classPrefix=""):
    if isinstance(data.get(key), list):
        return "std::vector<" + classPrefix + globalClassAccess + key + globalArrayClassPostfix + "> "
    elif isinstance(data.get(key), int):
        return "int "
    elif isinstance(data.get(key), bool):
        return "list "
    elif isinstance(data.get(key), float):
        return "float "
    else:
        return "std::string "

def printFileHeader():
    print('#pragma once', file=globalOutputFile)
    print('', file=globalOutputFile)
    print("//DON'T EDIT - FILE IS GENERATED", file=globalOutputFile)
    print('', file=globalOutputFile)
    print('#include <string>', file=globalOutputFile)
    print('#include <vector>', file=globalOutputFile)
    print('#include <fstream>', file=globalOutputFile)
    print('#include "' + globalJsonRelativeDependencyPath + '"', file=globalOutputFile)
    print('namespace ' + globalNamespace + ' {', file=globalOutputFile);
    print('', file=globalOutputFile)

def printFileEnd():
    print('}', file=globalOutputFile)

def printClassHeader(className, indentation=""):
    print(indentation + "class " + className + " {", file=globalOutputFile)
    print(indentation + "public:", file=globalOutputFile)

def printClassBody(data, indentation="", scope="static "):
    for key in data.keys():
        if type(data.get(key)) is dict:
            printClassHeader(key, indentation)
            printClassBody(data.get(key), indentation + globalBaseIndentation, scope)
            printClassEnd(indentation)
        elif type(data.get(key)) is list:
            printClassMemberArray(key, data.get(key), indentation, scope)
        else:
            printClassMember(getType(data, key), key, indentation, scope)

def printClassEnd(indentation=""):
    print(indentation + "};", file=globalOutputFile)

def printClassMember(classType, key, indentation="", scope=""):
    print(indentation + scope + classType + key + ";", file=globalOutputFile)

def printClassMemberArray(key, list, indentation="", scope=""):
    postfix = globalArrayClassPostfix
    printClassHeader(key + postfix, indentation)
    printClassBody(list[0], indentation + globalBaseIndentation, "")
    printClassEnd(indentation)
    print(indentation + scope + 'std::vector<' + (key + postfix) + '>' + " " + key + ";", file=globalOutputFile)

def printLoadMethodHeader(indentation=""):
    print(indentation + "static void load() {", file=globalOutputFile)

def printLoadMethodBody(data, indentation=""):
    print(indentation + 'std::ifstream fileStream("' + globalLoadFile + '");', file=globalOutputFile)
    print(indentation + 'nlohmann::json dataJson;', file=globalOutputFile)
    print(indentation + 'fileStream>>dataJson;', file=globalOutputFile)
    printLoadKey(data, globalClassName, 'dataJson', indentation, globalClassName)

def printMethodEnd(indentation=""):
    print(indentation + "}", file=globalOutputFile)

def printLoadKey(data, accessName, dataJson, indentation="", className="", iterator=globalBaseIterator, accessBy = globalClassAccess):
    for key in data.keys():
        if type(data.get(key)) is dict:
            printLoadKey(data.get(key), accessName + accessBy + key, dataJson + '["'+key+'"]', indentation, className + globalClassAccess + key, iterator, accessBy)
        elif type(data.get(key)) is list:
            newClassName = className + globalClassAccess + key + globalArrayClassPostfix;
            print(indentation + 'for(unsigned int ' + iterator + ' = 0; ' + iterator + '<' + dataJson + '["' + key + '"]' '.size(); ' + iterator + '++) {', file=globalOutputFile)
            print(indentation + globalBaseIndentation + accessName + accessBy + key + '.push_back(' + newClassName + '());', file=globalOutputFile)
            printLoadKey(data.get(key)[0], accessName + accessBy + key + '.at(' + iterator + ')', dataJson + '["'+key+'"]' +  '.at('+iterator+')', indentation + globalBaseIndentation, newClassName, iterator + globalBaseIterator, ".")
            print(indentation + "}", file=globalOutputFile)
        else:
            print(indentation + accessName + accessBy + key + " = " + dataJson + '["'+key+'"];', file=globalOutputFile)

def printMemberDefinitions(data, className="", indentation=""):
    for key in data.keys():
        if type(data.get(key)) is dict:
            printMemberDefinitions(data.get(key), className + globalClassAccess + key, indentation)
        else:
            print(indentation + getType(data, key, className) + className + globalClassAccess + key + ';', file=globalOutputFile)

parser = OptionParser()
parser.add_option("-f", "--file", dest="filename", default="client/resources/config.json",
                  help="Filename used to generate config JSON")
parser.add_option("-l", "--loadFile", dest="loadFilename", default="resources/config.json",
                  help="Filename used to load data from JSON - runtime")
parser.add_option("-c", "--className", dest="className", default="C",
                  help="Name of generated class")
parser.add_option("-o", "--outputFilename", dest="outputFilename", default="lib/C.h",
                  help="Output filename")
parser.add_option("-n", "--namespace", dest="namespace", default="gen",
                  help="Namespace for generated classes")
parser.add_option("-d", "--jsonRelativeDependencyPath", dest="jsonRelativeDependencyPath", default="json/src/json.hpp",
                  help="Relative dependency path for json library")
parser.add_option("-a", "--arrayPostfix", dest="arrayClassPostfix", default="__GENERATED",
                  help="Postfix for json array classes")
parser.add_option("-i", "--indentation", dest="indentation", default="   ",
                  help="indentation for beautiful code")
(options, args) = parser.parse_args()

globalConfigFile = options.filename
globalLoadFile = options.loadFilename
globalClassName = options.className
globalNamespace = options.namespace
globalArrayClassPostfix = options.arrayClassPostfix
globalJsonRelativeDependencyPath = options.jsonRelativeDependencyPath
globalBaseIndentation = options.indentation

print("Start!")
print("Otwieranie pliku do odczytu!")
data = json.load(open(globalConfigFile))
print("Otwieranie pliku do zapisu!")
globalOutputFile = open(options.outputFilename, 'w')
print("Parsowanie!")
printFileHeader();
printClassHeader(globalClassName);
printClassBody(data, globalBaseIndentation)
printLoadMethodHeader(globalBaseIndentation)
printLoadMethodBody(data, globalBaseIndentation + globalBaseIndentation)
printMethodEnd(globalBaseIndentation)
printClassEnd()
printMemberDefinitions(data, globalClassName);
printFileEnd();
print("Sukces!")