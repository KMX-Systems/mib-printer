CppApplication {
    cpp.cxxLanguageVersion: "c++23"
    cpp.includePaths: ["inc", "/usr/local/include/antlr4-runtime"]
    cpp.staticLibraries: [
        "mib-parser",
        "antlr4-runtime"
    ]
    consoleApplication: true
    install: true
    files: "main.cpp"
}
